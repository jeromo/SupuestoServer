#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QNetworkSession>

//! [0]
class Server : public QObject
{
    Q_OBJECT

public:
    explicit Server();

private slots:
    void sessionOpened();
    void sendFortune();

private:
    QTcpServer *tcpServer;
    QStringList fortunes;
    QNetworkSession *networkSession;
};

#endif // SERVER_H
