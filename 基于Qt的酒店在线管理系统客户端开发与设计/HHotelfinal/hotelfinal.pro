#-------------------------------------------------
#
# Project created by QtCreator 2017-12-22T10:13:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hotelfinal
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chgpwd.cpp \
    login.cpp \
    change_room_price.cpp \
    add_food_info.cpp \
    delete_food_info.cpp \
    change_food_info.cpp \
    select_food_info.cpp \
    food_consume_info.cpp \
    zhu_ce.cpp \
    change_bash_info.cpp

HEADERS  += mainwindow.h \
    chgpwd.h \
    login.h \
    change_room_price.h \
    add_food_info.h \
    delete_food_info.h \
    change_food_info.h \
    select_food_info.h \
    food_consume_info.h \
    zhu_ce.h \
    change_bash_info.h \
    databaseconnection.h

FORMS    += mainwindow.ui \
    chgpwd.ui \
    login.ui \
    change_room_price.ui \
    add_food_info.ui \
    delete_food_info.ui \
    change_food_info.ui \
    select_food_info.ui \
    food_consume_info.ui \
    zhu_ce.ui \
    change_bash_info.ui

QT      += sql

RESOURCES += \
    res.qrc
