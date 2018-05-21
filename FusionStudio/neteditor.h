#pragma once

#include <QMainWindow>
#include <QAction>
#include <QToolBox>

#include "ui_neteditor.h"

#include "editor.h"
#include "DiagramScene.h"
class NetEditor : public QMainWindow
{
	Q_OBJECT

public:
	///外部操作
	NetEditor(QWidget *parent = Q_NULLPTR);
	NetEditor(QString FileName,QWidget *parent = Q_NULLPTR);
	~NetEditor();

private:
	///内部变量
	Ui::NetEditor ui;
	Editor *MyTextEditor;//文本编辑器

	DiagramScene *scene;//绘图区域
	QButtonGroup *buttonGroup;
	QButtonGroup *backgroundButtonGroup;
	QGraphicsView *view;
	QButtonGroup *pointerTypeGroup;
	QComboBox *sceneScaleCombo;
	QToolBar *pointerToolbar;
	QAction*deleteAction;//删除当前图元
	QAction*toFrontAction;
	QAction*sendBackAction;
	QToolBox *toolBox;//工具箱
private:
	///内部操作
	void createToolBox();
	void createToolbars();
	QWidget *createCellWidget(const QString &text, DiagramItem::DiagramType type);//创建图元笔刷按钮
	QWidget *createBackgroundCellWidget(const QString &text, const QString &image);//创建背景切换按钮
private slots:
	///槽函数
	void itemInserted(DiagramItem *item);//插入图元
	void itemSelected(QGraphicsItem *item);
	void bringToFront();
	void sendToBack();
	void deleteItem();
	void pointerGroupClicked(int id);//鼠标指针
	void sceneScaleChanged(const QString &scale);//缩放
	void backgroundButtonGroupClicked(QAbstractButton *button);//点击换背景
	void buttonGroupClicked(int id);//选中图元,点击画图
};
