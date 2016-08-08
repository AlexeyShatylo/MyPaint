#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), m_scene(nullptr), m_view(nullptr), m_color(0,0,0), m_widthSelector(nullptr)
{
    ui->setupUi(this);

    m_scene = new Scene(new Rectangle, this);
    m_view = new QGraphicsView(this);
    m_widthSelector = new QSpinBox();

    m_widthSelector->setValue(1);
    m_widthSelector->setRange(1,40);
    ui->toolBar->addWidget(m_widthSelector);
    m_scene->setSceneRect(0, 0, MainWindow::width(), MainWindow::height());
    m_view->setScene(m_scene);
    setCentralWidget(m_view);
    connect(m_widthSelector, SIGNAL(valueChanged(int)), this, SLOT(on_widthChanged(int))); // connection for notification if user sets new line width and set new width to next shape
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    m_scene->setSceneRect(0,0, MainWindow::width(), MainWindow::height());
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_actionCreateLine_triggered()
{
    m_scene->SetFigure(line);
}

void MainWindow::on_actionCreateRectangle_triggered()
{
    m_scene->SetFigure(rectangle);
}

void MainWindow::on_actionCreateEllipse_triggered()
{
    m_scene->SetFigure(ellips);
}

void MainWindow::on_actionColorSelection_triggered()
{
    m_color = QColorDialog::getColor(Qt::white, this);
    m_scene->SetColor(m_color);
}

void MainWindow::on_actionClearScreen_triggered()
{
    m_scene->clear();
    m_scene->clearShapelist();
    m_scene->update(0, 0, MainWindow::width(), MainWindow::height());
}

void MainWindow::on_widthChanged(int value)
{
    if(m_lineWidth != value) {
        m_lineWidth = value;
        m_scene->SetWidth(m_lineWidth);
    }

}
void MainWindow::on_actionRedo_triggered()
{
    m_scene->Redo();
    m_scene->update(0, 0, MainWindow::width(), MainWindow::height());
}
void MainWindow::on_actionUndo_triggered() {
    m_scene->Undo();
    m_scene->update(0, 0, MainWindow::width(), MainWindow::height());
}


