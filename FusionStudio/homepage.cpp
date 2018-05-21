#include "homepage.h"
#include <QDesktopServices>
#include <QUrl>
#include "about.h"

HomePage::HomePage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

HomePage::~HomePage()
{
}

void HomePage::LinkToAuthor()
{
	QDesktopServices::openUrl(QUrl("http://my.csdn.net/Angle_Cal"));
}

void HomePage::LinkToCaffe()
{
	QDesktopServices::openUrl(QUrl("http://caffe.berkeleyvision.org/"));
}

void HomePage::HelpViewer()
{
	QDesktopServices::openUrl(QUrl("https://github.com/BVLC/caffe/tree/windows"));
}

void HomePage::About()
{
	class About *_aboutPage = new class About();
	_aboutPage->show();
}
