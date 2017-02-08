#include "testclient.h"
#include <fstream>

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
//JRM AQUI ESTOY{
    Clients client;

    QFETCH(QString, string);
    QFETCH(QString, result);

    QCOMPARE(string.toUpper(), result);
}

void TestClient::addClientUser_data()
{
    QTest::addColumn<string>("string");
    QTest::addColumn<int>("identifier");
    QTest::addColumn<string>("client");
    QTest::addColumn<string>("user");

    char    data_identifier[255],
            identifier[255],
            client[255],
            user[255],
            rubbish[255];

    ifstream file ( "client_user.csv" );
    while ( file.good() )
    {
       file.getline(data_identifier, ',');
       file.getline(identifier, ',');
       file.getline(client, ',');
       file.getline(user, ',');
       file.getline(rubbish, '\n'); // discard end of line

       QTest::newRow(data_identifier) << identifier << client << user;

    }
    file.close();
}
QTEST_MAIN(TestClient)
