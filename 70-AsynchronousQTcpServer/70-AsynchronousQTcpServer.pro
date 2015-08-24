#-------------------------------------------------
#
# Project created by QtCreator 2015-08-22T11:24:35
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = 70-AsynchronousQTcpServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myserver.cpp \
    myclient.cpp \
    mytask.cpp

HEADERS += \
    myserver.h \
    myclient.h \
    mytask.h
