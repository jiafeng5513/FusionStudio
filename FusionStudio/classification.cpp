#include "classification.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QtCore/qmath.h>

Classification::Classification(QString coredir, QProcess *addprocess, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	CoreDir= coredir;
	_AdditionalProcess= addprocess;
}

Classification::~Classification()
{
}

void Classification::Browser1()
{
	ui.lineEdit_deploy->setText(
		QFileDialog::getOpenFileName(this,
			QStringLiteral("选择网络部署描述文件"),
			" ",
			QStringLiteral("部署描述(*.prototxt);;所有类型(*.*)")));
}

void Classification::Browser2()
{
	ui.lineEdit_caffemodel->setText(
		QFileDialog::getOpenFileName(this,
			QStringLiteral("选择预训练网络文件"),
			" ",
			QStringLiteral("caffe预训练网络(*.caffemodel);;所有类型(*.*)")));
}

void Classification::Browser3()
{
	ui.lineEdit_binaryproto->setText(
		QFileDialog::getOpenFileName(this,
			QStringLiteral("选择图片均值文件"),
			" ",
			QStringLiteral("图片均值(*.binaryproto);;所有类型(*.*)")));
}

void Classification::Browser4()
{
	ui.lineEdit_labels->setText(
		QFileDialog::getOpenFileName(this,
			QStringLiteral("选择标签辞典文件"),
			" ",
			QStringLiteral("标签辞典(*.txt);;所有类型(*.*)")));
}

void Classification::Browser5()
{
	ui.lineEdit_img->setText(
		QFileDialog::getOpenFileName(this,
			QStringLiteral("选择图片"),
			" ",
			QStringLiteral("图片(*.jpg);;所有类型(*.*)")));
}
//分类
void Classification::DoClassification()
{
	//校验参数
	if (ui.lineEdit_deploy->text().toStdString() != ""&&
		ui.lineEdit_caffemodel->text().toStdString() != ""&&
		ui.lineEdit_binaryproto->text().toStdString() != ""&&
		ui.lineEdit_labels->text().toStdString() != ""&&
		ui.lineEdit_img->text().toStdString() != "")
	{
	//显示图片
		QImage *_img = new QImage();
		if (_img->load(ui.lineEdit_img->text()) == true) 
		{
			QGraphicsScene *scene = new QGraphicsScene;
			scene->addPixmap(QPixmap::fromImage(*_img));
			ui.graphicsView->setScene(scene);
			//构造命令
			QString cmd="";
			cmd.append(CoreDir);
			cmd.append("/classification.exe");cmd.append(" ");
			cmd.append(ui.lineEdit_deploy->text()); cmd.append(" ");
			cmd.append(ui.lineEdit_caffemodel->text()); cmd.append(" ");
			cmd.append(ui.lineEdit_binaryproto->text()); cmd.append(" ");
			cmd.append(ui.lineEdit_labels->text()); cmd.append(" ");
			cmd.append(ui.lineEdit_img->text());
			//启动额外线程
			_AdditionalProcess->start(cmd);
		}
		else
		{
			QMessageBox::information(this, QStringLiteral("分类测试"), QStringLiteral("图片打开失败!"));
			return;
		};
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("分类测试"), QStringLiteral("参数有误!"));
		return;
	}
	

}

void Classification::ZoomImage()
{
	qreal scale = qPow(qreal(2), (ui.horizontalSlider->value()) / qreal(25));
	QMatrix matrix;//缩放矩阵
	matrix.scale(scale, scale);
	ui.graphicsView->setMatrix(matrix);
}
