#include "featureexp.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

FeatureExp::FeatureExp(QString coredir, QProcess *addprocess, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.radioButton_lmdb->setChecked(true);
	CoreDir = coredir;
	_AdditionalProcess = addprocess;
}

FeatureExp::~FeatureExp()
{
}
//选择训练好的网络模型
void FeatureExp::Browser1()
{
	ui.lineEdit_Model->setText(
		QFileDialog::getOpenFileName(this,
			QStringLiteral("选择训练好的网络模型"),
			" ",
			QStringLiteral("caffe网络模型(*.caffemodel);;所有类型(*.*)")));
}
//选择网络部署描述文件
void FeatureExp::Browser2()
{
	ui.lineEdit_Prototxt->setText(
		QFileDialog::getOpenFileName(this,
			QStringLiteral("选择网络部署描述文件"),
			" ",
			QStringLiteral("部署描述文件(*.prototxt);;所有类型(*.*)")));
}
//选择导出位置
void FeatureExp::Browser3()
{
	ui.lineEdit_ExpPath->setText(
		QFileDialog::getExistingDirectory(this,
			QStringLiteral("选择输出目录"), QDir::currentPath()));
}
//验证?验证什么鬼???直接上算了反正已经没时间了
void FeatureExp::Verification()
{
}
//执行特征导出
void FeatureExp::DoFeatureExp()
{
	QString tempQS = ui.lineEdit_ExpPath->text();
	tempQS.append("/");
	tempQS.append(ui.lineEdit_DbName->text());

	std::string _temp = "lmdb";

	//直接调用业务逻辑
	//校验参数
	if (ui.lineEdit_Model->text() != ""&&
		ui.lineEdit_Prototxt->text() != ""&&
		ui.lineEdit_LayerID->text() != ""&&
		ui.lineEdit_MiniBatches->text() != ""&&
		tempQS!="")
	{
		//构造命令
		QString cmd = "";
		cmd.append(CoreDir);
		cmd.append("/extract_features.exe"); cmd.append(" ");
		cmd.append(ui.lineEdit_Model->text()); cmd.append(" ");
		cmd.append(ui.lineEdit_Prototxt->text()); cmd.append(" ");
		cmd.append(ui.lineEdit_LayerID->text()); cmd.append(" ");
		cmd.append(tempQS); cmd.append(" ");
		cmd.append(ui.lineEdit_MiniBatches->text()); cmd.append(" ");
		cmd.append((ui.radioButton_lmdb->isChecked() ? "lmdb" : "leveldb")); cmd.append(" ");
		cmd.append((ui.comboBox_cupgpu->currentIndex()==0 ? "CPU" : "GPU"));
		//启动额外线程
		_AdditionalProcess->start(cmd);
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("特征导出"), QStringLiteral("参数有误!"));
		return;
	}

}
