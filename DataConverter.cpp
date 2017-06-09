#include "DataConverter.h"

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <google/protobuf/text_format.h>

#include <lmdb.h>

#if defined(_MSC_VER)
#include <direct.h>
#define mkdir(X, Y) _mkdir(X)
#endif

#include <stdint.h>
#include <sys/stat.h>



#include <algorithm>
#include <utility>
#include <vector>

#include "boost/scoped_ptr.hpp"
#include "caffe/proto/caffe.pb.h"
#include "caffe/util/db.hpp"
#include "caffe/util/format.hpp"
#include "caffe/util/io.hpp"
#include "caffe/util/rng.hpp"

using namespace caffe;  // NOLINT(build/namespaces)
using boost::scoped_ptr;
using std::string;

const int kCIFARSize = 32;
const int kCIFARImageNBytes = 3072;
const int kCIFARBatchSize = 10000;
const int kCIFARTrainBatches = 5;

DataConverter::DataConverter()
	:CurrentMode(DEFAULT)
	, _label_filename(string(""))
	, _db_path(string(""))
	, _db_backend(string(""))
	,_image_filename(string(""))
	, _input_folder(string(""))
	, _output_folder(string(""))
	, _db_type(string(""))
	, _ImgFileList(string(""))
	, _RootDir(string(""))
	, _DbName(string(""))
	, _gray(true)
	, _shuffle(true)
	, _backend(string(""))
	, _resize_width(0)
	, _resize_height(0)
	, _check_size(true)
	, _encoded(true)
	, _encode_type(string(""))
{
	
}


DataConverter::~DataConverter()
{
}

uint32_t DataConverter::swap_endian(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return (val << 16) | (val >> 16);
}

void DataConverter::convert_mnist_dataset(string& image_filename, string& label_filename, string& db_path, string& db_backend)
{
	// Open files
	std::ifstream image_file(image_filename, std::ios::in | std::ios::binary);
	std::ifstream label_file(label_filename, std::ios::in | std::ios::binary);
	CHECK(image_file) << "Unable to open file " << image_filename;
	CHECK(label_file) << "Unable to open file " << label_filename;
	// Read the magic and the meta data
	uint32_t magic;
	uint32_t num_items;
	uint32_t num_labels;
	uint32_t rows;
	uint32_t cols;

	image_file.read(reinterpret_cast<char*>(&magic), 4);
	magic = swap_endian(magic);
	CHECK_EQ(magic, 2051) << "Incorrect image file magic.";
	label_file.read(reinterpret_cast<char*>(&magic), 4);
	magic = swap_endian(magic);
	CHECK_EQ(magic, 2049) << "Incorrect label file magic.";
	image_file.read(reinterpret_cast<char*>(&num_items), 4);
	num_items = swap_endian(num_items);
	label_file.read(reinterpret_cast<char*>(&num_labels), 4);
	num_labels = swap_endian(num_labels);
	CHECK_EQ(num_items, num_labels);
	image_file.read(reinterpret_cast<char*>(&rows), 4);
	rows = swap_endian(rows);
	image_file.read(reinterpret_cast<char*>(&cols), 4);
	cols = swap_endian(cols);


	scoped_ptr<db::DB> db(db::GetDB(db_backend));
	db->Open(db_path, db::NEW);
	scoped_ptr<db::Transaction> txn(db->NewTransaction());

	// Storing to db
	char label;
	char* pixels = new char[rows * cols];
	int count = 0;
	string value;

	Datum datum;
	datum.set_channels(1);
	datum.set_height(rows);
	datum.set_width(cols);
	LOG(INFO) << "A total of " << num_items << " items.";
	LOG(INFO) << "Rows: " << rows << " Cols: " << cols;
	for (int item_id = 0; item_id < num_items; ++item_id) {
		image_file.read(pixels, rows * cols);
		label_file.read(&label, 1);
		datum.set_data(pixels, rows*cols);
		datum.set_label(label);
		string key_str = caffe::format_int(item_id, 8);
		datum.SerializeToString(&value);

		txn->Put(key_str, value);

		if (++count % 1000 == 0) {
			txn->Commit();
		}
	}
	// write the last batch
	if (count % 1000 != 0) {
		txn->Commit();
	}
	LOG(INFO) << "Processed " << count << " files.";
	delete[] pixels;
	db->Close();
}

void DataConverter::read_image(std::ifstream * file, int * label, char * buffer)
{
	char label_char;
	file->read(&label_char, 1);
	*label = label_char;
	file->read(buffer, kCIFARImageNBytes);
	return;
}

void DataConverter::convert_cifar_dataset(string & input_folder, string & output_folder, string & db_type)
{
	scoped_ptr<db::DB> train_db(db::GetDB(db_type));
	train_db->Open(output_folder + "/cifar10_train_" + db_type, db::NEW);
	scoped_ptr<db::Transaction> txn(train_db->NewTransaction());
	// Data buffer
	int label;
	char str_buffer[kCIFARImageNBytes];
	Datum datum;
	datum.set_channels(3);
	datum.set_height(kCIFARSize);
	datum.set_width(kCIFARSize);

	LOG(INFO) << "Writing Training data";
	for (int fileid = 0; fileid < kCIFARTrainBatches; ++fileid) {
		// Open files
		LOG(INFO) << "Training Batch " << fileid + 1;
		string batchFileName = input_folder + "/data_batch_"
			+ caffe::format_int(fileid + 1) + ".bin";
		std::ifstream data_file(batchFileName.c_str(),
			std::ios::in | std::ios::binary);
		CHECK(data_file) << "Unable to open train file #" << fileid + 1;
		for (int itemid = 0; itemid < kCIFARBatchSize; ++itemid) {
			read_image(&data_file, &label, str_buffer);
			datum.set_label(label);
			datum.set_data(str_buffer, kCIFARImageNBytes);
			string out;
			CHECK(datum.SerializeToString(&out));
			txn->Put(caffe::format_int(fileid * kCIFARBatchSize + itemid, 5), out);
		}
	}
	txn->Commit();
	train_db->Close();

	LOG(INFO) << "Writing Testing data";
	scoped_ptr<db::DB> test_db(db::GetDB(db_type));
	test_db->Open(output_folder + "/cifar10_test_" + db_type, db::NEW);
	txn.reset(test_db->NewTransaction());
	// Open files
	std::ifstream data_file((input_folder + "/test_batch.bin").c_str(),
		std::ios::in | std::ios::binary);
	CHECK(data_file) << "Unable to open test file.";
	for (int itemid = 0; itemid < kCIFARBatchSize; ++itemid) {
		read_image(&data_file, &label, str_buffer);
		datum.set_label(label);
		datum.set_data(str_buffer, kCIFARImageNBytes);
		string out;
		CHECK(datum.SerializeToString(&out));
		txn->Put(caffe::format_int(itemid, 5), out);
	}
	txn->Commit();
	test_db->Close();
}

void DataConverter::convert_images(string&ImgFileList, string&RootDir,string&DbName,bool gray, bool shuffle, string & backend, int resize_width, int resize_height, bool check_size, bool encoded, string & encode_type)
{
#ifndef GFLAGS_GFLAGS_H_
	namespace gflags = google;
#endif

	const bool is_color = !gray;
	//const bool check_size = FLAGS_check_size;
	//const bool encoded = FLAGS_encoded;
	//const string encode_type = FLAGS_encode_type;

	std::ifstream infile(ImgFileList);
	std::vector<std::pair<std::string, int> > lines;
	std::string line;
	size_t pos;
	int label;
	while (std::getline(infile, line)) {
		pos = line.find_last_of(' ');
		label = atoi(line.substr(pos + 1).c_str());
		lines.push_back(std::make_pair(line.substr(0, pos), label));
	}
	if (shuffle) {
		// randomly shuffle data
		LOG(INFO) << "Shuffling data";
		caffe::shuffle(lines.begin(), lines.end());
	}
	LOG(INFO) << "A total of " << lines.size() << " images.";

	if (encode_type.size() && !encoded)
		LOG(INFO) << "encode_type specified, assuming encoded=true.";

	int _resize_height = std::max<int>(0, resize_height);
	int _resize_width = std::max<int>(0, resize_width);

	// Create new DB
	scoped_ptr<db::DB> db(db::GetDB(backend));
	db->Open(DbName, db::NEW);
	scoped_ptr<db::Transaction> txn(db->NewTransaction());

	// Storing to db
	//std::string root_folder(RootDir);
	Datum datum;
	int count = 0;
	int data_size = 0;
	bool data_size_initialized = false;

	for (int line_id = 0; line_id < lines.size(); ++line_id) {
		bool status;
		std::string enc = encode_type;
		if (encoded && !enc.size()) {
			// Guess the encoding type from the file name
			string fn = lines[line_id].first;
			size_t p = fn.rfind('.');
			if (p == fn.npos)
				LOG(WARNING) << "Failed to guess the encoding of '" << fn << "'";
			enc = fn.substr(p);
			std::transform(enc.begin(), enc.end(), enc.begin(), ::tolower);
		}
		status = ReadImageToDatum(RootDir + lines[line_id].first,
			lines[line_id].second, _resize_height, _resize_width, is_color,
			enc, &datum);
		if (status == false) continue;
		if (check_size) {
			if (!data_size_initialized) {
				data_size = datum.channels() * datum.height() * datum.width();
				data_size_initialized = true;
			}
			else {
				const std::string& data = datum.data();
				CHECK_EQ(data.size(), data_size) << "Incorrect data field size "
					<< data.size();
			}
		}
		// sequential
		string key_str = caffe::format_int(line_id, 8) + "_" + lines[line_id].first;

		// Put in db
		string out;
		CHECK(datum.SerializeToString(&out));
		txn->Put(key_str, out);

		if (++count % 1000 == 0) {
			// Commit db
			txn->Commit();
			txn.reset(db->NewTransaction());
			LOG(INFO) << "Processed " << count << " files.";
		}
	}
	// write the last batch
	if (count % 1000 != 0) {
		txn->Commit();
		LOG(INFO) << "Processed " << count << " files.";
	}

}

//转换Mnist数据集到本地数据库
bool DataConverter::MnistToDb(string image_filename, string label_filename, string db_path, string db_backend)
{
	//切换模式
	
	//校验参数
	if (image_filename != ""&&label_filename != ""&&db_path != ""&&
		(db_backend=="lmdb"|| db_backend == "leveldb")) {
		//传递值
		_image_filename = image_filename;
		_label_filename = label_filename;
		_db_path = db_path;
		_db_backend = db_backend;
		CurrentMode = MNIST;
		return true;
	}
	else {
		return false;
	}
}
//转换Cifar数据集到本地数据库
bool DataConverter::CifarToDb(string & input_folder, string & output_folder, string & db_type)
{
	if (input_folder != ""&&output_folder != "" &&
		(db_type == "lmdb" || db_type == "leveldb")) {
		_input_folder = input_folder;
		_output_folder = output_folder;
		_db_type = db_type;
		CurrentMode = CIFAR;
		return true;
	}
	else
	{
		return false;
	}
}
//将图片集装换到本地数据库
bool DataConverter::ImagesToDb(string & ImgFileList, string & RootDir, string & DbName, bool gray, bool shuffle, string & backend, int resize_width, int resize_height, bool check_size, bool encoded, string & encode_type)
{
	if (ImgFileList!="" && RootDir!=""&& DbName!=""&&(backend=="lmdb"|| backend == "leveldb") )
	{
		if (encode_type!="png"&&encode_type != "jpg")
		{
			string temp = "";
			_ImgFileList = ImgFileList;
			_RootDir= RootDir;
			_DbName= DbName;
			_gray= gray;
			_shuffle= shuffle;
			_backend= backend;
			_resize_width= resize_width;
			_resize_height= resize_height;
			_check_size= check_size;
			_encoded= false;
			_encode_type= temp;
		}
		else
		{//正常调用
			_ImgFileList = ImgFileList;
			_RootDir = RootDir;
			_DbName = DbName;
			_gray = gray;
			_shuffle = shuffle;
			_backend = backend;
			_resize_width = resize_width;
			_resize_height = resize_height;
			_check_size = check_size;
			_encoded = encoded;
			_encode_type = encode_type;
		}
		CurrentMode = IMAGE;
		return true;
	}
	else
	{
		return false;
	}
}
//重载线程方法
void DataConverter::run()
{
	//1.判断这一次运行是要转换什么数据集
	switch (CurrentMode)
	{
	case MNIST:
		convert_mnist_dataset(_image_filename, _label_filename, _db_path, _db_backend);
		break;
	case CIFAR:
		convert_cifar_dataset(_input_folder, _output_folder, _db_type);
		break;
	case IMAGE:
		convert_images(_ImgFileList, _RootDir, _DbName, _gray, _shuffle, _backend, _resize_width, _resize_height, _check_size, _encoded, _encode_type);
		break;
	default:
		break;
	}
	/*this->quit();*/
}
