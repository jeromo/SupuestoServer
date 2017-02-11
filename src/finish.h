#ifndef FINISH_H
#define FINISH_H

#include <QThread>
#include <QTcpSocket>

class Finish : public QThread
{
    Q_OBJECT

public:
    Finish();
    void run() Q_DECL_OVERRIDE;

};

#endif // FINISH_H
