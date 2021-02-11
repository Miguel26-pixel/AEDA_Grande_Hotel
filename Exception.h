//
// Created by marga on 19/11/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_EXCEPTION_H
#define GRANDE_HOTEL_CENTRAL_EXCEPTION_H


#include <vector>
#include <string>
#include "Date.h"

/**
 * Exception Class
 * Invalid nif exception
*/
class InvalidNifException{
    std::vector<unsigned int> invalid_nif;                                          ///< private vector nif
public:
    /**
       *Exception InvalidNif constructor
       * @param nif
    */
    InvalidNifException(std::vector<unsigned int> &nif){invalid_nif = nif;};

    /**
     * Exception class function
     * Return the invalid nif
    */
    std::vector<unsigned int> getInvalidNIF() const {return invalid_nif;};
};

/**
 * Exception Class
 * Employee Doesnt Exist exception
*/
class EmployeeDoesntExist{
    unsigned int login_nif;                                                          ///< private string nif
public:
    /**
       *Exception EmployeeDoesntExist constructor
       * @param login_nif
    */
    EmployeeDoesntExist(unsigned int login_nif){ login_nif = login_nif; }

    /**
     * Exception class function
     * Return the login_nif
    */
    unsigned int getNIF() const { return login_nif; }
};

/**
 * Exception Class
 * No Rooms Available exception
*/
class NoRoomsAvailable {
public:
    /**
       *Exception NoRoomsAvailable constructor
    */
    NoRoomsAvailable() {}
};

class FloorAlreadyAssigned{
    int floor;
public:
    FloorAlreadyAssigned(int floor){this->floor=floor;}
};

class FloorNotAssigned{
    int floor;
public:
    FloorNotAssigned(int floor){this->floor=floor;};
};

class InvalidDate{
    Date date;
public:
    InvalidDate(Date date) : date(date) {};
    Date getDate() const {return date;}
};


#endif //GRANDE_HOTEL_CENTRAL_EXCEPTION_H