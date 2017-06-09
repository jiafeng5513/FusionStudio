#include "DiagramScene.h"
#include "Arrow.h"

#include <QTextCursor>
#include <QGraphicsSceneMouseEvent>
#include <QAction>
#include <QMenu>
//! [0]构造
DiagramScene::DiagramScene(QObject *parent) : QGraphicsScene(parent)
{
	myMode = MoveItem;
	myItemType = DiagramItem::InputLayer;
	line = 0;
	//textItem = 0;
	myItemColor = Qt::white;
	myTextColor = Qt::black;
	myLineColor = Qt::black;
}
//! [0]

//! [1]设置线颜色
void DiagramScene::setLineColor(const QColor &color)
{
	myLineColor = color;
	if (isItemChange(Arrow::Type)) {
		Arrow *item = qgraphicsitem_cast<Arrow *>(selectedItems().first());
		item->setColor(myLineColor);
		update();
	}
}
//! [1]

////! [2]设置文字颜色
//void DiagramScene::setTextColor(const QColor &color)
//{
//	myTextColor = color;
//	if (isItemChange(DiagramTextItem::Type)) {
//		DiagramTextItem *item = qgraphicsitem_cast<DiagramTextItem *>(selectedItems().first());
//		item->setDefaultTextColor(myTextColor);
//	}
//}
////! [2]

//! [3]设置图元颜色
void DiagramScene::setItemColor(const QColor &color)
{
	myItemColor = color;
	if (isItemChange(DiagramItem::Type)) {
		DiagramItem *item = qgraphicsitem_cast<DiagramItem *>(selectedItems().first());
		//item->setBrush(myItemColor);
	}
}
//! [3]

////! [4]设置字体
//void DiagramScene::setFont(const QFont &font)
//{
//	myFont = font;
//
//	if (isItemChange(DiagramTextItem::Type)) {
//		QGraphicsTextItem *item = qgraphicsitem_cast<DiagramTextItem *>(selectedItems().first());
//		//At this point the selection can change so the first selected item might not be a DiagramTextItem
//		if (item)
//			item->setFont(myFont);
//	}
//}
////! [4]

//槽函数:设置模式?
void DiagramScene::setMode(Mode mode)
{
	myMode = mode;
}

//槽函数:设置图元的类型?
void DiagramScene::setItemType(DiagramItem::DiagramType type)
{
	myItemType = type;
}

////! [5]槽函数:绘图区域失去焦点
//void DiagramScene::editorLostFocus(DiagramTextItem *item)
//{
//	QTextCursor cursor = item->textCursor();
//	cursor.clearSelection();
//	item->setTextCursor(cursor);
//
//	if (item->toPlainText().isEmpty()) {
//		removeItem(item);
//		item->deleteLater();
//	}
//}
////! [5]

//! [6]重载:鼠标左键按下事件(画图形,划线,插入文本框)
void DiagramScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	if (mouseEvent->button() != Qt::LeftButton) {
		qDebug("Pos:(%.2f,%.2f)", mouseEvent->scenePos().rx(), mouseEvent->scenePos().ry());
		return;
	}
	DiagramItem *item;
	switch (myMode) {
	case InsertItem:
		item = new DiagramItem(myItemType);
		//item->setBrush(myItemColor);
		addItem(item);
		item->setPos(mouseEvent->scenePos());
		emit itemInserted(item);//已经把图元插入到了指定位置
		break;
		//! [6] //! [7]
	case InsertLine:
		line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),
			mouseEvent->scenePos()));
		line->setPen(QPen(Qt::black, 2));
		addItem(line);
		break;
		//! [7] //! [8]
	case InsertText:
		//textItem = new DiagramTextItem();
		//textItem->setFont(myFont);
		//textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
		//textItem->setZValue(1000.0);
		//connect(textItem, SIGNAL(lostFocus(DiagramTextItem*)),
		//	this, SLOT(editorLostFocus(DiagramTextItem*)));
		//connect(textItem, SIGNAL(selectedChange(QGraphicsItem*)),
		//	this, SIGNAL(itemSelected(QGraphicsItem*)));
		//addItem(textItem);
		//textItem->setDefaultTextColor(myTextColor);
		//textItem->setPos(mouseEvent->scenePos());
		//emit textInserted(textItem);
		////! [8] //! [9]
	default:
		;
	}
	QGraphicsScene::mousePressEvent(mouseEvent);
}
//! [9]

//! [10]重载:鼠标移动事件
void DiagramScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	if (myMode == InsertLine && line != 0) {
		QLineF newLine(line->line().p1(), mouseEvent->scenePos());
		line->setLine(newLine);
	}
	else if (myMode == MoveItem) {
		QGraphicsScene::mouseMoveEvent(mouseEvent);
	}
}
//! [10]

//! [11]重载:鼠标释放事件
void DiagramScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	if (line != 0 && myMode == InsertLine) {
		QList<QGraphicsItem *> startItems = items(line->line().p1());
		if (startItems.count() && startItems.first() == line)
			startItems.removeFirst();
		QList<QGraphicsItem *> endItems = items(line->line().p2());
		if (endItems.count() && endItems.first() == line)
			endItems.removeFirst();

		removeItem(line);
		delete line;
		//! [11] //! [12]

		if (startItems.count() > 0 && endItems.count() > 0 &&
			startItems.first()->type() == DiagramItem::Type &&
			endItems.first()->type() == DiagramItem::Type &&
			startItems.first() != endItems.first()) {
			DiagramItem *startItem = qgraphicsitem_cast<DiagramItem *>(startItems.first());
			DiagramItem *endItem = qgraphicsitem_cast<DiagramItem *>(endItems.first());
			Arrow *arrow = new Arrow(startItem, endItem);
			arrow->setColor(myLineColor);
			startItem->addArrow(arrow);
			endItem->addArrow(arrow);
			arrow->setZValue(-1000.0);
			addItem(arrow);
			arrow->updatePosition();
		}
	}
	//! [12] //! [13]
	line = 0;
	QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

//! [13]

//! [14]选中的图元发生变化
bool DiagramScene::isItemChange(int type)
{
	foreach(QGraphicsItem *item, selectedItems()) {
		if (item->type() == type)
			return true;
	}
	return false;
}
//! [14]
