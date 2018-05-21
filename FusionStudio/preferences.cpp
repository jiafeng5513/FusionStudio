#include "preferences.h"
#include "QSettings.h"
#include "QFile.h"
#include "QMessageBox.h"
#include "QFileDialog"
#include <qstandarditemmodel.h>

//========================================================================
//=============================内部方法===================================
//========================================================================
//构造函数
Preferences::Preferences(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//额外的ui初始化
	ScriptsModel = new QStandardItemModel();
	ScriptsModel->setColumnCount(2);
	ScriptsModel->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("功能"));
	ScriptsModel->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("命令"));
	ui.tableView->setModel(ScriptsModel);
	ui.tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);//表头信息显示居左
	/*==========默认参数==========*/
	IniFilePath = "./EngineStart.ini";//默认配置文件地址

	FuncList.append("train");//脚本的功能,同时也是索引脚本内容的键值
	FuncList.append("test");
	FuncList.append("convert_image");

	Scripts.insert("train", " train --solver=");//对应键值的脚本的默认内容
	Scripts.insert("test", " test_Script");
	Scripts.insert("convert_image", " convert_image_Script");

	defaultInstallPath = "E:\\VisualStudio\\FusionStudio\\FusionStudio\\Components\\caffe-CPU-py27";//默认install目录
	defaultBinPath="E:\\VisualStudio\\FusionStudio\\FusionStudio\\Components\\caffe-CPU-py27\\bin";//默认bin目录
	defaultLibPath="E:\\VisualStudio\\FusionStudio\\FusionStudio\\Components\\caffe-CPU-py27\\lib";//默认Lib目录

	//defaultScript_Train=" train --solver=";//默认脚本
	//初始化方法
	initialize();
}
//析构函数
Preferences::~Preferences()
{
}
/*
方法:初始化
功能:查看配置文件是否存在,如果不存在,则建立配置文件,并写入默认数据
*/
void Preferences::initialize()
{
	//QFile file(IniFilePath);
	QFile *file = new QFile(IniFilePath);
	if (file->exists()) {
		//QMessageBox::information(this, "测试", QStringLiteral("文件存在"));
	}
	else {//配置文件不存在
		//Qt中使用QSettings类读写ini文件  
		//QSettings构造函数的第一个参数是ini文件的路径,第二个参数表示针对ini文件,第三个参数可以缺省  
		QSettings *configIniWrite = new QSettings(IniFilePath, QSettings::IniFormat);
		//向ini文件中写入内容,setValue函数的两个参数是键值对  
		//向ini文件中写入默认配置参数
		configIniWrite->setValue("path/install", defaultInstallPath);
		configIniWrite->setValue("path/bin", defaultBinPath);
		configIniWrite->setValue("path/lib", defaultLibPath);

		//将命令脚本的键值(就是对应脚本的的功能)写入ini文件的一个数组里面
		configIniWrite->beginWriteArray("FuncList");
		for (int i = 0; i < FuncList.size(); i++)
		{
			configIniWrite->setArrayIndex(i);
			configIniWrite->setValue("Func", FuncList[i]);
		}
		configIniWrite->endArray();
		//将键值对应的值写入ini文件
		configIniWrite->beginGroup("Scripts");
		for (int i = 0; i < FuncList.size(); i++)
		{
			QMap<QString, QString>::iterator it = Scripts.find(FuncList[i]);
			configIniWrite->setValue(FuncList[i], it.value());
		}
		configIniWrite->endGroup();
		//写入完成后删除指针  
		delete configIniWrite;
	};
	delete file;
}
//切换配置文件
void Preferences::iniFileSwitch(QString path)
{
	IniFilePath = path;
	initialize();
}
//唤醒首选项管理器
void Preferences::awakenPreferencesManager()
{
	//把目前的状态显示到界面上
	//显示路径设置
	ui.lineEdit_BinPath->setText(readBinPath());
	ui.lineEdit_InstallPath->setText(readInstallPath());
	ui.lineEdit_LibPath->setText(readLibPath());
	//显示命令设置(表格)
		///首先查询出所有的key,放在一个临时容器(向量)里面,
	QVector <QString> _tempFuncList;
	QSettings *mod_read = new QSettings(IniFilePath, QSettings::IniFormat, 0);
	int num = mod_read->beginReadArray("FuncList");
	for (int i = 0; i<num; i++)
	{
		mod_read->setArrayIndex(i);
		_tempFuncList.append( mod_read->value("Func", "该命令为空").toString());
	}
	mod_read->endArray();
		///然后进入循环,用key从文件中查询出内容,再把key和内容写到同一行中,然后循环变量后移
	mod_read->beginGroup("Scripts");
	for (int i = 0; i < num; i++)
	{
	
		ScriptsModel->setItem(i, 0, new QStandardItem(_tempFuncList[i]));//功能字段
		ScriptsModel->item(i, 0)->setForeground(QBrush(QColor(255, 0, 0)));//设置字符颜色
		ScriptsModel->item(i, 0)->setTextAlignment(Qt::AlignCenter);//设置字符位置
		ScriptsModel->setItem(i, 1, new QStandardItem(mod_read->value(_tempFuncList[i]).toString()));//命令字段
	}
	mod_read->endGroup();
	delete mod_read;
}
//从文件中读取install路径
QString Preferences::readInstallPath()
{
	QSettings *configIniRead = new QSettings(IniFilePath, QSettings::IniFormat);
	//将读取到的ini文件保存在QString中，先取值，然后通过toString()函数转换成QString类型   
	QString Result = configIniRead->value("path/install").toString();
	
	//读入入完成后删除指针   
	delete configIniRead;
	return Result;
}
//从文件中读取bin的路径
QString Preferences::readBinPath()
{
	QSettings *configIniRead = new QSettings(IniFilePath, QSettings::IniFormat);  
	QString Result = configIniRead->value("path/bin").toString();
	delete configIniRead;
	return Result;
}
//从文件中读取lib的路径
QString Preferences::readLibPath()
{
	QSettings *configIniRead = new QSettings(IniFilePath, QSettings::IniFormat);
	QString Result = configIniRead->value("path/lib").toString();
	delete configIniRead;
	return Result;
}
//从文件中读取对应Func的脚本
QString Preferences::readScript(QString Func)
{
	QSettings *configIniRead = new QSettings(IniFilePath, QSettings::IniFormat);
	configIniRead->beginGroup("Scripts");
	QString Result = configIniRead->value(Func,"").toString();
	configIniRead->endGroup();
	delete configIniRead;
	return Result;
}
//将install路径写入文件
void Preferences::writeInstallPath(QString path)
{
	QSettings *configIniWrite = new QSettings(IniFilePath, QSettings::IniFormat);
	configIniWrite->setValue("path/install", path);
	delete configIniWrite;
}
//将bin路径写入文件
void Preferences::writeBinPath(QString path)
{
	QSettings *configIniWrite = new QSettings(IniFilePath, QSettings::IniFormat);
	configIniWrite->setValue("path/bin", path);
	delete configIniWrite;
}
//将lib路径写入文件
void Preferences::writeLibPath(QString path)
{
	QSettings *configIniWrite = new QSettings(IniFilePath, QSettings::IniFormat);
	configIniWrite->setValue("path/lib", path);
	delete configIniWrite;
}
//将对应Func的脚本写入文件
void Preferences::writeScript(QString Func, QString script)
{
	QSettings *configIniWrite = new QSettings(IniFilePath, QSettings::IniFormat);
	configIniWrite->beginGroup("Scripts");
	configIniWrite->setValue(Func, script);
	configIniWrite->endGroup();
	delete configIniWrite;
}

//========================================================================
//=============================外部接口===================================
//========================================================================

//获取install目录
QString Preferences::getInstallPath()
{
	return readInstallPath();
}
//获取bin目录
QString Preferences::getBinPath()
{
	return readBinPath();
}
//获取lib目录
QString Preferences::getLibPath()
{
	return readLibPath();
}
//获取指定脚本
QString Preferences::getScript(QString Func)
{
	return readScript(Func);
}

//=========================================================================
//=============================槽函数======================================
//=========================================================================

//浏览1
void Preferences::Browser1()
{
	QString tempInstallPath = QFileDialog::getExistingDirectory(this,tr("选择install目录"), QDir::currentPath());
	if (tempInstallPath!="")
	{
		ui.lineEdit_InstallPath->setText(tempInstallPath);
	}
}
//浏览2
void Preferences::Browser2()
{
	QString tempBinPath = QFileDialog::getExistingDirectory(this,tr("选择bin目录"), QDir::currentPath());
	if (tempBinPath!="")
	{
		ui.lineEdit_BinPath->setText(tempBinPath);
	}
}
//浏览3
void Preferences::Browser3()
{
	QString tempLibPath = QFileDialog::getExistingDirectory(this, tr("选择lib目录"), QDir::currentPath());
	if (tempLibPath != "") {
		ui.lineEdit_LibPath->setText(tempLibPath);
	}
}
//检查组件状态
void Preferences::checkComponent()
{
	//构造检查表
	QString CheckList[]{ "caffe.exe","classification.exe","compute_image_mean.exe",
		"convert_cifar_data.exe","convert_imageset.exe","convert_mnist_data.exe",
		"convert_mnist_siamese_data.exe","device_query.exe","extract_features.exe",
		"finetune_net.exe","net_speed_benchmark.exe","test_net.exe",
		"train_net.exe","upgrade_net_proto_binary.exe","upgrade_net_proto_text.exe",
		"upgrade_solver_proto_text.exe" };
	ui.plainTextEdit_ComponentState->clear();
	QString tempBinPath = readBinPath();
	if (tempBinPath!="") 
	{
		ui.plainTextEdit_ComponentState->appendPlainText(QStringLiteral("正在校验核心组件:")+ tempBinPath);
		tempBinPath = tempBinPath.append("\\");
		for (int i = 0; i < 16; i++)
		{
			QString _currentFile = tempBinPath;
			_currentFile.append(CheckList[i]);
			QFile file(_currentFile);
			if (file.exists()) {
				ui.plainTextEdit_ComponentState->appendPlainText(CheckList[i] + "...OK!");
			}
			else
			{
				ui.plainTextEdit_ComponentState->appendPlainText(CheckList[i] + "...ERROR!");
			}
		}
	}
	else
	{
		ui.plainTextEdit_ComponentState->appendPlainText(QStringLiteral("bin目录为空!"));
	}

}
//全部路径设置成默认参数
void Preferences::setDefaultPath()
{
	
	ui.lineEdit_BinPath->setText(defaultBinPath);
	ui.lineEdit_InstallPath->setText(defaultInstallPath);
	ui.lineEdit_LibPath->setText(defaultLibPath);
}

void Preferences::creatEnvironmentVariable()
{
	//导入环境变量
}
//全部脚本设为默认
void Preferences::setDefaultScripts()
{
	for (int i = 0; i < FuncList.size(); i++)
	{
		QMap<QString, QString>::iterator it = Scripts.find(FuncList[i]);
		ScriptsModel->setItem(i, 0, new QStandardItem(FuncList[i]));//功能字段
		ScriptsModel->item(i, 0)->setForeground(QBrush(QColor(255, 0, 0)));//设置字符颜色
		ScriptsModel->item(i, 0)->setTextAlignment(Qt::AlignCenter);//设置字符位置
		ScriptsModel->setItem(i, 1, new QStandardItem(it.value()));//命令字段

	}
}
//保存
void Preferences::save()
{
	//保存路径设置
	writeBinPath(ui.lineEdit_BinPath->text());
	writeInstallPath(ui.lineEdit_InstallPath->text());
	writeLibPath(ui.lineEdit_LibPath->text());
	//保存脚本设置
	///读取整个表格,非空的进行覆盖
	ScriptsModel->rowCount();//一共多少行
	QString _tempFunc = ScriptsModel->data(ScriptsModel->index(3, 1)).toString();//第3行第1列的内容
	QString _tempScript;
	for (int i = 0; i < ScriptsModel->rowCount(); i++)
	{
		_tempFunc = ScriptsModel->data(ScriptsModel->index(i, 0)).toString();//第i行第1列的内容
		_tempScript= ScriptsModel->data(ScriptsModel->index(i, 1)).toString();//第i行第2列的内容
		if (_tempFunc!=""&&_tempScript!="")
		{
			writeScript(_tempFunc, _tempScript);
		}
	}
	//保存组件设置

}

