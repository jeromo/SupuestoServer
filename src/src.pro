include(../defaults.pri)

QT += core
QT += network
QT -= gui

CONFIG += c++11
TARGET = Server
TEMPLATE = app

SOURCES += main.cpp \
    clients.cpp \
    server.cpp \
    connection.cpp \
    finish.cpp
HEADERS += clients.h \
    server.h \
    connection.h \
    finish.h
