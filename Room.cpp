//
// Created by marga on 27/10/2020.
//

#include "Room.h"
#include "Product.h"
#include "DataBase.h"

/**
 * Default Class constructor
 */
Room::Room(){
}

/**
 * Class constructor
 */
Room::Room(int floor, int number, DataBase &dataBase) {
    available = true;
    this-> floor = floor;
    this-> number = number;
    capacity = 3;
}

/**
  * SubClass constructor
  */
NoViewRoom::NoViewRoom(int floor, int number, DataBase &database) : Room(floor, number, database)
{
    capacity = 3;
}

/**
  * SubClass constructor
  */
ViewRoom::ViewRoom(int floor, int number, DataBase &database) : Room(floor, number, database)
{
    capacity = 3;
}

/**
  * SubClass constructor
  */
SuiteRoom::SuiteRoom(int floor, int number, DataBase &database) : Room(floor, number, database)
{
    capacity = 4;
}

/**
  * Default SubClass
  */
NoViewRoom::NoViewRoom(): Room() {}

/**
  * Default SubClass
  */
ViewRoom::ViewRoom(): Room() {}

/**
  * Default SubClass
  */
SuiteRoom::SuiteRoom(): Room() {}

/**
  * Compare two different rooms
  */
bool Room::operator==(const Room &room) const
{
    return number == room.number && floor == room.floor;
}

/**
  * Add room to a vector of rooms
  */
bool Room::AddRoomElement(Room *room, std::vector<Room *> roomvec) {
    for (auto & i : roomvec)
        if (*room == (*i)) return false;
    roomvec.push_back(room);
    return true;
}

/*
 * Getters & Setters
 */
/**
  * Return bool available
  */
int Room::getFloor() const
{
    return floor;
}

/**
  * Return int number
   */
int Room::getNumber() const
{
    return number;
}

/**
  * Return bool available
  */
bool Room::getAvailable() const
{
    return available;
}

/**
  * Return int capacity
  */
int Room::getCapacity() const
{
    return capacity;
}


/**
  * Set room's available as equal to argument avail
  */
void Room::setAvailable(bool avail)
{
    available = avail;
}

/**
  * Return cleaning products
  */
int SuiteRoom::getCleaning_products() const {
    return num_cleaning_products;
}

/**
  * Return cleaning products
  */
int NoViewRoom::getCleaning_products() const {
    return num_cleaning_products;
}

/**
  * Set room's floor as equal to argument floor
  */
void Room::setFloor(int floor) {
    this-> floor = floor;
}


/**
  * Set room's number as equal to argument number
  */
void Room::setNumber(int number) {
    this-> number = number;
}

/**
  * Set room's floor as equal to argument floor
  */
void Room::setCapacity(int capacity) {
    this -> capacity = capacity;
}

int Room::getCleaning_products() const{
    return 0;
}
const double Room::getPromotion() const {
    return 0;
}

const double Room::getBase_price() const {
    return 0;
}



/**
  * Return cleaning products
  */
int ViewRoom::getCleaning_products() const {
    return num_cleaning_products;
}

/**
  * Return base_price of no view rooms
  */
const double NoViewRoom::getBase_price() const {
    return base_price;
}

/**
  * Return base_price of view rooms
  */
const double ViewRoom::getBase_price() const {
    return base_price;
}

/**
  * Return base_price of suites
  */
const double SuiteRoom::getBase_price() const {
    return base_price;
}

/**
  * Return promotion
  */
const double ViewRoom::getPromotion() const {
    return promotion;
}


/**
  * Return promotion
  */
const double SuiteRoom::getPromotion() const {
    return promotion;
}
/**
  * Return promotion
  */
const double NoViewRoom::getPromotion() const {
    return promotion;
}


