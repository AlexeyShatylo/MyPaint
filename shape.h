#ifndef SHAPE_H
#define SHAPE_H
#include <QPainter>
#include <QColor>
#include <QGraphicsItem>

class Shape : public QObject, public QGraphicsItem /*Base pure virtual class for all shapes*/
{
    Q_OBJECT
public:
    Shape(QObject *parent = 0);
    QRectF boundingRect() const;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) = 0; // pure virtual function

    void setSecondX(float sX);
    void setSecondY(float sY);
    void setColor(QColor value);
    void setWidth(int width);
    void setPen(QColor color, int width);

    float getFirstX() const;
    float getFirstY() const;
    float getSecondX() const;
    float getSecondY() const;
    QPen getPen();

private:
    float m_firstX;     //
    float m_firstY;     //shape
    float m_secondX;    //coords
    float m_secondY;    //

    QColor m_color;     // shape color
    int m_width;        // shape width
    QPen m_pen;
    enum Coord {firstCoord = 1, secondCoord};
};

#endif // SHAPE_H
