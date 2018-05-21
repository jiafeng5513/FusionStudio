#include "Project.h"

/*
编程:天使微积分
修改时间:2017年1月29日17:39:01
工程类的实现函数
*/

Project::Project(QObject *parent)
	: QObject(parent)
{
	WorkingDir = "";
}

Project::~Project()
{
}

void Project::setWorkingDir(QString NewValue)
{
	if (NewValue != WorkingDir)
	{
		WorkingDir = NewValue;
		emit ValueChanged();//值更改,发出信号
	}
}

QString Project::getWorkingDir()
{
	return WorkingDir;
}
