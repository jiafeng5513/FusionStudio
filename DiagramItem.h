/****************************************************************************
重构:天使微积分
时间;2017年4月6日15:41:18
****************************************************************************/

#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QGraphicsPixmapItem>
#include <QList>

QT_BEGIN_NAMESPACE
class QPixmap;
class QGraphicsItem;
class QGraphicsScene;
class QTextEdit;
class QGraphicsSceneMouseEvent;
class QMenu;
class QGraphicsSceneContextMenuEvent;
class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QPolygonF;
QT_END_NAMESPACE

class Arrow;

//! [0]
class DiagramItem : public QGraphicsPixmapItem
{
public:
	enum { Type = UserType + 15 };
	enum DiagramType { InputLayer, Conditional, DataSource, Io, ConvLayer, PoolingLayer };

	DiagramItem(DiagramType diagramType, QGraphicsItem *parent = 0);

	void removeArrow(Arrow *arrow);
	void removeArrows();
	DiagramType diagramType() const { return myDiagramType; }
	QPolygonF polygon() const { return myPolygon; }
	void addArrow(Arrow *arrow);
	QPixmap image() const;
	int type() const override { return Type; }

protected:
	QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

private:
	DiagramType myDiagramType;
	QPolygonF myPolygon;
	QList<Arrow *> arrows;
	QPixmap * _image;//当前图元对象的基础图形
};
//! [0]

#endif // DIAGRAMITEM_H
