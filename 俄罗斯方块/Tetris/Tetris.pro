#-------------------------------------------------
#
# Project created by QtCreator 2016-09-02T10:48:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tetris
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controlpanel.cpp \
    Item.cpp

HEADERS  += mainwindow.h \
    controlpanel.h \
    Item.h

FORMS    += mainwindow.ui

RESOURCES += \
    rc.qrc

RC_FILE = icon.rc 