#-------------------------------------------------
#
# Project created by QtCreator 2015-08-22T10:59:08
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = 69-QTcpServer-Using-QThreadPool
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myserver.cpp \
    myrunnable.cpp

HEADERS += \
    myserver.h \
    myrunnable.h
