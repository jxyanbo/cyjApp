#-------------------------------------------------
#
# Project created by QtCreator 2017-09-05T10:05:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cyjApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    CAN_SJA1000.cpp \
    NAV_Control.cpp \
    NetAccess.cpp

HEADERS  += mainwindow.h \
    CAN_SJA1000.h \
    NAV_Control.h \
    NetAccess.h

FORMS    += mainwindow.ui