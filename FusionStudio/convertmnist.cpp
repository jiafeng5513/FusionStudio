#include "convertmnist.h"
#include <string>
#include <QMessageBox>
#include <QTimer>

ConvertMnist::ConvertMnist(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	MyConverter = new DataConverter();
	ui.radioButton_Lmdb->setChecked(true);
}

ConvertMnist::~ConvertMnist()
{
}
//从外面传入Bin路径
void ConvertMnist::TellMeWhereIsTheBin(QString BinPath)
{
}

//选择图片集
void ConvertMnist::Browser1() {
	/*
	参数1：父窗口
	参数2：对话框的标题
	参数3：默认的打开的位置，如”我的文档“等
	参数4：文件的过滤器，注意文件类型之间用  ；；  分开
	*/
	ui.lineEdit_MnistImageSet->setText(
		QFileDialog::getOpenFileName(this,
			QStringLiteral("选择图片集"),
			" ",
			QStringLiteral("Mnist图片集(*.idx3-ubyte);;所有类型(*.*)")));
}
//选择标签集
void ConvertMnist::Browser2() {
	/*
	参数1：父窗口
	参数2：对话框的标题
	参数3：默认的打开的位置，如”我的文档“等
	参数4：文件的过滤器，注意文件类型之间用  ；；  分开
	*/
	ui.lineEdit_MnistlabelSet->setText(
		QFileDialog::getOpenFileName(this,
			QStringLiteral("选择标签集"),
			" ",
			QStringLiteral("Mnist标签集(*.idx1-ubyte);;所有类型(*.*)")));
}
//选择结果存放地址
void ConvertMnist::Browser3() {
	/*
	参数1：父窗口
	参数2：对话框的标题
	参数3：默认的打开的位置，如”我的文档“等
	参数4：文件的过滤器，注意文件类型之间用  ；；  分开
	*/
	ui.lineEdit_MnistResult->setText(
		QFileDialog::getExistingDirectory(this,
			QStringLiteral("选择输出目录"), QDir::currentPath()));

}
//转换Mnist数据
void ConvertMnist::DoConvert_Mnist_Data()
{

	QString tempQS = ui.lineEdit_MnistResult->text();
	tempQS.append("\\");
	tempQS.append(ui.lineEdit_ResultName->text());


	std::string _temp = (ui.radioButton_Lmdb->isChecked() ? "lmdb" : "leveldb");
	bool flag=MyConverter->MnistToDb(ui.lineEdit_MnistImageSet->text().toStdString(),
									 ui.lineEdit_MnistlabelSet->text().toStdString(),
									 tempQS.toStdString(), _temp);
	if (flag==false)
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