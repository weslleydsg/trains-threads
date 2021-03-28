QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Train
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    train.cpp

HEADERS  += mainwindow.h \
    train.h

FORMS    += mainwindow.ui
