#include "DbOperator.h"

#include <stdint.h>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <stdexcept>  

#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include "boost/scoped_ptr.hpp"
#include "gflags/gflags.h"
#include "glog/logging.h"

#include "caffe/proto/caffe.pb.h"
#include "caffe/util/db.hpp"
#include "caffe/util/io.hpp"


using namespace caffe;  // NOLINT(build/namespaces)

using std::max;
using std::pair;
using boost::scoped_ptr;

boost::scoped_ptr<db::DB> _db;//db这个命名与某个命名空间冲突
boost::scoped_ptr<db::Cursor> cursor;
//初始化
DbOperator::DbOperator(string DbType, string filename)
{
	try
	{
		//默认使用lmdb
		if (DbType=="leveldb")
		{
			_db.reset(db::GetDB("leveldb"));
			_db->Open(filename, db::READ);//打开leveldb数据库
		}
		else {
			_db.reset(db::GetDB("lmdb"));
			_db->Open(filename, db::READ);//打开lmdb数据库
		}
		cursor.reset(_db->NewCursor());//绑定游标
	}
	catch (const std::exception&e)
	{
		std::cout << "有问题!"<<e.what();
	}
}

DbOperator::~DbOperator()
{

}

//获取当前游标下的图片,并把游标后移一位
bool DbOperator::getImage(cv::Mat & img, int &label)
{
	if (cursor->valid())//当前游标有效
	{
		Datum datum;
		bool flag = datum.ParseFromString(cursor->value());
		string DarkMagic = cursor->value();//使用黑魔法强制解码
		DecodeDatumNative(&datum);
		if (datum.has_data())
		{
			try
			{
				const string& data = datum.data();
				int height = datum.height();
				int width = datum.width();
				label =datum.label();
				cv::Mat cv_img_temp(height, width, CV_8UC1);//构造一个空的Mat
				for (int i = 0; i < height; i++) {
					for (int j = 0; j < width; j++) {
						char _temp = data.at(i * width + j);
						cv_img_temp.at<char>(i,j)= data.at(i * width + j);
					}
				}
				cv_img_temp.copyTo(img);//传递结果
			}
			catch (std::out_of_range &exc)
			{
				std::cerr << exc.what() << " Line:" << __LINE__ << " File:" << __FILE__ << "\n";
			}
		}
		else
		{
			//正常解码方案已经无法使用,尝试使用黑魔法
			try
			{
				const string& data = datum.data();
				int height = datum.height();
				int width = datum.width();
				label = datum.label();
				cv::Mat cv_img_temp(height, width, CV_8UC1);//构造一个空的Mat
				for (int i = 0; i < height; i++) {
					for (int j = 0; j < width; j++) {
						cv_img_temp.at<char>(i, j) = DarkMagic.at(i * width + j);
					}
				}
				cv_img_temp.copyTo(img);//传递结果
			}
			catch (std::out_of_range &exc)
			{
				std::cerr << exc.what() << " Line:" << __LINE__ << " File:" << __FILE__ << "\n";
			}
			//return false;//当前游标指向了空位置
		}
		cursor->Next();
		return true;
	}
	else
	{
		return false;//当前游标无效
	}
}


