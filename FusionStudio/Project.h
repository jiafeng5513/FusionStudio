#pragma once

#include <QObject>
/*
编程:天使微积分
修改时间:2017年1月29日17:39:01
功能:封装一个工程的所有属性
备注:这应该是一个单例类,同一时刻最多只能有一个活跃的工程
*/
class Project : public QObject
{
	Q_OBJECT

public:
	///构造和析构
	Project(QObject *parent = 0);
	~Project();
private:
	///工程的私有属性
	QString WorkingDir;          //该工程的工作目录
public:
	///属性的get和set方法
	void setWorkingDir(QString);//工作目录的set方法
	QString getWorkingDir();    //工作目录的get方法

public:
	///工程的共有方法

private:
	///工程的私有方法

signals :
	void ValueChanged();        //自定义值更改信号
};
