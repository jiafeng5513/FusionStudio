#pragma once

#include <QWidget>
#include "ui_convertcifar.h"

#include "DataConverter.h"
class ConvertCifar : public QWidget
{
	Q_OBJECT

public:
	ConvertCifar(QWidget *parent = Q_NULLPTR);
	~ConvertCifar();

private:
	Ui::ConvertCifar ui;
	DataConverter *MyConverter;
public slots:
	void Browser1();
	void Browser2();
	void DoConvert();
};
