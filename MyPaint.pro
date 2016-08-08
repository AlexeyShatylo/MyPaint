#-------------------------------------------------
#
# Project created by QtCreator 2016-07-01T14:51:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyPaint
TEMPLATE = app


SOURCES += main.cpp\
    rectangle.cpp \
    scene.cpp \
    mainwindow.cpp \
    shape.cpp \
    ellipse.cpp \
    line.cpp

HEADERS  += \
    rectangle.h \
    scene.h \
    mainwindow.h \
    shape.h \
    ellipse.h \
    line.h

FORMS    += \
    mainwindow.ui

RESOURCES += \
    icons.qrc
