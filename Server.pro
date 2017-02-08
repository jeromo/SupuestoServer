#QT += core
#QT -= gui

#CONFIG += c++11

#TARGET = Server
#CONFIG += console
#CONFIG -= app_bundle

#TEMPLATE = app

#SOURCES += main.cpp

TEMPLATE = subdirs
CONFIG+=ordered
SUBDIRS = \
    src \
    app \
    tests
app.depends = src
tests.depends = src
