#-------------------------------------------------
#
# Project created by QtCreator 2014-12-14T16:37:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sapper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    engine.cpp \
    presenter.cpp \
    minefield.cpp \
    square.cpp


HEADERS  += mainwindow.h \
    engine.h \
    presenter.h \
    minefield.h \
    square.h

FORMS    += mainwindow.ui

INCLUDEPATH += .
