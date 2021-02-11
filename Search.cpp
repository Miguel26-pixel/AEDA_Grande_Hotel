//
// Created by aluis on 17/11/2020.
//

#include "Search.h"
#include "DataBase.h"
#include "Book.h"
#include <bits/stdc++.h>
#include <climits>

using namespace std;

/**
        * Default Class constructor
    */
Search::Search(){}

/**
        * Class constructor
    */
Search::Search(DataBase database1){
    search_employees = database1.getEmployees();
    search_books = database1.getBooks();
    //stock_products = database1.getStock_products();
    database = &database1;
}

/**
        * Return vector with employees which salary equal to the argument salary
    */
std::vector<Employee *> Search::sortEmployeesBySalary() {
    filter_employees_salary = search_employees;
    sort(filter_employees_salary.begin(), filter_employees_salary.end(), [](Employee* employee1, Employee* employee2){
        return employee1->getSalary() <= employee2->getSalary();
    });
    return filter_employees_salary;
}

/**
        * Return vector with employees which role equal to the argument role
    */
std::vector<Employee *> Search::findEmployeeByRole(string role) {
    for(auto i: search_employees){
        if(role == i->employeeRole())
            filter_employees_role.push_back(i);
    }
    return filter_employees_role;
}

/**
        * Return books vector for the given date
    */
std::vector<Book *> Search::dayBooks(Date date) {

    search_books = database->getBooks();
    vector<Book *> books_of_the_day;

    for (auto b: search_books){
        if (b->getCheckin_date() == date){
            books_of_the_day.push_back(b);
        }
    }
    return books_of_the_day;
}

