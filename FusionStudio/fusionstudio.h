#pragma once

#include <QtWidgets/QMainWindow>
#include "QProcess"
#include "ui_fusionstudio.h"
#include "Project.h"
#include "trainingsetter.h"
#include "convertmnist.h"
#include "convertcifar.h"
#include "convertimage.h"
#include "browsedatabase.h"
#include "preferences.h"
#include "myhighlighter.h"
#include "typedef.h"
#include "editor.h"
#include "homepage.h"
#include "neteditor.h"
#include "classification.h"
#include "featureexp.h"
#include "about.h"

/*
编程:天使微积分
创建日期:2017年1月4日13:18:08
重构:2017年2月19日13:52:02
    重构备注:与核心组件脱离,独立使用一个解决方案,以便于模块化编写
*/
class FusionStudio : public QMainWindow
{
	Q_OBJECT

public:
	FusionStudio(QWidget *parent = Q_NULLPTR);
	QProcess * p2;
	static void test();
private:
	///内部变量
	Ui::FusionStudioClass ui;
	void configureUI();
	QPoint PrePosition;
	//QMenu *TreeViewMenu = NULL;
	QMenu *TreeViewMenu_Empty = NULL;//文件树为空时的右键单击事件菜单
	QMenu *TreeViewMenu_File = NULL;//发生在文件节点上的右键单击事件菜单
	QMenu *TreeViewMenu_Path = NULL;//发生在文件夹节点上的右键单击事件菜单
	Project * m_project;
	Preferences *m_PreferencesManager;//首选项管理器,窗口关闭不能销毁
	QString CurrentTreeViewSelectedPath;//当前文件树视图中被选中的项目的绝对路径
private:
	///内部操作
	bool DelDir(const QString &path);
public slots:
	void start_read_output();//控制台标准输出重定向
	void Train();//测试控制台重定向功能
	void Refresh();//刷新文件树
	void ShowEditor();
	void on_treeView_customContextMenuRequested(QPoint pos);
	//文件树->右键菜单
	void newFile();//新建文件
	void newFolder();//新建文件夹
	void getAbsolutePath();//获取绝对路径
	void openInSystemResourceManager();//在系统资源管理器中打开
	void deleteFileOrPath();//删除路径或文件
	//菜单->文件
	void FolderCreater();
	void FolderUnfolder();
	void FolderCloser();
	//菜单->视图
	void changeVisible_Explorer();
	void changeVisible_Console();
	//菜单->工具
	void MnistConverter();
	void CifarConverter();
	void ImageConverter();
	void DatabaseBrowser();
	//菜单->设置
	void PreferencesSetter();//启动首选项管理器
							 //菜单->项目
	void WorkingDirScanner();//扫描工作目录
	//菜单->生成
	void DoClassification();//分类
	void DoFeaturesExp();//特征导出
	//菜单->帮助
	void ShowHome();
	void ShowAbout();
};
