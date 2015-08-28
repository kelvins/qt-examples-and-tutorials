#-------------------------------------------------
#
# Project created by QtCreator 2015-08-28T20:32:58
#
#-------------------------------------------------

QT       -= gui

TARGET = StaticLib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += staticlib.cpp

HEADERS += staticlib.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
