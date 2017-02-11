#include <QtNetwork>

#include <stdlib.h>
#include <iostream>

#include "server.h"
#include "connection.h"


using namespace std;

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
    if (!listen()) {
        cout <<"Unable to start the server: " << errorString().toStdString() << std::flush;
        close();
        return;
    }

    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    cout << "The server is running on IP port:" << ipAddress.toStdString() <<" " << serverPort()<< std::flush;


}
void Server::incomingConnection(qintptr socketDescriptor)
{
    Connection *thread = new Connection(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
