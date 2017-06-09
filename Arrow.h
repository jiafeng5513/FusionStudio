#pragma once

#ifndef ARROW_H
#define ARROW_H

#include <QGraphicsLineItem>

#include "Diagramitem.h"

QT_BEGIN_NAMESPACE
class QGraphicsPolygonItem;
class QGraphicsLineItem;
class QGraphicsScene;
class QRectF;
class QGraphicsSceneMouseEvent;
class QPainterPath;
QT_END_NAMESPACE

//! [0]
class Arrow : public QGraphicsLineItem
{
public:
	enum { Type = UserType + 4 };

	Arrow(DiagramItem *startItem, DiagramItem *endItem,
		QGraphicsItem *parent = 0);

	int type() const override { return Type; }
	QRectF boundingRect() const override;
	QPainterPath shape() const override;
	void setColor(const QColor &color) { myColor = color; }
	DiagramItem *startItem() const { return myStartItem; }
	DiagramItem *endItem() const { return myEndItem; }

	void updatePosition();

protected:
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

private:
	DiagramItem *myStartItem;
	DiagramItem *myEndItem;
	QColor myColor;
	QPolygonF arrowHead;
};
//! [0]

#endif // ARROW_H
