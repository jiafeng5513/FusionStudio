#include "convertcifar.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

ConvertCifar::ConvertCifar(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	MyConverter = new DataConverter();
	ui.LmDbButton->setChecked(true);
}

ConvertCifar::~ConvertCifar()
{
}

void ConvertCifar::Browser1()
{
	ui.lineEdit_Inputfolder->setText(
		QFileDialog::getExistingDirectory(this,
			QStringLiteral("选择Cifar数据集目录"), QDir::currentPath()));
}
void ConvertCifar::Browser2()
{
	ui.lineEdit_outputfolder->setText(
		QFileDialog::getExistingDirectory(this,
			QStringLiteral("选择输出目录"), QDir::currentPath()));
}

void ConvertCifar::DoConvert()
{
	std::string _temp = (ui.LmDbButton->isChecked()?"lmdb":"leveldb");//lmdb
	
	bool flag = MyConverter->CifarToDb(ui.lineEdit_Inputfolder->text().toStdString(),
						               ui.lineEdit_outputfolder->text().toStdString(), _temp);
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
