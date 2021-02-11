//
// Created by marga on 28/10/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_CLIENT_H
#define GRANDE_HOTEL_CENTRAL_CLIENT_H

#include "Room.h"

#include <string>
#include <vector>

/**
 * Class that defines the clients
 * It defines his name, nif number
 * If it's an old client or not, if it's present right now
 * The group size of the reservation and the room_number of the reservation
*/
class Client{
    std::string name;                                                       ///< private member string name

    bool old_client;                                                        ///< private member boolean old_client

    int group_size;                                                         ///< private member int group_siz

    bool present;                                                           ///< private member boolean present

    int room_number;                                                        ///< private member room_number

    unsigned int nif;                                                   ///< private member nif

    unsigned int stays;

    double promotion;
public:
    /**
        * Default Client constructor
    */
    Client();

    /**
        * Client constructor
        * Create the client with his name, nif number and group_size
    */
    Client(std::string name, int group_size, unsigned int nif, unsigned int stays);


    /**
        * Class Operator ==
        * Compare two different clients
        * True if nif number its equal
    */
    bool operator ==(const Client &client) const;

    bool incrementStays();

    //Getters & Setters
    /**
        * Class Function
        * Return the boolean old_client
    */
    bool getOld_Client() const;

    /**
        * Class Function
        * Return the boolean present
    */
    bool getPresent() const;

    /**
        * Class Function
        * Return the integer value of client's group size
    */
    int getGroupSize() const;

    /**
        * Class Function
        * Return the value of client's name
    */
    std::string getName() const;

    /**
        * Class Function
        * Return nif number
    */
    unsigned int getIntNIF() const;


    void setNIF(unsigned int nif);


    /**
        * Class Function
        * Return the value of client's room number
    */
    int getRoomNumber() const;
    /**
        * Class Function
        * @param old_client
        * Set the old_client as equal to the argument old_client
    */
    void setOld_Client(bool old_client);
    /**
        * Class Function
        * @param present
        * Set the class' variable "present" as equal to the argument
    */
    void setPresent(bool present);
    /**
        * Class Function
        * @param name
        * Set the client's name as equal to the string argument name
    */
    void setName(std::string name);
    /**
        * Class Function
        * @param groupsize
        * Set the the client's group_size as equal to the value of the argument group_size
    */
    void setGroupSize(int group_size);

    /**
        * Class Function
        * @param room_number
        * Set the client's room number to the value of the argument room number
    */
    void setRoomNumber(int room_number);

    void setStays(unsigned int stays){this-> stays = stays;};

    unsigned int getStays() const;

    double getPromotion() const;

    void setPromotion (double promo);
};


#endif //GRANDE_HOTEL_CENTRAL_CLIENT_H
