//
// Created by aluis on 17/11/2020.
//

#include "Date.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


Date::Date(){}
/**
* Date constructor
*/
Date::Date(int d, int m, int y){
    day = d;
    month = m;
    year = y;
}

Date* todayDate(){
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    Date * today = new Date((tPtr->tm_mday),(tPtr->tm_mon)+1,(tPtr->tm_year)+1900);
    return today;
}

bool Date::operator >(Date date1)
{
    if (year > date1.year) return true;
    else if (year < date1.year) return false;
    else{
        if (month < date1.month) return false;
        else if (month > date1.month) return true;
        else if (day > date1.day) return true;
    }
    return false;
}


/**
     * operator to print
    */
ostream &operator <<(ostream &out, Date &d)
{
    out << "Date: " << setfill('0') << setw(2) << d.day << "/" << setfill('0') << setw(2) << d.month << "/" << d.year;
    return out;
}

/**
 * Count the leap years
*/
int countLeapYear(int month, int year) {
    if (month <= 2) return year--;
    return year;
}

int Date::operator-(Date date1)
{
    long int n = year * 365 + day;
    long int n1 = date1.year * 365 + date1.day;

    for (int i = 0; i < month - 1; i++) n += monthDays[i];
    n += countLeapYear(month, year);

    for(int i = 0; i < date1.month - 1; i++) n1 += monthDays[i];
    n1 += countLeapYear(date1.month, date1.year);

    return (int)(n - n1);
}

