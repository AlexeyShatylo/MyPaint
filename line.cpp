#include "line.h"

Line::Line(QObject *parent): Shape(parent)
{

}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QLine line(getFirstX(), getFirstY(), getSecondX(), getSecondY());
    painter->setPen(getPen());
    painter->drawLine(line);
}
