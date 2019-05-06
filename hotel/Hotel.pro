#-------------------------------------------------
#
# Project created by QtCreator 2019-04-04T13:06:20
#
#-------------------------------------------------

QT       += core gui widgets
QT       +=sql
TARGET = Hotel
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        hotel.cpp \
    mainwindow.cpp \
    rebook.cpp \
    registart.cpp \
    transroom.cpp \
    checkout.cpp \
    database.cpp \
    modifypaw.cpp \
    enrolui.cpp


HEADERS += \
        hotel.h \
    mainwindow.h \
    rebook.h \
    registart.h \
    transroom.h \
    checkout.h \
    database.h \
    modifypaw.h \
    enrolui.h


FORMS += \
        hotel.ui \
    mainwindow.ui \
    rebook.ui \
    registart.ui \
    transroom.ui \
    checkout.ui \
    modifypaw.ui \
    enrolui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
