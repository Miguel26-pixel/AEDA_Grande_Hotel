//
// Created by migam on 12/26/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_VEHICLE_H
#define GRANDE_HOTEL_CENTRAL_VEHICLE_H

#include <iostream>

/**
 * ##Class Vehicle
 * Vehicles are used transport clients from the airport
 * Used only by the manager
 */
class Vehicle {
    std::string registration;
    int km;
    int number_seats;
public:

    Vehicle(){};
    Vehicle(std::string registration,int km,int number_seats);
    std::string getRegistration() const;
    int getKM() const;
    int getNumber_Seats() const;
    void addKM(int add_km);
    void setKm(int km);
    void setNumber_seats(int no_seats);
    void setRegistration(std::string registration);
    bool operator<(Vehicle *veh);
    bool operator==(Vehicle *veh);
};


#endif //GRANDE_HOTEL_CENTRAL_VEHICLE_H
