#ifndef CLIENTS_H
#define CLIENTS_H

#include <QMutex>
#include <iostream>
#include <map>
#include <ctime>

using namespace std;


class Clients
{
private:
    static bool instanceFlag;
    static Clients *single;
    const int max_identifier = 250;
    const int min_identifier = 1;
    struct ClientUser
    {
        string user;
        string client;
    };
    map<int, ClientUser> mapClientUser;
    map<int, ClientUser>::iterator it;
    std::time_t last_time;
    QMutex mutex;

public:
    static Clients* getInstance();
    bool add (int identifier, string client, string user);
    string createClientName();
    void setLastTime(std::time_t now);
    std::time_t getLastTime();
    void report();
};

#endif // CLIENTS_H
