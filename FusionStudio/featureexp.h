#pragma once

#include <QWidget>
#include "ui_featureexp.h"
#include <QProcess>

class FeatureExp : public QWidget
{
	Q_OBJECT

public:
	FeatureExp(QString coredir, QProcess *addprocess, QWidget *parent = Q_NULLPTR);
	~FeatureExp();

private:
	Ui::FeatureExp ui;
	QString CoreDir;//保存核心目录
	QProcess *_AdditionalProcess;//指向主界面类中已经重定向的那个线程,浅拷贝,构造赋值
public slots:
	void Browser1();
	void Browser2();
	void Browser3();
	void Verification();
	void DoFeatureExp();
};
