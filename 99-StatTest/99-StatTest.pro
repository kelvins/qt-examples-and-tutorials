#-------------------------------------------------
#
# Project created by QtCreator 2015-08-28T20:34:43
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 99-StatTest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

INCLUDEPATH += "/home/kelvin/QtProjects/Youtube\ Tutorials/StaticLib"
LIBS += "/home/kelvin/QtProjects/Youtube\ Tutorials/build-StaticLib-Desktop-Debug/libStaticLib.a"

HEADERS += \
    ../StaticLib/staticlib.h
