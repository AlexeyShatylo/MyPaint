#include "shape.h"

Shape::Shape(QObject *parent) : m_firstX(firstCoord), m_firstY(firstCoord),
    m_secondX(secondCoord), m_secondY(secondCoord), QObject(parent), QGraphicsItem()
{

}

QRectF Shape::boundingRect() const
{
    return QRectF(getFirstX(), getFirstY(), getSecondX(), getSecondY());
}

void Shape::setSecondX(float sX)
{
    m_secondX = sX;
}

void Shape::setSecondY(float sY)
{
    m_secondY = sY;
}

float Shape::getFirstX() const
{
    return m_firstX;
}

float Shape::getFirstY() const
{
    return m_firstY;
}

float Shape::getSecondX() const
{
    return m_secondX;
}

float Shape::getSecondY() const
{
    return m_secondY;
}

QPen Shape::getPen()
{
    return m_pen;
}

void Shape::setPen(QColor color, int width)
{
    m_pen.setColor(color);
    m_pen.setWidth(width);
}

void Shape::setWidth(int width)
{
    m_width = width;
}

void Shape::setColor(QColor value)
{
    m_color = value;
}

