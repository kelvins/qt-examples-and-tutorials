#-------------------------------------------------
#
# Project created by QtCreator 2015-09-04T16:55:22
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 112-WorkingWithQuaZipAndZlib
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# Set variables
QUAZIPCODEDIR = "/home/kelvin/ZipLib/quazip-0.7.1/quazip"
#ZLIBCODEDIR = "/home/kelvin/ZipLib/zlib-1.2.8"
ZLIBCODEDIR = "/home/kelvin/ZipLib/Libs"

# include the compiled code
unix
{
    LIBS += -L $${ZLIBCODEDIR} -lz
}

#win32
#{
#    LIBS += -L $${ZLIBCODEDIR} -lzdll
#}

#include files
INCLUDEPATH += $${QUAZIPCODEDIR}
HEADERS += $${QUAZIPCODEDIR}/*.h # Include all .h files in the QUAZIPCODEDIR PATH

# Don't need
#SOURCES += $${QUAZIPCODEDIR}/*.cpp # Include all .cpp files in the QUAZIPCODEDIR PATH
#SOURCES += $${QUAZIPCODEDIR}/*.c # Include all .c files in the QUAZIPCODEDIR PATH

SOURCES += main.cpp
