//
// Created by migam on 11/18/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_LOGIN_H
#define GRANDE_HOTEL_CENTRAL_LOGIN_H

#include "DataBase.h"
#include "Exception.h"
#include <string>

/**
 *  Class Login
 *  Class to the user login into the site
*/
class Login{
    Employee* user;                                                     ///< private Employee
public:
    /**
        *  Default Login constructor
    */
    Login();

    /**
        *  Class Function to validate the user
        *  @param database
        *  @param login_name
        *  @param login_nif
        *  Return true if the employee exists
        *  Throw exception if false
    */
    bool userLogin(DataBase * database, std::string login_name, unsigned int login_nif);

    /**
        *  Class function
        *  Return the user
    */
    Employee* getUser() const;
};

//APAGAR
/*
class EmployeeDoesntExist{
    std::string login_nif;
public:
    EmployeeDoesntExist(std::string login_nif){ login_nif = login_nif; }
    std::string getNIF() const { return login_nif; }
};
*/
#endif //GRANDE_HOTEL_CENTRAL_LOGIN_H
