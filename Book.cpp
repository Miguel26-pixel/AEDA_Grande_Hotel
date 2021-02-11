//
// Created by marga on 29/10/2020.
//

#include "Book.h"
#include "Date.h"
#include "InputValidation.h"
#include "Exception.h"

#include <algorithm>

Book::Book(){
    this  -> client = new Client();
}

Book::Book(Client *client, DataBase *dataBase, unsigned int d1, unsigned int m1, unsigned int y1, unsigned int d2, unsigned int m2, unsigned int y2, Date* today)
{
    this->client = client;
    book_date = today;
    Date *check_in_date = new Date(d1, m1, y1);
    checkin_date = check_in_date;
    Date *check_out_date = new Date(d2, m2, y2);
    checkout_date = check_out_date;
    dateValidation(check_in_date, check_out_date);
    std::vector <Room*> rooms = dataBase->getRooms();
    if(!findEmptyRoom(rooms)) throw NoRoomsAvailable();
    reservation_price = (check_in_date - check_out_date) * (room->getBase_price());
}

/**
 * Check if there are rooms available and saves them
*/
bool Book::findEmptyRoom(const std::vector <Room*>& rooms)
{
    for (auto & r : rooms)
    {
        if (r->getAvailable() && client->getGroupSize()  <= r->getCapacity())
        {
            room = r;
            room->setAvailable(0);
            return true;
        }
    }
    return false;
}

/**
 * Calculate the number of cleaning products needed to the reservation
*/
int Book::cleaningProductsNeeded() {
    int book_days = (*checkout_date) - (*checkin_date);
    int cleaning_products = 0;
    cleaning_products += room->getCleaning_products();
    return cleaning_products * book_days;
}

/**
  * Calculate the number of hygiene products needed to the reservation
*/
int Book::hygieneProductsNeeded() {
    int book_days = (*checkout_date) - (*checkin_date);
    int hygiene_products = 0;

    //each client has 2 hygiene products per day
    hygiene_products = client->getGroupSize();

    return hygiene_products * book_days;
}

//Getters and Setters

/**
 * Return a pointer to the checkin_date
*/
Date Book::getCheckin_date() const {
    return *checkin_date;
}

/**
 *  Return a pointer to the checkout_date
*/
Date Book::getCheckout_date() const {
    return *checkout_date;
}

/**
 * Return the pointer to the client that made the reservation
*/
Client * Book::getClient() const {
    return client;
}

/**
 * Return the price of the reservation
*/
double Book::getReservation_price() const {
    return reservation_price;
}

/**
 * Set the price of reservation as equal to the value of variable price
*/
void Book::setReservation_price(double price){
    this -> reservation_price = price;
}

/**
 * Return the client that made the reservation
*/
Client Book::getBookClient() const {
    return *client;
}

Date Book::getBook_date() const {return *book_date;}

Room* Book::getRoom() const {
    return room;
}

void Book::setRoom(Room *room) {
    this -> room = room;
}

void Book::setCheckDate(Date *data_in, Date *data_out) {
    this -> checkin_date = new Date(data_in->day,data_in->month,data_in->year);
    this -> checkout_date = new Date(data_out->day,data_out->month,data_out->year);
}
