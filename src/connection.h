#ifndef CONNECTION_H
#define CONNECTION_H

#include <QThread>
#include <QTcpSocket>

class Connection : public QThread
{
    Q_OBJECT

public:
    Connection(int socketDescriptor, QObject *parent);
    QString read();
    void write(QString data);
    void run() Q_DECL_OVERRIDE;


private:
    int socketDescriptor;
    const int Timeout = 5 * 1000;
    QTcpSocket socket;

};

#endif // CONNECTION_H
