include(../defaults.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
QT += core
QT -= gui

CONFIG += c++11

SOURCES += main.cpp

LIBS += -L../src -lserver
