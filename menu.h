//
// Created by aluis on 20/11/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_MENU_H
#define GRANDE_HOTEL_CENTRAL_MENU_H

#include "UserInterface.h"
#include "InputValidation.h"
#include "Files.h"

/**
 *  Bool Function
 *  Show the initial menu
 *  Redirects to employee's menu according to their position
 *  Allows new logins and the termination of the system
 */
bool menu() {
    DataBase *dataBase = new DataBase();
    UserInterface ui;
    ui.setEndMonth(rand() % 2);
    ui.setChristmas(rand() % 2);

    while (1) {
        loadFiles(dataBase);
        int exit_flag;
        do {
            ui.login(dataBase);
            ui.setDataBase(dataBase);
            string role = ui.getUser()->employeeRole();
            if (role == "Responsible") ui.responsible();
            else if (role == "Cleaning") ui.cleaning();
            else if (role == "Reception") ui.reception();
            else if (role == "Manager") ui.manager();

            std::cout << "Turn off hotel system?\n[1] Yes\n[2] No\n";
            std::cin >> exit_flag;
        } while (exit_flag - 1);

        return true;
    }
}

#endif //GRANDE_HOTEL_CENTRAL_MENU_H