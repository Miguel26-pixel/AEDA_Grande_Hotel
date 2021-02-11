//
// Created by marga on 28/10/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_DATABASE_H
#define GRANDE_HOTEL_CENTRAL_DATABASE_H

#include "Client.h"
#include "Employee.h"
#include "Room.h"
#include "Product.h"
#include "BuyProduct.h"
#include "Vehicle.h"
#include "ClientInitial.h"
#include <queue>
#include <unordered_set>
#include <string>
#include <vector>
#include <array>
#include "bst.h"
#include "binaryTree.h"

class Book;
struct Date;
class BuyProduct;

/**
 *
 */
struct clientHash
{
    int operator()(const ClientInitial ci) const
    {
        int v = 0;
        for (int i = 0; i < ci.getClient()->getName().length(); i++)
            v = 37*v + ci.getClient()->getName()[i];
        return v;
    }
    bool operator() (const ClientInitial& ci1, const ClientInitial& ci2) const
    {
        return ci1.getInitial() == ci2.getInitial();
    }
};

/**
 * ## Client Hash Table
 */
typedef std::unordered_set<ClientInitial, clientHash, clientHash> tabHClient;


typedef std::priority_queue<BuyProduct> HeapProd;

/**
 * ## Template function
 * Inserts the element T in the vector of pointers of objects T
 * @param element an object T
 * @param vec a vector of pointers of objects T
*/
template<class T>
bool addElement(T* element, std::vector<T*>* vec)
{
    for (auto & i : *vec)
        if ((*element) == (*i)) return false; // returns false is element already exists in vector
    vec->push_back(element);
    return true;
}

/**
 * Class DataBase
 * Class to create the database of the system
 * Where all the data is saved while the program is running
*/
class DataBase {
    std::vector<Client*> clients;                         ///< private vector to save all the information about the clients

    std::vector<Room*> rooms;                             ///< private vector to save all the information about the rooms

    std:: vector<NoViewRoom*> no_view_rooms;              ///< private vector to save all the information about the rooms that no have view

    std:: vector<ViewRoom*> view_rooms;                   ///< private vector to save all the information about the rooms that have view

    std:: vector<SuiteRoom*> suite_rooms;                 ///< private vector to save all the information about the suits

    std::vector<Employee*> employees;                     ///< private vector to save all the information about the employees

    std::vector<Product*> stock_products;                 ///< private vector to save all the information about the stock_products

    std::vector<Book*> books;                             ///< private vector to save all the information about the reservations

    std::vector<Book*> temporary_books;                   ///< private vector to save all the information about the temporary reservations

    tabHClient frequent_clients;                          ///< private hashtable that stores clients with more than 2 previous stays in the hotel

    std::priority_queue<BuyProduct> buy_products;         ///< private priority queue that stores products to be bought

    std::priority_queue<BuyProduct> shop_inf_stock;       ///< private priority queue that stores an infinite stock of products

    BST<Vehicle *> vehicles_list;                         ///< private binary tree that stores pointers to vehicles

    BST<Vehicle *> vehicles_stock_inf;                    ///< private binary tree that stores an infinite stock of pointers to vehicles

    BST<Vehicle *> vehicles_to_deliver;                   ///< private binary tree that stores pointers to vehicles that need to be delivered

    int products_costs;                                   ///< private integer saves the total cost of bought products

    bool employees_payment;                               ///< private boolean payment of salaries should be set to true in the end of the month

public:

    /**
     * Default DataBase construct
    */
    DataBase();

    /**
     * Class Function
     * returns vector with all the employees which have salary  == argument salary
     * @param salary argument to search
    */
    std::vector<Employee*> findEmployeeBySalary(double salary);

    /**
     * Class Function
     * returns vector with all the employees which have role  == argument role
     * @param role : argument to search
    */
    std::vector<Employee*> findEmployeeByRole(std::string role);

    /**
     * Class function
     * Calculates the total cost of the month
    */
    double totalCostMonth();

    /**
     * Class function
     * Calculates the total profit
    */
    double calculateProfit();

    /**
     * Returns the number of days between in_date and out_date
     * Used to perform calculations useful to books
     * @param out_date
     * @param in_date
     * @return
     */
    unsigned int calculateBookDays(std::vector<unsigned int> out_date, std::vector<unsigned int> in_date);

    /**
     * Class function
     * Adds the employee in the employees' vector
     * @param employee : pointer to the employee to add
    */
    bool addEmployeeElement(Employee* employee);

    /**
     * Class function
     * Adds the room in the room's vector
     * @param room : pointer to the room to add
    */
    bool addRoomElement(Room *room);

    void addFrequentClient(ClientInitial ci);

    void resetBuyProducts();

    /**
     * Increments vehicles kms
     * @param kms
     * @param v
     */
    void updateKms(int kms, Vehicle*v);

    /**
     *
     * @param people
     * @return best vehicle with the mininum capacity of people
     */
    Vehicle * bestVehicle(int people);

    /**
     * Transfers vehicles with 5000+ kms from vehicles_list to vehicles_to_deliver
     */
    void vehiclesToDeliver();

    /**
     * Removes vehicles from vehicles_to_deliver
     * @param v
     */
    void deliverVehicles(Vehicle *v);

    /**
     * Adds product to temp priority queue
     * Removes it from buy_products
     * @param no_product
     */
    void buyChosenProduct(int no_product);

    /**
     * Buy product on top of the queue
     */
    void buyTopProduct();

    /**
     * Buys products according to productStockInterval() output
     * @param min
     * @param max
     * @return
     */
    bool buyProductInInterval(int min, int max);

    /**
     * Checks if product stock is between min and max values
     * @param min
     * @param max
     * @param bp
     * @return boolean
     */
    static bool productStockInterval(int min, int max, BuyProduct bp);

    /**
     * Checks which products are missing
     * @return array of products to buy
     */
    array<int,2> missingProducts();

    /**
     * Resets the vehicles in vehicles_list
     */
    void resetVehicles();

    /**
     * Allows manager to apply Christmas promotion to frequent clients with given initial
     * @param initial
     * @return
     */
    bool applyPromotionByInitial(char initial);

    /*
     * Getters & Setters
     */
    std::vector<Client*> getClients() const;               ///< Returns the private vector clients

    std::vector<Room*> getRooms() const;                   ///< Returns the private vector rooms

    std::vector<Employee*> getEmployees() const;           ///< Returns the private vector employees

    std::vector<Product*> getStock_products() const;       ///< Returns the private vector stock_products

    std::priority_queue<BuyProduct> getBuy_products();     ///< Returns the private buy_products

    std::vector<Book*> getBooks() const;                   ///< Returns the private vector books

    std::vector<Book*> getTemp_books() const;              ///< Returns the private vector temporary_books

    std::vector<Client*>* getPointerClients();

    std::vector<Product *>* getPointerStock_products();

    std::vector<Book *>* getPointerBooks();

    std::vector<Book *>* getPointerTemp_books();

    std::priority_queue<BuyProduct> * getPointerBuy_products();

    std::priority_queue<BuyProduct>* getPointerShopInfStock();

    tabHClient getFrequent_clients(){return frequent_clients;};

    BST<Vehicle*> * getPointerVehicles_list();

    BST<Vehicle*> getVehiclesToDeliver();

    BST<Vehicle*>* getPointerVehicle_stock_inf();

    int getProductsCosts() { return products_costs; }

    void setEmployeesPayment(bool ep);

    bool getEmployeesPayment();



};


#endif //GRANDE_HOTEL_CENTRAL_DATABASE_H
