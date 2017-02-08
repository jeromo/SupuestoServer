#ifndef CLIENTS_H
#define CLIENTS_H

#include <iostream>
#include <map>

using namespace std;


class Clients
{
private:
    const int max_identifier = 250;
    struct ClientUser
    {
        string user;
        string client;
    };
    map<int, ClientUser> mapClientUser;
    map<int, ClientUser>::iterator it;

public:
    Clients();
    bool addClient (int identifier, string client, string user);
    string createClientName();
};

#endif // CLIENTS_H
