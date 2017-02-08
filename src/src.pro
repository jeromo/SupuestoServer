include(../defaults.pri)
CONFIG -= qt
#QT += core
#QT -= gui

CONFIG += c++11
TARGET = server
TEMPLATE = lib

SOURCES += myclass.cpp \
    clients.cpp
HEADERS += myclass.h \
    clients.h
