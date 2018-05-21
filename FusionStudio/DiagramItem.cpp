/****************************************************************************
**
**
****************************************************************************/

#include "Diagramitem.h"
#include "Arrow.h"

#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPainter>

//! [0] 图元对象初始化
DiagramItem::DiagramItem(DiagramType diagramType, QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
	myDiagramType = diagramType;

	QPainterPath path;

	int a = 0;
	int b = 0;

	switch (myDiagramType) {
	case DataSource:
		path.moveTo(100, -25);
		path.arcTo(50, -25, 50, 50, 0, 90);
		path.arcTo(-50, -25, 50, 50, 90, 90);
		path.arcTo(-50, 25, 50, 50, 180, 90);
		path.arcTo(50, 25, 50, 50, 270, 90);
		//path.lineTo(200, 25);
		myPolygon = path.toFillPolygon();

		_image = new QPixmap("./Resources/BP_DataSource.png");
		setPixmap(_image->scaled(180, 90));
		break;
	case PoolingLayer:
		myPolygon << QPointF(0, 0) << QPointF(300, 0)
			<< QPointF(300, 150) << QPointF(0, 150) << QPointF(0, 0);

		_image = new QPixmap("./Resources/BP_PoolingLayer.png");
		setPixmap(_image->scaled(180, 90));
		/*a = (_image->logicalDpiX()) ;
		b = (_image->logicalDpiY()) ;
		myPolygon << QPointF(0, 0) << QPointF(a, 0)
		<< QPointF(a, b*(1)) << QPointF(0, b*(1)) << QPointF(0, 0);*/
		break;
	case InputLayer:
		myPolygon << QPointF(-100, -100) << QPointF(100, -100)
			<< QPointF(100, 100) << QPointF(-100, 100)
			<< QPointF(-100, -100);
		_image = new QPixmap("./Resources/BP_DataLayer.png");
		setPixmap(_image->scaled(180, 90));
		break;
	case ConvLayer:
		_image = new QPixmap("./Resources/BP_ConvLayer.png");
		setPixmap(_image->scaled(180, 90));
		break;
	default:
		myPolygon << QPointF(-120, -80) << QPointF(-70, 80)
			<< QPointF(120, 80) << QPointF(70, -80)
			<< QPointF(-120, -80);
		break;
	}
	//setPolygon(myPolygon);

	setFlag(QGraphicsItem::ItemIsMovable, true);
	setFlag(QGraphicsItem::ItemIsSelectable, true);
	setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}
//! [0]

//! [1]
void DiagramItem::removeArrow(Arrow *arrow)
{
	int index = arrows.indexOf(arrow);

	if (index != -1)
		arrows.removeAt(index);
}
//! [1]

//! [2]
void DiagramItem::removeArrows()
{
	foreach(Arrow *arrow, arrows) {
		arrow->startItem()->removeArrow(arrow);
		arrow->endItem()->removeArrow(arrow);
		scene()->removeItem(arrow);
		delete arrow;
	}
}
//! [2]

//! [3]
void DiagramItem::addArrow(Arrow *arrow)
{
	arrows.append(arrow);
}
//! [3]

//! [4]
QPixmap DiagramItem::image() const
{
	QPixmap pixmap(250, 250);
	pixmap = *_image;
	QPainter painter(&pixmap);
	painter.setPen(QPen(Qt::black, 8));
	painter.translate(125, 125);
	return pixmap;
}
//! [4]

//! [6]
QVariant DiagramItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
	if (change == QGraphicsItem::ItemPositionChange) {
		foreach(Arrow *arrow, arrows) {
			arrow->updatePosition();
		}
	}

	return value;
}
//! [6]
