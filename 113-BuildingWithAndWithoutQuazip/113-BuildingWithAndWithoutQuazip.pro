#-------------------------------------------------
#
# Project created by QtCreator 2015-09-04T17:42:01
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 113-BuildingWithAndWithoutQuazip
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# Set variables
QUAZIPCODEDIR = "/home/kelvin/ZipLib/quazip-0.7.1/quazip"
ZLIBCODEDIR = "/home/kelvin/ZipLib/Libs"

# include the compiled code
unix
{
    LIBS += -L $${ZLIBCODEDIR} -lz
}

#include files
INCLUDEPATH += $${QUAZIPCODEDIR}
HEADERS += $${QUAZIPCODEDIR}/*.h # Include all .h files in the QUAZIPCODEDIR PATH
SOURCES += $${QUAZIPCODEDIR}/*.cpp
SOURCES += $${QUAZIPCODEDIR}/*.c

SOURCES += main.cpp
