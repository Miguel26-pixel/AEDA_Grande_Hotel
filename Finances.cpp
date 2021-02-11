//
// Created by marga on 21/11/2020.
//

#include "Finances.h"
#include "Book.h"
using namespace std;

Finances::Finances(DataBase* dataBase, Date* begin, Date* end) {
    int days = (*end) - (*begin);
    salaries_cost = 0; products_cost = 0; booking_profit = 0;

    if (dataBase->getEmployeesPayment()){
        for (auto employee: dataBase->getEmployees()){
            salaries_cost += employee->getSalary();
        }
    }

    for (auto b : dataBase->getBooks()){
        booking_profit += b->getReservation_price();
    }

    products_cost += dataBase->getProductsCosts();
}