#ifndef CLIENTS_H
#define CLIENTS_H

#include <QMutex>
#include <iostream>
#include <map>

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
    QMutex mutex;

public:
    static Clients* getInstance();
    bool add (int identifier, string client, string user);
    string createClientName();
};

#endif // CLIENTS_H
