//
// Created by aluis on 04/01/2021.
//

#include "ClientInitial.h"

using namespace std;

ClientInitial::ClientInitial(char initial, Client * c) {
    this-> initial = initial;
    clients_with_coincident_initial.push_back(c);
    this -> client = c;
}

Client * ClientInitial::getClient() const {
    return client;
}

char ClientInitial::getInitial() const {
    return initial;
}

std::vector<Client *> ClientInitial::getClientsCoincident() const {
    return clients_with_coincident_initial;
}

void ClientInitial::addClientsCoincident(Client *  c) {
    clients_with_coincident_initial.push_back(c);
}