INCLUDEPATH += ../src
QT += testlib
SOURCES += ../src/clients.cpp \
    testclient.cpp
TEMPLATE = app
TARGET = tests
INCLUDEPATH += .

# Input
HEADERS += \
    testclient.h
SOURCES +=
