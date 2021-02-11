//
// Created by aluis on 17/11/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_SEARCH_H
#define GRANDE_HOTEL_CENTRAL_SEARCH_H

#include <vector>
#include <string>
#include <queue>

class Employee;
class Book;
class Date;
class DataBase;
class Room;
class Product;
class BuyProduct;

/**
 * Class Search
 * Class to create search
*/

class Database;

class Search {
    std::vector<Employee*> search_employees;                                        ///< private vector search_employees

    std::vector<Book*> search_books;                                                ///< private vector search_books

    std::vector<Employee*> filter_employees_salary;                                 ///< private vector filter_employees_salary

    std::vector<Employee*> filter_employees_role;                                   ///< private vector filter_employees_role

    double total_cost_salaries;                                                     ///< private double total_cost_salaries

    double total_cost_products;                                                     ///< private double total_cost_products

    DataBase* database;

public:

    /**
        * Default Class constructor
    */
    Search();

    /**
        * Class constructor
        * @param database
    */
    Search(DataBase dataBase);

    /**
        * Class Function
        * @param salary
        * Return vector with employees which salary equal to the argument salary
    */
    std::vector<Employee*> sortEmployeesBySalary();

    /**
        * Class Function
        * @param role
        * Return vector with employees which role equal to the argument role
    */
    std::vector<Employee*> findEmployeeByRole(std::string role);

    /**
        * Class Function
        * @param date
        * Return vector with rooms which date equal to the argument date
    */
    std::vector<Book*> dayBooks(Date date);


};


#endif //GRANDE_HOTEL_CENTRAL_SEARCH_H
