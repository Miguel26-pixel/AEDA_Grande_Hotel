//
// Created by migam on 11/18/2020.
//

#include "Login.h"
#include <iostream>

/**
        *  Default Login constructor
    */
Login::Login(){};

/**
        *  Return true if the employee exists
        *  Throw exception if false
    */
bool Login::userLogin(DataBase *database, std::string login_name, unsigned int login_nif) {
    try{
        for (auto  e: database->getEmployees()){
            if(e->getName() == login_name && e->getNIF() == login_nif){
                user = (e);
                return true;
            }
        }
        throw EmployeeDoesntExist(login_nif);
    }
    catch (EmployeeDoesntExist){
        std::cout << "\nEmployee does not exist.\n";
        return false;
    }
}

//Getter
/**
        *  Return the user
    */
Employee* Login::getUser() const {
    return user;
}