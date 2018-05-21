#pragma once

#include <QWidget>
#include "ui_classification.h"
#include <QProcess>
#include <QString>

/*
编程:天使微积分
时间:2017年5月1日14:50:37
备注:这个功能没办法使用中间层来隔离Qmake,所以只能使用外部委托来实现
     这个类中,额外线程的指针的传递比较有参考价值
*/
class Classification : public QWidget
{
	Q_OBJECT

public:
	Classification(QString coredir,QProcess *addprocess,QWidget *parent = Q_NULLPTR);
	~Classification();

private:
	Ui::Classification ui;
	QString CoreDir;//保存核心目录
	QProcess *_AdditionalProcess;//指向主界面类中已经重定向的那个线程,浅拷贝,构造赋值
public slots:
	void Browser1();
	void Browser2();
	void Browser3();
	void Browser4();
	void Browser5();
	void DoClassification();
	void ZoomImage();

};
