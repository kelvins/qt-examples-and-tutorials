#-------------------------------------------------
#
# Project created by QtCreator 2015-08-21T17:35:29
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = 68-MultiServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myserver.cpp \
    mythread.cpp

HEADERS += \
    myserver.h \
    mythread.h
