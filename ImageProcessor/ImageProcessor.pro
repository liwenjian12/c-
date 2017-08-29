#-------------------------------------------------
#
# Project created by QtCreator 2016-12-17T14:41:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageProcessor
TEMPLATE = app


SOURCES += main.cpp\
        imgprocessor.cpp \
    showwidget.cpp

HEADERS  += imgprocessor.h \
    showwidget.h
qtHaveModule(printsupport): QT += printsupport
qtHaveModule(printdialogsupport): QT += printdialogsupport
