#pragma once

#include <QWidget>
#include "ui_trainingsetter.h"
#include <QProcess>
#include <QString>

class TrainingSetter : public QWidget
{
	Q_OBJECT

public:
	TrainingSetter(QString coredir, QProcess *addprocess,QWidget *parent = Q_NULLPTR);
	~TrainingSetter();

private:
	///内部属性
	Ui::TrainingSetter ui;
	QString CoreDir;//保存核心目录
	QProcess *_AdditionalProcess;//指向主界面类中已经重定向的那个线程,浅拷贝,构造赋值
private:
	///内部操作
public slots :
	///槽函数
	void BrowseSolver();//浏览训练配置文件
	void BrowseSnapPath();
	void BrowseNet();
	void ReadSolver();
	void SaveSolver();
	void ExecuteTraining();
	void policyChange();//衰减策略变更
};
