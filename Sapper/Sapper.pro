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
    engineimpl.cpp \
    presenter.cpp \
    engine.cpp

HEADERS  += mainwindow.h \
    engine.h \
    engineimpl.h \
    presenter.h

FORMS    += mainwindow.ui
