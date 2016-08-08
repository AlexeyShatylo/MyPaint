#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include "shape.h"
enum Mode {isDraw = 1, isScale};

enum Shapes {line = 1, rectangle, ellips};

class Scene : public QGraphicsScene //this class is a main class where we will draw all shapes
{
    Q_OBJECT
public:
    Scene(Shape* item, QObject *parent = 0);
private:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
private:
    Shape* m_item;
    int m_shapeName;
    Mode m_mode;
    float m_startCoordSceneX;
    float m_startCoordSceneY;
    float m_setScreenPosX;
    float m_setScreenPosY;
    QColor m_color;             // line color
    int m_width;                // line width
    QList<Shape*> m_shapeList;  // container for containing shapes
    int m_level;                // variable that contains the number of keystrokes button redo
    enum{vScale = 2};
public:
    void SetFigure(int idFigure);
    void SetColor(QColor color);
    void SetWidth(int width);
    void Redo();                // Undo figure
    void Undo();                // Redo figure
    void clearShapelist();
};

#endif // SCENE_H
