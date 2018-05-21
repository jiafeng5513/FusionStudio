#pragma once

#include <QWidget>
#include "ui_preferences.h"
#include "QStandardItemModel.h"
/*
编程:天使微积分
创建时间;2017年2月20日09:06:24
备注:1.这个类用于管理程序的配置文件,将首选项设置导入文件保存,并对外开放访问接口.
     2.这个类具有较高的优先级,他的初始化顺序排在主界面之前.
	 3.提供一个函数,该函数启动首选项管理器.
	 4.程序应该固化一组默认参数用来生成默认的配置文件或者对配置文件进行初始化.
	 5.读取一个属性的时候,首先查找配置文件,如果读取失败后者验证失败,则读取默认参数.
*/

class Preferences : public QWidget
{
	Q_OBJECT

public:
	Preferences(QWidget *parent = Q_NULLPTR);
	~Preferences();
private:
	Ui::Preferences ui;
///业务操作
private:
	void initialize();//初始化
	void iniFileSwitch(QString path);//配置文件切换
	
	///从文件读取,有问题返回NULL
	QString readInstallPath();//读取install目录
	QString readBinPath();//读取bin目录
	QString readLibPath();//读取Lib目录
	QString readScript(QString Func);//读取对应func功能的脚本
	///写入文件
	void writeInstallPath(QString path);//写入install目录
	void writeBinPath(QString path);//写入bin目录
	void writeLibPath(QString path);//写入Lib目录
	void writeScript(QString Func,QString script);//写入对应func功能的脚本
public:
	void awakenPreferencesManager();//唤醒首选项管理器
	///从此类外部访问配置
	QString defaultInstallPath;//默认install目录
	QString defaultBinPath;//默认bin目录
	QString defaultLibPath;//默认Lib目录
	QVector <QString> FuncList;//存储脚本的key,命名规则为对应脚本的功能
	QMap <QString, QString> Scripts;//存储所有的脚本
	QString defaultScript_Train;//默认脚本
public:
	///保存默认参数
	QString getInstallPath();//获取install目录
	QString getBinPath();//获取bin目录
	QString getLibPath();//获取Lib目录
	QString getScript(QString Func);//获取对应func功能的脚本
private:
	///维持本类正常工作所需的内部参数
	QString IniFilePath;//保存当前所使用的配置文件路径
	QStandardItemModel  *ScriptsModel;//命令表格模型
private slots:
	void Browser1();
	void Browser2();
	void Browser3();
	void checkComponent();
	void setDefaultPath();
	void creatEnvironmentVariable();
	void setDefaultScripts();
	void save();
};
