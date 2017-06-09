#pragma once

#include <QWidget>
#include "ui_homepage.h"

class HomePage : public QWidget
{
	Q_OBJECT

public:
	HomePage(QWidget *parent = Q_NULLPTR);
	~HomePage();

private:
	Ui::HomePage ui;
public slots:
	void LinkToAuthor();
	void LinkToCaffe();
	void HelpViewer();
	void About();
};
