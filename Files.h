//
// Created by migam on 11/16/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_FILES_H
#define GRANDE_HOTEL_CENTRAL_FILES_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include "bst.h"

class Client;
class Employee;
class Product;
class Room;
class Book;
class Date;
class DataBase;
class BuyProduct;
class Vehicle;

//book
#define NAME 0
#define NIF 1
#define GROUP_SIZE 2
#define HISTORY 3
#define PRESENT 4
#define ROOM_NUMBER 5
#define ROOM_TYPE 5
#define STAYS 6
#define DATE 6

//employee
#define WORK_YEARS 2
#define SALARY 3

//rooms
#define ROOM_ID 0
#define ROOM_AVAILABLE 1
#define ROOM_CAPACITY 2

//products
#define TYPE 0
#define QUALITY 1
#define PRICE 2

//buy product
#define PROVIDER 3
#define RATING 4
#define STOCK 5

//vehicles
#define REGISTRATION 0
#define DISTANCE 1
#define NO_SEATS 2



/**
 *  Function load
 *  @param database
 *  function to load all the information from the files
*/
void loadFiles(DataBase* database);

/**
 *  Function update clients file
 *  @param client
 *  function to update
*/
void updateClientsFile(const std::vector<Client*>& client);

/**
 *  Function update employees file
 *  @param employee
 *  function to update
*/
void updateEmployeesFile(const std::vector<Employee*>& employee);

/**
 *  Function update rooms file
 *  @param room
 *  function to update
*/
void updateRoomsFile(const std::vector<Room*>& room);

/**
 *  Function update stock products file
 *  @param product
 *  function to update
*/
void updateProductStockFile(const std::vector<Product*>& product);

/**
 *  Function update products to buy file
 *  @param product
 *  function to update
*/
void updateProductToBuyFile(std::priority_queue<BuyProduct> product);

/**
 *  Function update books file
 *  @param book
 *  function to update
*/
void updateBookFile(std::vector<Book*> book);

/**
 *  Function to create a room to type of argument
 *  @param room_type
*/
Room* roomIdentifier(std::string room_type);

void updateVehiclesFile(const BST<Vehicle*>& vehicle);



#endif //GRANDE_HOTEL_CENTRAL_FILES_H