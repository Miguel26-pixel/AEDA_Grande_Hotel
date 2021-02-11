//
// Created by marga on 28/10/2020.
//

#include "Client.h"
#include "Exception.h"
#include "InputValidation.h"

#include <math.h>

Client::Client(){
    stays = 1;
}

Client::Client(std::string name, int group_size, unsigned int nif, unsigned int stays)
{
    this -> name = name;
    this -> group_size = group_size;
    this -> nif = nif;
    old_client = stays > 1;
    present = false;
    room_number = -1;
    this -> stays = stays;
}

bool Client::operator==(const Client &client) const
{
    return client.nif == nif;
}

bool Client:: incrementStays(){
    stays++;
    return (stays > 2);
}

/*
 * Getters & Setters
 */

bool Client::getOld_Client() const {return old_client;}

void Client::setOld_Client(bool old_client) {this -> old_client = old_client;}

bool Client::getPresent() const {return present;}

void Client::setPresent(bool present) {this -> present = present;}

std::string Client::getName() const {return name;}

int Client::getGroupSize() const {return group_size;}

int Client::getRoomNumber() const {
    return room_number;
}

unsigned int Client::getIntNIF() const {
    return nif;
}

unsigned int Client::getStays() const {
    return stays;
}

void Client:: setNIF(unsigned int nif){
    this -> nif = nif;
}

void Client::setName(std::string name) {
    this -> name = name;
}

void Client::setGroupSize(int group_size) {
    this -> group_size = group_size;
}

void Client::setRoomNumber(int room_number) {
    this -> room_number= room_number;
}

double Client::getPromotion() const {
    return promotion;
}

void Client::setPromotion(double promo) {
    this -> promotion = promo;
}

