#include "convertimage.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

ConvertImage::ConvertImage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	MyConverter = new DataConverter();
	ui.radioButton_Lmdb->setChecked(true);
}

ConvertImage::~ConvertImage()
{
}
//选择文件列表文件
void ConvertImage::Browser1()
{
	ui.lineEdit_ImgFileList->setText(
		QFileDialog::getOpenFileName(this,
			QStringLiteral("选择图片文件列表"),
			" ",
			QStringLiteral("文件列表(*.txt);;所有类型(*.*)")));
}
//选择根目录
void ConvertImage::Browser2()
{
	ui.lineEdit_RootDir->setText(
		QFileDialog::getExistingDirectory(this,
			QStringLiteral("选择图片文件的目录"), QDir::currentPath()));
}
//选择输出目录
void ConvertImage::Browser3()
{
	ui.lineEdit_OutputDir->setText(
		QFileDialog::getExistingDirectory(this,
			QStringLiteral("选择输出目录"), QDir::currentPath()));
}
//将一些参数设为默认参数
void ConvertImage::SetDefault()
{
}
//进行数据转换
void ConvertImage::DoConvert()
{

	QString absDbName = ui.lineEdit_OutputDir->text();
	absDbName.append("\\");
	absDbName.append(ui.lineEdit_DBName->text());

	std::string _temp = (ui.radioButton_Lmdb->isChecked() ? "lmdb" : "leveldb");
	bool flag = MyConverter->ImagesToDb(ui.lineEdit_ImgFileList->text().toStdString(),
		ui.lineEdit_RootDir->text().toStdString(),
		absDbName.toStdString(),
		ui.checkBox_isGray->isChecked(),
		ui.checkBox_isShuffle->isChecked(),
		_temp,
		ui.lineEdit_resize_width->text().toInt(),
		ui.lineEdit_resize_height->text().toInt(),
		ui.checkBox_isCheck_size->isChecked(),
		ui.checkBox_isEncoded->isChecked(),
		ui.lineEdit_encode_type->text().toStdString()
	);
	if (flag == false)
	{
		QMessageBox::information(this, QStringLiteral("数据转换"), QStringLiteral("转换失败!"));
	}
	else {
		//启动转换线程
		MyConverter->start();
		int cnt = 0; // 循环次数计数器，用于"计算"当前的进度值
		while (MyConverter->isRunning())  // 只要子线程还没有完成，就一直循环，并更新进度条
		{
			ui.progressBar->setValue((cnt++ % 20) * 5); // 进度值每次递增5%，达到100后则再次从0开始

			QEventLoop eventloop; // 使用事件循环阻塞主线程
			QTimer::singleShot(500, &eventloop, SLOT(quit())); // wait 0.5s
			eventloop.exec(); // 每0.5秒执行一次事件循环，然后更新进度条
		}
		ui.progressBar->setValue(100);
		QMessageBox::information(this, QStringLiteral("数据转换"), QStringLiteral("转换完成!"));
	}
}
