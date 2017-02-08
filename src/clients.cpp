#include "clients.h"

Clients::Clients()
{

}
string Clients::createClientName()
{
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

    return string(str);
}
bool Clients::addClient (int identifier, string client, string user)
{
    if ((identifier > max_identifier) || (identifier < min_identifier))
        return false;

    it = mapClientUser.find(identifier);
    if (it != mapClientUser.end())
        return false;

    ClientUser aux;
    aux.client = client;
    aux.user = user;
    mapClientUser[identifier] = aux;

    return true;
}
