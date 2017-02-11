#include "connection.h"
#include "clients.h"

#include <QtNetwork>
#include <iostream>
#include "connection.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


Connection::Connection(int socketDescriptor, QObject *parent)
    : QThread(parent), socketDescriptor(socketDescriptor)
{
}

void Connection::run()
{
    QTcpSocket socket;

    if (!socket.setSocketDescriptor(socketDescriptor)) {
        std::cout << "EN setSocketDescriptor " << socket.errorString().toStdString() <<std::endl << std::flush;

        return;
    }

    Clients *clients = Clients::getInstance();

    string client_name = clients->createClientName();
    while (socket.state() == QAbstractSocket::ConnectedState){
        string data = read(&socket).toStdString();
        if (socket.state() == QAbstractSocket::ConnectedState)
        {

            size_t position = data.find(":");
            string s_identifier = data.substr(0, position);
            int identifier = std::stoi(s_identifier);
            if (clients->add(identifier, client_name, data.substr(position+1)))
            {
                write(&socket, QString("OK"));
            }
            else
            {
                write(&socket, QString("ERR"));
            }
            clients->setLastTime(std::time(nullptr));
        }
    }

    exit();
}

QString Connection::read(QTcpSocket *socket)
{
    if (socket ->state() != QAbstractSocket::ConnectedState)
    {
        exit();
    }

    QString data;
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_4_0);


    do {
        if (!socket->waitForReadyRead(Timeout)) {
            std::cout << "En waitForReadyRead " << socket->errorString().toStdString() <<std::endl << std::flush;
            exit(0);

            break;
        }

        in.startTransaction();
        in >> data;

    } while (!in.commitTransaction());

    return data;
}

void Connection::write(QTcpSocket *socket, QString data)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << data;

    socket->write(block);
}
