#pragma once

#include <QWidget>
#include "ui_convertimage.h"

#include "DataConverter.h"

class ConvertImage : public QWidget
{
	Q_OBJECT

public:
	ConvertImage(QWidget *parent = Q_NULLPTR);
	~ConvertImage();

private:
	Ui::ConvertImage ui;
	DataConverter *MyConverter;
public slots:
	void Browser1();
	void Browser2();
	void Browser3();
	void SetDefault();
	void DoConvert();
};
