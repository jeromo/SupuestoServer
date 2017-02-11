#include "finish.h"

#include <QCoreApplication>


#include <ctime>
#include <iostream>
#include <clients.h>

Finish::Finish()
{
    Clients *clients = Clients::getInstance();
    clients->setLastTime(std::time(nullptr));
}

void Finish::run()
{
    Clients *clients = Clients::getInstance();

    while (1){
        sleep(60);
        std::time_t result = std::time(nullptr);
        std::cout << std::asctime(std::localtime(&result))
                  << result << " seconds since the Epoch\n" << std::flush;
        if (result - clients->getLastTime() > 60 ){
            clients->report();

            QCoreApplication::quit();
        }

    }
}
