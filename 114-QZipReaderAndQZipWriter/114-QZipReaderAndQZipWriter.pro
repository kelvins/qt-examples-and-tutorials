#-------------------------------------------------
#
# Project created by QtCreator 2015-09-04T18:16:43
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = 114-QZipReaderAndQZipWriter
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += $$PWD/zlib
ZLIBDIR = "/home/kelvin/QtProjects/Youtube\ Tutorials/114-QZipReaderAndQZipWriter/zlib"

unix{
    LIBS += -L $${ZLIBDIR} -lz
}

#win32{
#    LIBS += L$$PWD/zlib/Windows -lzdll
#}

SOURCES += main.cpp \
    zip.cpp

HEADERS += \
    zipwriter.h \
    zipreader.h \
    zlib.h \
    zconf.h
