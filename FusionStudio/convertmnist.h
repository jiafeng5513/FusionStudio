#pragma once

#include <QWidget>
#include "ui_convertmnist.h"
#include "QFileDialog"

#include "DataConverter.h"

class ConvertMnist : public QWidget
{
	Q_OBJECT

public:
	ConvertMnist(QWidget *parent = Q_NULLPTR);
	~ConvertMnist();
	void TellMeWhereIsTheBin(QString BinPath);
private:
	Ui::ConvertMnist ui;
	DataConverter *MyConverter;
private slots:
	void Browser1();
	void Browser2();
	void Browser3();
	void DoConvert_Mnist_Data();
};
