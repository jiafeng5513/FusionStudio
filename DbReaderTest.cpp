#include <stdint.h>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include "boost/scoped_ptr.hpp"
#include "gflags/gflags.h"
#include "glog/logging.h"

#include "caffe/proto/caffe.pb.h"
#include "caffe/util/db.hpp"
#include "caffe/util/io.hpp"

#include "DbReaderTest.h"
using namespace caffe;  // NOLINT(build/namespaces)

using std::max;
using std::pair;
using boost::scoped_ptr;



int Go_Fuck_The_Main() {

	//scoped_ptr<db::DB> db(db::GetDB("lmdb"));

	scoped_ptr<db::DB> db;
	db.reset(db::GetDB("lmdb"));

	db->Open("E:/test", db::READ);
	scoped_ptr<db::Cursor> cursor(db->NewCursor());
	bool succeed = false;
	int i = 0;

	while (cursor->valid()) {
		Datum datum;
		datum.ParseFromString(cursor->value());
		DecodeDatumNative(&datum);

		cv::Mat cv_img;
		bool is_color = true;

		//cv_img = DecodeDatumToCVMat(datum,false);
		//cv_img = DecodeDatumToCVMatNative(datum);
		//CHECK(datum.encoded()) << "Datum not encoded";

		//1.现在假设data这个字符串是正确的且非空的
		const string& data = datum.data();
		//2.data->char[28][28]
		unsigned char cbuf[28][28];
		for (int i = 0; i < 28; i++) {
			for (int j = 0; j < 28; j++) {
				cbuf[i][j] = data.at(i*28+j);
			}
		}
		//3.从数组中建立Mat
		cv::Mat img(28, 28, CV_8UC1, cbuf);
		//4.what ?竟然好用了......我要杀人别拦着我
		/*
		编程:天使微积分
		备注:2017年3月22日14:10:32,这个奇诡的BUG终于解决了
		我认为引发的原因很有可能是多字节编码和UNICODE编码的切换
		还有可能是本渣渣无法理解编写caffe的前辈的高深思想
		*/
		/*std::vector<char> vec_data(data.c_str(), data.c_str() + data.size());
		int cv_read_flag = (is_color ? CV_LOAD_IMAGE_COLOR :CV_LOAD_IMAGE_GRAYSCALE);
		cv_img = cv::imdecode(vec_data, cv_read_flag);*/
		/*if (!cv_img.data) {
			LOG(ERROR) << "Could not decode datum ";
		}*/


		if (img.data!= NULL) {
			cv::namedWindow("img", CV_WINDOW_NORMAL);
			cv::imshow("img", img);
			cv::waitKey(0);
			succeed = true;
		}
		
		cursor->Next();
		i++;
	}

	return 0;
}
