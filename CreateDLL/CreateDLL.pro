#-------------------------------------------------
#
# Project created by QtCreator 2015-08-28T20:10:31
#
#-------------------------------------------------

QT       -= gui

TARGET = CreateDLL
TEMPLATE = lib

DEFINES += CREATEDLL_LIBRARY

SOURCES += createdll.cpp

HEADERS += createdll.h\
        createdll_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
