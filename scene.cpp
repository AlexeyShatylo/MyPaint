#include "scene.h"
#include "rectangle.h"
#include "ellipse.h"
#include "line.h"
#include <QDebug>
Scene::Scene(Shape *item, QObject *parent) : m_item(item), m_shapeName(1), m_mode(isDraw), QGraphicsScene(parent), m_width(1), m_level(0)
{

}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (((event->scenePos().x() >= m_setScreenPosX) && event->scenePos().x() <= m_setScreenPosX + vScale) &&
            ((event->scenePos().y() >= m_setScreenPosY) && event->scenePos().y() <= m_setScreenPosY + vScale)) {
        m_mode = isScale;
    }
    else
    {
        m_mode = isDraw;
    }
    if (m_mode == isDraw) {
        switch (m_shapeName)
        {
        case line:
            m_item = new Line(this);
            break;
        case rectangle:
            m_item = new Rectangle(this);
            break;
        case ellips:
            m_item = new Ellipse(this);
            break;
        default:
            break;
        }
        m_item->setPos(event->scenePos());
        m_item->setPen(m_color,m_width);
        m_startCoordSceneX = event->scenePos().x();
        m_startCoordSceneY = event->scenePos().y();
        /*
         * if (m_level == 0) - if we dont use redo
         * esle{while(m_level != 0){...} - if we use redo and than we want to draw a new figure
         * we cleaning list from other item that we dont undo
         */
        if (m_level == 0) {
            m_shapeList.append(m_item);
            addItem(m_item);

        } else {
            while(m_level != 0) {
                m_shapeList.removeAt(m_shapeList.size() - m_level);
                m_level--;
            }
            m_shapeList.append(m_item);
            addItem(m_item);
        }
    }
}

void Scene::Redo() {
    if (!m_shapeList.isEmpty() && m_level < m_shapeList.size())  {
        m_level++;
        removeItem(m_shapeList.at(m_shapeList.size() - m_level));
    }
}

void Scene::Undo () {

    if (m_level !=0 && !m_shapeList.isEmpty() && m_level <= m_shapeList.size()) {
        addItem(m_shapeList.at(m_shapeList.size() - m_level));
        m_level--;
    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
    m_setScreenPosX = event->scenePos().x();
    m_setScreenPosY = event->scenePos().y();
    m_item->setSecondX(event->scenePos().x() - m_startCoordSceneX);
    m_item->setSecondY(event->scenePos().y() - m_startCoordSceneY);
    update(QRectF(0,0,width(), height()));
}

void Scene::clearShapelist() {
    while(!m_shapeList.empty()) {
        m_shapeList.pop_front();
    }
}

void Scene::SetWidth(int width)
{
    m_width = width;
}

void Scene::SetColor(QColor color)
{
    m_color = color;
}

void Scene::SetFigure(int idFigure)
{
    m_shapeName = idFigure;
}
