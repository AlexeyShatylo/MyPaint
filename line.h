#ifndef LINE_H
#define LINE_H
#include "shape.h"

class Line : public Shape
{
public:
    Line(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // LINE_H
