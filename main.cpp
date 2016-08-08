#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* App = new MainWindow;
    App->show();

    return a.exec();
}
