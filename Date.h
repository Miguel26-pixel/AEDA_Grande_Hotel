//
// Created by aluis on 16/11/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_DATE_H
#define GRANDE_HOTEL_CENTRAL_DATE_H

#include <array>
#include <iostream>
#include <ostream>

const int monthDays[12] = { 31, 28, 31, 30, 31,
                            30, 31, 31, 30, 31, 30, 31 };      ///< array with the numbers of days per month

/**
 * Struct
 * Represents a specific date
 * day/month/year
*/
struct Date{
    unsigned int day;                                          ///< day of the date

    unsigned int month;                                        ///< month of the date

    unsigned int year;                                         ///< year of the date

    Date();
    /**
     * Date constructor
     * @param d : day
     * @param m : month
     * @param y : year
    */
    Date(int d, int m, int y);

    /**
     * Date operator ==
     * Compare two diferent dates
     * True if all date is equal
    */
    bool operator == (Date date) {
        return (date.day == day && date.month == month && date.year == year);
    }
    /**
     * Date operator >
     * @param date1
     * Compare two diferent dates
     * True if the argument date is lower
    */
    bool operator >(Date date1);

    int operator -(Date date1);
    /**
     * Friend operator <<
     * @param d : date to print
     * @param out
     * operator to print
    */
    friend std::ostream & operator <<(std::ostream &out, Date &d);

};
int countLeapYear(int month, int year);
Date* todayDate();


#endif //GRANDE_HOTEL_CENTRAL_DATE_H
