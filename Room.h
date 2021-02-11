//
// Created by marga on 27/10/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_ROOM_H
#define GRANDE_HOTEL_CENTRAL_ROOM_H

#include <vector>
#include <iostream>
#include <string>

class Product;
class DataBase;

/**
 * Class Room
 * Class to create rooms
*/
class Room{

protected:
    bool available;                                                     ///< private bool available

    int floor;                                                          ///< private int floor

    int number;                                                         ///< private int number

    int capacity;                                                       ///< private int capacity

    std::vector<Product*> products_info;                                ///< private vector products_info

public:
    /**
        * Default Class constructor
    */

    Room();

    /**
        * Class constructor
        * @param floor
        * @param number
        * @param database
    */
    Room(int floor, int number, DataBase &database);

    /**
        * Class operator
        * @param room
        * Compare two different rooms
        * Return true if they have the same floor and number
    */
    bool operator ==(const Room &room) const;

    //Getters & Setters

    /**
        * Class function
        * Return bool available
    */
    bool getAvailable() const;

    /**
        * Class function
        * Return bool available
    */
    int getFloor() const;

    /**
        * Class function
        * Return int number
    */
    int getNumber() const;

    /**
        * Class function
        * Return int capacity
    */
    int getCapacity() const;

    virtual /**
        * Class function
        * @param avail
        * Set room's available as equal to argument avail
    */
    void setAvailable(bool avail);

    /**
        * Class function
        * @param floor
        * Set room's floor as equal to argument floor
    */
    void setFloor(int floor);

    virtual /**
        * Class function
        * @param number
        * Set room's number as equal to argument number
    */
    void setNumber(int number);

    virtual /**
        * Class function
        * @param capacity
        * Set room's floor as equal to argument floor
    */
    void setCapacity(int capacity);

    /**
        * Class function
        * @param room
        * @param roomvec
        * Add room to a vector of rooms
        * Return true if success
    */

    bool AddRoomElement(Room * room, std::vector<Room *> roomvec);

    /**
        * Class virtual function
    */
    virtual int getCleaning_products() const;

    /**
        * Class virtual function
        * Return "Room"
    */
    virtual std::string RoomType(){return "Room";};

    /**
        * Class virtual function
        * Return 0
    */
    virtual const double getBase_price() const;

    /**
        * Class virtual function
        * Return 0
    */
    virtual const double getPromotion() const;

};

/**
 * SubClass public of Room
 * SubClass to create no view rooms
*/
class NoViewRoom : public Room {
    const double base_price = 99.99;                                    ///< private const base price price of no view rooms

    const int num_cleaning_products = 1;                                ///< private const int number of cleaning products

    const double promotion = 0.12;                                      ///< private const double promotion
public:
    /**
        * SubClass constructor
        * @param floor
        * @param number
        * @param database
    */
    NoViewRoom(int floor, int number, DataBase &database);

    /**
        * Default SubClass
    */
    NoViewRoom();

    /**
        * SubClass virtual function
        * Return cleaning products
    */
    virtual int getCleaning_products() const;

    /**
        * SubClass virtual function
        * Return base_price of no view rooms
    */
    virtual const double getBase_price() const;

    /**
        * SubClass virtual function
        * Return "NoViewRoom"
    */
    virtual std::string RoomType(){return "NoViewRoom";};

    /**
        * SubClass virtual function
        * Return promotion
    */
    virtual const double getPromotion() const;
};
/**
 * SubClass public of Room
 * SubClass to create view rooms
*/
class ViewRoom : public Room {
    const double base_price = 119.99;                                   ///< private const base price price of view rooms

    const int num_cleaning_products = 1;                                ///< private const int number of cleaning products

    const double promotion = 0.08;                                      ///< private const double promotion
public:
    /**
        * SubClass constructor
        * @param floor
        * @param number
        * @param database
    */
    ViewRoom(int floor, int number, DataBase &database);

    /**
        * Default SubClass
    */
    ViewRoom();

    /**
        * SubClass virtual function
        * Return cleaning products
    */
    virtual int getCleaning_products() const;

    /**
        * SubClass virtual function
        * Return base_price of no view rooms
    */
    virtual const double getBase_price() const;

    /**
        * SubClass virtual function
        * Return "ViewRoom"
    */
    virtual std::string RoomType(){return "ViewRoom";};

    /**
        * SubClass virtual function
        * Return promotion
    */
    virtual const double getPromotion() const;
};

/**
 * SubClass public of Room
 * SubClass to create view suites
*/
class SuiteRoom : public Room {
    const double base_price = 159.99;                                   ///< private const base price price of view rooms

    const int num_cleaning_products = 2;                                ///< private const int number of cleaning products

    const double promotion = 0.05;                                      ///< private const double promotion
public:
    /**
        * SubClass constructor
        * @param floor
        * @param number
        * @param database
    */
    SuiteRoom(int floor, int number, DataBase &database);

    /**
        * Default SubClass
    */
    SuiteRoom();

    /**
        * SubClass virtual function
        * Return cleaning products
    */
    virtual int getCleaning_products() const;

    /**
        * SubClass virtual function
        * Return base_price of no view rooms
    */
    virtual const double getBase_price() const;

    /**
        * SubClass virtual function
        * Return "Suite"
    */
    virtual std::string RoomType(){return "Suite";};

    /**
        * SubClass virtual function
        * Return promotion
    */
    virtual const double getPromotion() const;
};
#endif //GRANDE_HOTEL_CENTRAL_ROOM_H