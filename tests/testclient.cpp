#include "testclient.h"
#include <fstream>
#include <cstdlib>

Clients client;

void TestClient::getName()
{
    Clients client;
    for (int i = 0; i < 10;i++)
    {
        cout  << client.createClientName() << "\n";
        QVERIFY(1 == 1);
    }
}
void TestClient::addClientUser()
{

//    QFETCH(QString, name_row);
    QFETCH(QString, identifier);
    QFETCH(QString, client_name);
    QFETCH(QString, user);
    QFETCH(QString, result);

    if (client.add(identifier.toInt(), client_name.toStdString(), user.toStdString()))
       QCOMPARE(QString("true"), result);
    else
        QCOMPARE(QString("false"), result);
}

void TestClient::addClientUser_data()
{
    QTest::addColumn<QString>("identifier");
    QTest::addColumn<QString>("client_name");
    QTest::addColumn<QString>("user");
    QTest::addColumn<QString>("result");


    char    data_identifier[255],
            identifier[255],
            client_name[255],
            user[255],
            result[255];

    ifstream file ("client_user.csv");
    while (file.good() && !file.eof())
    {
       file.getline(data_identifier, 255, ',');
       file.getline(identifier,255,  ',');
       file.getline(client_name, 255, ',');
       file.getline(user, 255, ',');
       file.getline(result, 255);
cout << data_identifier << "#" << identifier << "#" << client_name << "#" << user << "#" << result << "\n";
       if (strlen(data_identifier) > 0)
           QTest::newRow(data_identifier) << QString(identifier) << QString(client_name) << QString(user) << QString(result);

    }
    file.close();
}
QTEST_MAIN(TestClient)
