#include "testclient.h"

void TestClient::getName()
{
    Clients client;
    for (int i = 0; i < 10;i++)
    {
        cout  << client.createClientName() << "\n";
        QVERIFY(1 == 1);
    }
}

QTEST_MAIN(TestClient)
