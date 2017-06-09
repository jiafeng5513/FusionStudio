#include "Arrow.h"
#include <math.h>

#include <QPen>
#include <QPainter>

const qreal Pi = 3.14;

//! [0]
Arrow::Arrow(DiagramItem *startItem, DiagramItem *endItem, QGraphicsItem *parent)
	: QGraphicsLineItem(parent)
{
	myStartItem = startItem;
	myEndItem = endItem;
	setFlag(QGraphicsItem::ItemIsSelectable, true);
	myColor = Qt::black;
	setPen(QPen(myColor, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
}
//! [0]

//! [1]
QRectF Arrow::boundingRect() const
{
	qreal extra = (pen().width() + 20) / 2.0;

	return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
		line().p2().y() - line().p1().y()))
		.normalized()
		.adjusted(-extra, -extra, extra, extra);
}
//! [1]

//! [2]
QPainterPath Arrow::shape() const
{
	QPainterPath path = QGraphicsLineItem::shape();
	path.addPolygon(arrowHead);
	return path;
}
//! [2]

//! [3]
void Arrow::updatePosition()
{
	QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
	setLine(line);

}
//! [3]

//! [4]
void Arrow::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
	QWidget *)
{
	////如果起始图元与结束图元有碰撞,则不画线
	if (myStartItem->collidesWithItem(myEndItem))
		return;
	//if (isSelected()) {
	//	painter->setPen(QPen(myColor, 1, Qt::DashLine));
	//	QLineF myLine = line();
	//	myLine.translate(0, 4.0);
	//	painter->drawLine(myLine);
	//	myLine.translate(0, -8.0);
	//	painter->drawLine(myLine);
	//}

	QPen pen;
	//pen.setColor(Qt::black);
	//pen.setWidth(2);
	//pen.setStyle(Qt::DashDotLine);
	setPen(QPen(Qt::black, 2, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin));
	painter->setPen(pen);
	painter->setRenderHint(QPainter::Antialiasing, true);//抗锯齿开启
														 /*==========================================================*/
														 //计算曲线的起止点
	QPointF start_pos(myStartItem->pos().x() + 170, myStartItem->pos().y() + 15);
	QPointF end_pos(myEndItem->pos().x() + 10, myEndItem->pos().y() + 15);

	//开始绘制曲线
	QPainterPath path(start_pos);//曲线的起点
								 //灵敏度参数
	float theta = 2000;
	//变距因数
	float m = theta / ((abs(end_pos.y() - start_pos.y()) + 1)*((abs(end_pos.x() - start_pos.x()) + 1)));
	float m1 = (m < 0 ? 0 : m);
	float xxxx = end_pos.y() - start_pos.y();
	m1 = (end_pos.y() - start_pos.y() == 0 ? 0 : m);
	if (end_pos.x() - start_pos.x() >= 50) {//滤掉无穷间断点
		m1 = 0;
	}
	//通过移动控制点实现曲线变距
	float xk1 = (start_pos.x() + end_pos.x()) / 2 + m1;
	float xk2 = (start_pos.x() + end_pos.x()) / 2 - m1;

	QPoint c1(xk1, start_pos.y() + m1 / 1000);
	QPoint c2(xk2, end_pos.y() - m1 / 1000);


	path.cubicTo(c1, c2, end_pos);//两个控制点一个结束点
								  //这个函数会导致残影
								  /*==========================================================*/

	painter->drawPath(path);

}
//! [7]
