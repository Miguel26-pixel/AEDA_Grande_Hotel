//
// Created by marga on 21/11/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_FINANCES_H
#define GRANDE_HOTEL_CENTRAL_FINANCES_H
#include "DataBase.h"
#include "Date.h"

class Finances {
    double products_cost;
    double salaries_cost;
    double booking_profit;
public:
    Finances(DataBase* dataBase, Date* begin, Date* end);
    double getProducts_cost() const {return products_cost;}
    double getSalaries_cost() const {return salaries_cost;}
    double getTotal_cost() const {return (salaries_cost + products_cost);}
    double getBooking_profit() const {return booking_profit;}
    double getProfit() const {return booking_profit - (salaries_cost + products_cost);}
};


#endif //GRANDE_HOTEL_CENTRAL_FINANCES_H
