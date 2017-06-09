#pragma once
//#include "boost/scoped_ptr.hpp"
//#include "caffe/util/db.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
/*
编    程:天使微积分
创建时间:2017年3月22日10:50:39
创建备注:这个类用来封装和数据库有关的操作
         加载数据库文件,读取数据库中的图片
		 使用时,用文件路径对本类做初始化
*/
class DbOperator
{
public:
	DbOperator(std::string DbType,std::string filename);//初始化
	~DbOperator();
public:
	///公开属性,
	//数据库对象

	//图片数量
	int numOfImage;
	//图片长
	int length;
	//图片宽
	int width;
	//图片是否为彩色
	bool isColour;
	//当前游标
	
private:
	///私有函数
	//获取数据库的状态参数,如一共有多少张图片,每张图片有多大,是否为彩色
public:
	///公开函数
	//获取当前图片,并把游标后移一位
	bool getImage(cv::Mat & img,int &label);
	//使用临时游标,获取特定的某张图片
	//获取标签?
	void heheh();

};

