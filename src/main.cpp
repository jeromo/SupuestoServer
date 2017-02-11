#include <QCoreApplication>
#include "server.h"
#include "finish.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server server;
    Finish *thread = new Finish();
    thread->start();

    return a.exec();
}
