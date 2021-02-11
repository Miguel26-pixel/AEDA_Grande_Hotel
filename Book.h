//
// Created by marga on 29/10/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_BOOK_H
#define GRANDE_HOTEL_CENTRAL_BOOK_H

#include "Client.h"
#include "Room.h"
#include "DataBase.h"
#include "Date.h"
#include <vector>

/**
 * Class to create reservations
 * It has the information of the rooms that are associated with the reservation
 * A pointer to the client who did the reservation
 * The check-in date and check-out date
 * The bill of the client
*/
class Book {

    Room* room;                                                                 ///< private member pointer to room

    Client* client;                                                             ///< private member pointer to client

    Date* checkin_date;                                                         ///< private member pointer to date of check-in

    Date* checkout_date;                                                        ///< private member pointer to date of check-out

    Date* book_date;
    /**
        * Class Function
        * @param rooms
        * Checks if there are rooms available and saves them
        * True if there are
    */

    bool findEmptyRoom(const std::vector <Room*>& rooms);

    double reservation_price = 0.0;                                             ///< private member double reservation_price
public:
    /**
        * Default constructor of the class Book
    */
    Book();


    /**
        * Constructor of the class Book
        * @param client
        * @param dataBase
        * @param d1,d2,m1,m2,y1,y2 check-in and check-out date
        * The arguments are the pointer to the client, the check-in date and out
        * The constructor checks which rooms are available *AVISO*
    */

    Book(Client *client, DataBase *dataBase, unsigned int d1, unsigned int m1, unsigned int y1, unsigned int d2, unsigned int m2, unsigned int y2, Date* today);

    void setRoom(Room* room);

    void setCheckDate(Date* data_in, Date* data_out);

    /**
        * Class Function
        * Each room has a specific number of cleaning products per day
        * Return the number of cleaning products needed to the reservation
    */
    int cleaningProductsNeeded();

    /**
        * Class Function
        * Each client spends 2 hygiene products per day
        * Return the number of hygiene products needed to the reservation
    */
    int hygieneProductsNeeded();


    /**
        * Class Function
        * Return the booked room
    */
    Room* getRoom() const;
    
    /**
        * Class Function
        * Return the pointer to the client that made the reservation
    */
    Client * getClient() const;

    /**
        * Class Function
        * Return the price of the reservation
    */
    double getReservation_price() const;

    /**
        * Class Function
        * Set the price of reservation as equal to the value of variable price
    */
    void setReservation_price(double price);

    /**
        * Class Function
        * Return a pointer to the checkin_date
    */
    Date getCheckout_date() const;

    /**
        * Class Function
        * Return a pointer to the checkout_date
    */
    Date getCheckin_date() const;

    Date getBook_date() const;
    
    /**
        * Class Function
        * Return the client that made the reservation
    */
    Client getBookClient() const;

    

    /**
        * Class Operator
        * Compare two different books
        * True if the client, checkin_date and checkout_date are equal
    */
    bool operator == (Book book){
        return (book.client == client && book.checkin_date == checkin_date && book.checkout_date == checkout_date);
    };

};

#endif //GRANDE_HOTEL_CENTRAL_BOOK_H
