#-------------------------------------------------
#
# Project created by QtCreator 2018-09-12T13:59:09
#
#-------------------------------------------------
QT       +=network
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Day1_task
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    joint.cpp \
    snake.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    joint.h \
    snake.h \
    client.h

FORMS    += mainwindow.ui
