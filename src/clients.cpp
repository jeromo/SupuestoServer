#include "clients.h"

bool Clients::instanceFlag = false;
Clients* Clients::single = nullptr;
Clients* Clients::getInstance()
{
    if(! instanceFlag)
    {
        single = new Clients();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}


string Clients::createClientName()
{
    mutex.lock();
    int length = 10;
    char str[length];
    str[length-1] = '\0';
    size_t i = 0;
    int r;

    for(i = 0; i < length-1; ++i) { //length-1 for the '\0' at the end
        for(;;) {
            r = rand() % 57 + 65; //interval between 65 ('A') and 65+57=122 ('z')
            if((r >= 65 && r <= 90) || (r >= 97 && r <= 122)) { // exclude '[' to '`'
                str[i] = static_cast<char>(r);
                break;
            }
        }
    }
    mutex.unlock();

    return string(str);
}
bool Clients::add (int identifier, string client, string user)
{
    if ((identifier > max_identifier) || (identifier < min_identifier))
        return false;

    mutex.lock();
    it = mapClientUser.find(identifier);
    if (it != mapClientUser.end())
    {
        mutex.unlock();

        return false;
    }

    ClientUser aux;
    aux.client = client;
    aux.user = user;
    mapClientUser[identifier] = aux;

    mutex.unlock();

    return true;
}

void Clients::setLastTime(std::time_t now)
{
    mutex.lock();
    last_time = now;
    mutex.unlock();
}

std::time_t Clients::getLastTime()
{
    return last_time;
}

void Clients::report()
{
    mutex.lock();
    std::cout << "Clients report" << std::endl;
    for ( it = mapClientUser.begin(); it != mapClientUser.end(); it++ )
    {
        std::cout << it->first
                  << ":"
                  << it->second.client
                  << ":"
                  << it->second.user
                  << std::endl ;

    }
    std::cout << std::flush;
    mutex.unlock();
}
