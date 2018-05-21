#pragma once

#include <QWidget>
#include "ui_about.h"

class About : public QWidget
{
	Q_OBJECT

public:
	About(QWidget *parent = Q_NULLPTR);
	~About();

private:
	Ui::About ui;
};
