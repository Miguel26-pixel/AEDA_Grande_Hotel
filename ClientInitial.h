//
// Created by aluis on 04/01/2021.
//

#ifndef GRANDE_HOTEL_CENTRAL_CLIENTINITIAL_H
#define GRANDE_HOTEL_CENTRAL_CLIENTINITIAL_H

#include <string>
#include <vector>
#include "Client.h"

/**
 * ## Class ClientInitial
 * Save vector with all clients with the same initial
 */
class ClientInitial {
    std::vector<Client*> clients_with_coincident_initial;
    char initial;
    Client * client;

public:
    ClientInitial(char initial,Client * c);
    Client * getClient() const;
    char getInitial() const;
    std::vector<Client*> getClientsCoincident() const;
    void addClientsCoincident( Client * c);
};


#endif //GRANDE_HOTEL_CENTRAL_CLIENTINITIAL_H
