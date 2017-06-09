#pragma once
#include "Diagramitem.h"

#include <QGraphicsScene>
#include <QAction>
/*************************************************************************
编程:天使微积分
时间:2017年4月7日15:34:15

日志:重载QGraphicsScene控价类,重写其中的鼠标响应方法,实现定点绘图等功能
**************************************************************************/

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QMenu;
class QPointF;
class QGraphicsLineItem;
class QFont;
class QGraphicsTextItem;
class QColor;
QT_END_NAMESPACE

//! [0]
class DiagramScene : public QGraphicsScene
{
	Q_OBJECT

public:
	enum Mode { InsertItem, InsertLine, InsertText, MoveItem };

	explicit DiagramScene(QObject *parent = 0);
	QFont font() const { return myFont; }
	QColor textColor() const { return myTextColor; }
	QColor itemColor() const { return myItemColor; }
	QColor lineColor() const { return myLineColor; }
	void setLineColor(const QColor &color);
	void setTextColor(const QColor &color);
	void setItemColor(const QColor &color);
	void setFont(const QFont &font);

	public slots:
	void setMode(Mode mode);
	void setItemType(DiagramItem::DiagramType type);
	//void editorLostFocus(DiagramTextItem *item);

signals:
	void itemInserted(DiagramItem *item);//插入了新的图元 
	void textInserted(QGraphicsTextItem *item);//插入了文字
	void itemSelected(QGraphicsItem *item);//选中了图元

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
private:
	///私有方法

private:
	///内部变量
	bool isItemChange(int type);

	DiagramItem::DiagramType myItemType;
	Mode myMode;
	bool leftButtonDown;
	QPointF startPoint;
	QGraphicsLineItem *line;
	QFont myFont;
	//DiagramTextItem *textItem;
	QColor myTextColor;
	QColor myItemColor;
	QColor myLineColor;
};
