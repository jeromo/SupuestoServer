#ifndef TESTCLIENT
#define TESTCLIENT

#include <QtTest/QtTest>
#include "clients.h"
class TestClient: public QObject
{
    Q_OBJECT
private slots:
    void getName();
    void addClientUser();
    void addClientUser_data();
};

#endif // TESTCLIENT
