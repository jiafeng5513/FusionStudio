#include "browsedatabase.h"
#include <QFileDialog>
#include <QtCore/qmath.h>
#include <qDebug>
#include <QMessageBox>

BrowseDatabase::BrowseDatabase(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.radioButton_lmdb->setChecked(true);
}

BrowseDatabase::~BrowseDatabase()
{
}
//Mat转换为QImage
QImage BrowseDatabase::MatToQImage(const cv::Mat &mat)
{
	// 8-bits unsigned, NO. OF CHANNELS=1
	if (mat.type() == CV_8UC1)
	{
		// Set the color table (used to translate colour indexes to qRgb values)
		QVector<QRgb> colorTable;
		for (int i = 0; i<256; i++)
			colorTable.push_back(qRgb(i, i, i));
		// Copy input Mat
		const uchar *qImageBuffer = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat
		QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
		img.setColorTable(colorTable);
		return img;
	}
	// 8-bits unsigned, NO. OF CHANNELS=3
	if (mat.type() == CV_8UC3)
	{
		// Copy input Mat
		const uchar *qImageBuffer = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat
		QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return img.rgbSwapped();
	}
	else
	{
		//qDebug() << "ERROR: Mat could not be converted to QImage.";
		return QImage();
	}
}
//加载数据库文件
void BrowseDatabase::LoadDatabase() {
	//1.打开路径选择窗口
	QString tempInstallPath = QFileDialog::getExistingDirectory(this, QStringLiteral("选择数据库文件路径"), QDir::currentPath());
	if (tempInstallPath != "")
	{
		//2.绑定数据库操作句柄
		std::string datatype = (ui.radioButton_lmdb->isChecked() ? "lmdb" : "leveldb");
		
		if (ui.checkBox_ForcedDecoding->isChecked()==true)//使用强制解码
		{
			//用goto跳过判定
			goto VerifyCompleted;
		}
		//2.1验证数据库的有效性
		if (
			QFile::exists(tempInstallPath) && 
			 (
				(	datatype == "lmdb"&&
					QFile::exists(tempInstallPath + "/data.mdb") &&
					QFile::exists(tempInstallPath + "/lock.mdb")
				) || (
					datatype == "leveldb"&&
					QFile::exists(tempInstallPath + "/CURRENT") &&
					QFile::exists(tempInstallPath + "/LOCK") &&
					QFile::exists(tempInstallPath + "/LOG")
				)
			 )
			)
		{
VerifyCompleted:
			//通过验证
			MyDbHandle = new DbOperator(datatype, tempInstallPath.toStdString());
			//3.显示第一张图片
			cv::Mat imageToShow;
			int label = 0;
			MyDbHandle->getImage(imageToShow, label);
			QImage qimageToShow = MatToQImage(imageToShow);//得到了QImage
			QGraphicsScene *scene = new QGraphicsScene;
			scene->addPixmap(QPixmap::fromImage(qimageToShow));
			ui.graphicsView->setScene(scene);
			//ui.graphicsView->resize(qimageToShow.width() + 10, qimageToShow.height() + 10);
			ui.graphicsView->show();
			ui.lineEdit->setText(QString::number(label, 10));
		}
		else
		{
			QMessageBox::information(this, QStringLiteral("数据集浏览"), 
				QStringLiteral("选中的文件目录与所选的数据库类型不符或者数据库已经损坏!"));
			return;
		}
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("数据集浏览"),
			QStringLiteral("请选择一个数据库目录!"));
		return;
	}
}
//下一张图片
void BrowseDatabase::Nextimage()
{
	cv::Mat imageToShow;
	int label = 0;
	bool flag = MyDbHandle->getImage(imageToShow, label);
	if (flag==true)
	{
		QImage qimageToShow = MatToQImage(imageToShow);//得到了QImage
		QGraphicsScene *scene = new QGraphicsScene;
		scene->addPixmap(QPixmap::fromImage(qimageToShow));
		ui.graphicsView->setScene(scene);
		//ui.graphicsView->resize(qimageToShow.width() + 10, qimageToShow.height() + 10);
		ui.graphicsView->show();
		ui.lineEdit->setText(QString::number(label, 10));
	}
	else
	{
		qDebug()<< QStringLiteral("无图")<<"\n";
	}
	
}
//缩放
void BrowseDatabase::ZoomImage()
{
	qreal scale = qPow(qreal(2), (ui.zoomSlider->value()) / qreal(25));
	QMatrix matrix;//缩放矩阵
	matrix.scale(scale, scale);
	ui.graphicsView->setMatrix(matrix);
}

void BrowseDatabase::CrashWarning()
{
	if (ui.checkBox_ForcedDecoding->isChecked() == true) {
		QMessageBox::information(this, QStringLiteral("崩溃警告"),
		QStringLiteral("该选项将会屏蔽程序的故障诊断功能并进行强制解码\n可能会产生严重错误甚至导致程序崩溃!\n请谨慎使用!"));
	}
	
}
