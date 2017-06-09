#pragma once
#include <string>
#include <fstream>  // NOLINT(readability/streams)
#include <QThread>
/*
实现数据转换的实际业务逻辑,用来隔离Qmake和protoc的转换过程
*/
class DataConverter:public QThread
{
public:
	DataConverter();
	~DataConverter();
	enum mode {MNIST,CIFAR,IMAGE,DEFAULT};//运行模式,DEFAULT下不启动内核
public:
	///外部操作
	bool MnistToDb(std::string image_filename, std::string label_filename, std::string db_path, std::string db_backend);
	bool CifarToDb(std::string& input_folder,std::string& output_folder,std::string& db_type);
	bool ImagesToDb(std::string&ImgFileList, std::string&RootDir, std::string&DbName, bool gray, bool shuffle, std::string & backend, int resize_width, int resize_height, bool check_size, bool encoded, std::string & encode_type);
	void run();
private :
	///内部变量
	mode CurrentMode;//当前运行模式
	//MNIST模式变量
	std::string _image_filename;
	std::string _label_filename;
	std::string _db_path;
	std::string _db_backend;
	//CIFAR模式变量
	std::string _input_folder;
	std::string _output_folder;
	std::string _db_type;
	//IMAGE模式变量
	std::string _ImgFileList;
	std::string _RootDir;
	std::string _DbName;
	bool _gray;
	bool _shuffle;
	std::string  _backend;
	int _resize_width;
	int _resize_height;
	bool _check_size;
	bool _encoded;
	std::string  _encode_type;
private:
	///内部操作11
	uint32_t swap_endian(uint32_t val);
	void convert_mnist_dataset(std::string& image_filename,
		std::string& label_filename,
		std::string& db_path,
		std::string& db_backend);

	void read_image(std::ifstream* file, int* label, char* buffer);
	void convert_cifar_dataset(std::string& input_folder,
							   std::string& output_folder,
		                       std::string& db_type);

	void convert_images(std::string&ImgFileList,//图片文件列表
						std::string&RootDir,//图片集根目录
		                std::string&DbName,//生成的数据库的绝对文件名
						bool gray,//是否将图片视为灰度图
					    bool shuffle,//是否对图片进行洗牌
						std::string &backend,//使用何种数据库
						int resize_width,//将图片的宽度调整到多少
						int resize_height,//将图片的高度调整到多少
						bool check_size,//是否检查所有的datum尺寸的一致性
						bool encoded,//是否将已编码的图片保存在Datum中
						std::string &encode_type//图片的编码形式(png,jpg等)
						);
};

