//
// Created by migam on 12/26/2020.
//

#include "Vehicle.h"
#include <iostream>
#include <utility>

using namespace std;

/**
 * ## Vehicle constructor
 * @param registration
 * @param km
 * @param number_seats
 */
Vehicle::Vehicle(string registration,int km,const int number_seats) : registration(std::move(registration)), number_seats(number_seats){
        this -> km = km;
}

void Vehicle::addKM(int add_km)
{
    this -> km += add_km;
}

bool Vehicle::operator<(Vehicle *veh)
{
    return (km != veh->km) ? km < veh->km : number_seats > veh->number_seats;
}

bool Vehicle::operator==(Vehicle *veh)
{
    return registration==veh->registration;
}

string Vehicle::getRegistration() const
{
    return registration;
}

int Vehicle::getKM() const
{
    return km;
}

int Vehicle::getNumber_Seats() const
{
    return number_seats;
}

void Vehicle::setRegistration(std::string registration) {
    this -> registration = registration;
}

void Vehicle::setNumber_seats(int no_seats) {
    number_seats = no_seats;
}

void Vehicle::setKm(int km) {
    this-> km = km;
}


