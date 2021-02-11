//
// Created by aluis on 19/11/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_USERINTERFACE_H
#define GRANDE_HOTEL_CENTRAL_USERINTERFACE_H

#include "Login.h"
#include "Book.h"
#include "Search.h"
#include "Exception.h"
#include "InputValidation.h"
#include "Finances.h"
#include "Files.h"
#include <string>

#define LOG_OUT(n) n

#define BOOK 2

#define VIEW_OPTIONS "-----VISUALIZE------"
#define ACTIONS_OPTIONS "-----ACTIONS------"
#define PERSONAL_FOLDER  1
#define SEE_EMPLOYEES 2
#define BOOKS_PER_DAY 3
#define STOCK_PRODUCTS 4
#define FINANCES 5
#define SHOW_VEHICLES 6
#define FREQ_CLIENTS 7
#define FINISH_BOOK 8
#define ADD_PRODUCTS 9
#define CHANGE_RATING 10
#define ADD_EMPLOYEES 11
#define PAY_SALARIES 12
#define DELIVER_VEHICLES 13
#define APPLY_C_PROMO 14
#define UPDATE_HOTEL_DB 15

/**
 * Class Search
 * Class to create search
*/
class UserInterface {
    DataBase* dataBase;                                                             ///< private member dataBase

    Employee* user;                                                                 ///< private member user

    std::vector<std::string> cleaning_actions {"Visualize personal folder.", "Log-out.\n" };         ///< private vector cleaning actions

    std::vector<std::string> responsible_actions {"Visualize personal folder.", "Log-out.\n"};        ///< private vector responsible actions

    std::vector<std::string> reception_actions {"Visualize personal folder.", "Make reservation (temporary).","Log-out.\n"};    ///< private vector reception actions

    std::vector<std::string> manager_actions { "Visualize personal folder.",
                                              "Visualize employees.",  "Visualize books.",
                                              "Visualize hotel stock products.",
                                               "View finances.", "Visualize available vehicles.", "Visualize frequent clients.",
                                               "Finish book.", "Buy products.", "Change product rating.",
                                               "Add Employee.", "Pay Salaries.", "Deliver used vehicles.",
                                               "Choose two initials to apply Christmas promotion.", "Update Hotel's files.",
                                               "Log-out.\n"};

    bool is_christmas; ///< private method christmas
    bool is_end_of_the_month; ///<private method end of month

public:
    /**
        * Default Class constructor
    */
    UserInterface();

    /**
        * Class function
        * Manage the login

    */
    void login(DataBase *dataBase);

    /**
        * Class function
        * Interface of manager
    */
    void manager();

    /**
        * Class function
        * Interface of reception
    */
    void reception();

    /**
        * Class function
        * Interface of responsible
    */
    void responsible();

    /**
        * Class function
        * Interface of cleaning
    */
    void cleaning();

    /**
        * Class function
        * @param actions vector with the actions that user can do
        * Show the action which one with index
        * Return the index that the user chose
    */
    int chooseAction(std::vector<std::string> actions);

    /**
        * Class function
        * Print all the information about the user
    */
    void printPersonalFolder();

    /**
        * Class function
        * Receive all the inputs to make the reservation
        * Make the reservation
    */
    void createReservation();

    /**
        * Class function
        * @param search
        * See the product to buy
        * Buy the products and see the cost of them
        * Save this information
    */
    void buyProducts(Search *search);

    /**
        * Class function
        * @param book the reservation
        * See if the client is a new client or not
        * Set the promotion
        * Calculates the the price of the reservation
    */
    void setPromotion(Book *book);

    /**
        * Class function
        * Create the employee with the inputs
    */
    void createEmployee();

    /**
        * Class function
        * Return the user
    */
    Employee* getUser() const;

    /**
    * Class function
    * Set the database of this UserInterface
    */
    void setDataBase(DataBase* dataBase);

    void viewFinances();

    void finishReservation();

    void showEmployees(Search search);

    void printBooks(Search search);

    void changeRating();

    void showStockProducts();

    /**
     * Allows the clients to rent a shuttle to the airport
     * Choosing always the best available vehicle
     * @param kms
     * @param num_visitants
     * @return the best suitable vehicle
     */
    Vehicle reserveVehicle(unsigned kms, unsigned num_visitants);

    /**
     * Prints vehicles information
     */
    void showVehicles();

    /**
     * Checks if there are vehicles that need to be delivered to the company
     * Delivers vehicles if needed
     */
    void deliverVehicles();

    /**
     * Displays useful information when the manager logs in
     * Information: end of month; christmas; missing products; vehicles to be delivered; unfinished books
     */
    void managerWarnings();

    /**
     * Manager function
     * Allows the manager to choose which clients will get the Christmas promotion
     * Manager has to choose different 2 initials
     */
    void applyChristmasPromotion();

    /**
     * Allows the user to define if it is christmas time
     * Method created for presentation and test purposes
     */
    void setChristmas(bool c){is_christmas = c;};

    /**
     * Allows the user to define if it the end of the current month
     * Method created for presentation and test purposes
     */
    void setEndMonth(bool m) {is_end_of_the_month = m;};

    /**
     * Prints frequent client information
     */
    void showFreqClients();
};



#endif //GRANDE_HOTEL_CENTRAL_USERINTERFACE_H
