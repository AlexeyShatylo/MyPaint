#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QAction>
#include <QResizeEvent>
#include <QColorDialog>
#include <QSpinBox>
#include "scene.h"
#include "rectangle.h"
#include "line.h"
#include <QList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent* event);

private:
    Ui::MainWindow *ui;

    Scene* m_scene;
    QGraphicsView* m_view;
    QColor m_color;
    QSpinBox* m_widthSelector;

    int m_lineWidth;

private slots:
    void on_actionCreateLine_triggered();
    void on_actionCreateRectangle_triggered();
    void on_actionCreateEllipse_triggered();
    void on_actionColorSelection_triggered();
    void on_actionClearScreen_triggered();
    void on_actionRedo_triggered();
    void on_actionUndo_triggered();
    void on_widthChanged(int value);
};

#endif // MAINWINDOW_H
