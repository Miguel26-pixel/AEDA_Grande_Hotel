//
// Created by marga on 28/10/2020.
//

#include "DataBase.h"
#include "Employee.h"
#include "Book.h"
#include "Files.h"
#include "InputValidation.h"
#include "Vehicle.h"

#include <vector>
#include <array>
#include <queue>
#include <math.h>
#include <string>

struct Date;
using namespace std;


DataBase::DataBase():vehicles_to_deliver(NULL), vehicles_list(NULL), vehicles_stock_inf(NULL)
{
    clients.clear();
    employees.clear();
    rooms.clear();
    stock_products.clear();
    books.clear();
    temporary_books.clear();
    frequent_clients.clear();
}

bool DataBase::addRoomElement(Room *room) {
    for (auto & i : rooms)
        if (*room == (*i)) return false;
    rooms.push_back(room);
    return true;
}

bool DataBase::addEmployeeElement(Employee* employee) {
    for (auto & i : employees)
        if (*employee == (*i)) return false;
    employees.push_back(employee);
    return true;
}


void DataBase::resetBuyProducts() {
    buy_products = shop_inf_stock;
}

void DataBase::resetVehicles() {
    vehicles_list = vehicles_stock_inf;
}

void DataBase::addFrequentClient(ClientInitial ci)
{
    Client *c = ci.getClient();
    if(frequent_clients.find(ci) == frequent_clients.end()){
        frequent_clients.insert(ci);
    }
    ci = *frequent_clients.find(ci);
    ci.addClientsCoincident(c);
    frequent_clients.insert(ci);
}

bool DataBase::applyPromotionByInitial(char initial) {
    bool found = false;
    for(const auto& fci : frequent_clients){
        if(fci.getInitial() == initial){
            for(auto c : fci.getClientsCoincident()){
                c->setPromotion(0.02);
            }
            found = true;
        }
    }
    return found;
}



Vehicle * DataBase::bestVehicle(int people)
{
    BSTItrIn<Vehicle *> it(vehicles_list);
    while(!it.isAtEnd())
    {
        if(it.retrieve()->getNumber_Seats()>=people)
            return it.retrieve();
        it.advance();
    }
    return new Vehicle("",0,0); //throw exception
}

void DataBase::updateKms(int kms, Vehicle *v) {
    BSTItrIn<Vehicle *> it(vehicles_list);
    while(!it.isAtEnd())
    {
        if(it.retrieve()==v)
            break;
        it.advance();
    }

    Vehicle *v2 = new Vehicle(it.retrieve()->getRegistration(), it.retrieve()->getKM(), it.retrieve()->getNumber_Seats());

    v2->addKM(kms);
    vehicles_list.remove(it.retrieve());
    vehicles_list.insert(v2);
}

void DataBase::vehiclesToDeliver(){
    BSTItrIn<Vehicle *> it(vehicles_list);
    while(!it.isAtEnd())
    {
        if(it.retrieve()->getKM()>=5000){
            vehicles_to_deliver.insert(it.retrieve());
            vehicles_list.remove(it.retrieve());
        }
        it.advance();
    }
}

void DataBase::deliverVehicles(Vehicle * v){
    BSTItrIn<Vehicle *> it(vehicles_to_deliver);
    Vehicle * empty = nullptr;
    //case deliver all
    if (v == empty) {
        while(!it.isAtEnd())
        {
            vehicles_to_deliver.remove(it.retrieve());
            it.advance();
        }
    }

    while(!it.isAtEnd())
    {
        if(it.retrieve()==v){
            vehicles_to_deliver.remove(it.retrieve());
            break;
        }
        it.advance();
    }
}

void DataBase::buyTopProduct() {
    int n = 0;
    while(n < buy_products.top().getValueStock()){
        stock_products.push_back(buy_products.top().getProduct());
        products_costs += buy_products.top().getProduct()->getPrice();
        n++;
    }
    buy_products.pop();
}

void DataBase::buyChosenProduct(int no_product_selected) {
    priority_queue<BuyProduct> temp;
    //copia priority para temporário
    for (int i = 0; !buy_products.empty(); i++){
        temp.push(buy_products.top());
        products_costs += buy_products.top().getProduct()->getPrice();
        buy_products.pop();
    }

    //procura on numero pedido e retira-o da priority queue e guarda no stock do hotel
    for(int i = 0; !temp.empty(); i++){
        cout << "a";
        if(i != no_product_selected-1)
            buy_products.push(temp.top());
        else{
            int n = 0;
            while(n < temp.top().getValueStock()){
                stock_products.push_back(temp.top().getProduct());
                products_costs += temp.top().getProduct()->getPrice();
                n++;
            }
        }
        temp.pop();
    }
}

bool DataBase::productStockInterval(int min, int max, BuyProduct bp) {
    return bp.getValueStock()>=min && bp.getValueStock()<=max;
}


bool DataBase::buyProductInInterval(int min,int max) {
    priority_queue<BuyProduct> temp;
    bool find = false;

    int count_products = 0;
    for (int i = 0; !buy_products.empty(); i++){
        temp.push(buy_products.top());
        buy_products.pop();
    }
    while(!temp.empty()){
        BuyProduct bp = temp.top();
        if(productStockInterval(min,max,bp)){
                int n = 0;
                while(n < bp.getValueStock()){
                    stock_products.push_back(temp.top().getProduct());
                    products_costs += temp.top().getProduct()->getPrice();
                    n++;
                }
                count_products++;
                find = true;
        }
        else{
            buy_products.push(temp.top());
        }
        temp.pop();
    }
    return find;
}

array<int,2> DataBase::missingProducts() {
    int hygiene_needed = 0, cleaning_needed = 0;
    int hygiene_stock = 0, cleaning_stock = 0;
    for (auto b : books){
        hygiene_needed +=  b->hygieneProductsNeeded();
        cleaning_needed += b->cleaningProductsNeeded();
    }
    int hygiene_missing = 0, cleaning_missing = 0;
    for (auto p: stock_products){
        if (p->getType() == "Hygiene") hygiene_stock++;
        else if (p->getType()=="Cleaning") cleaning_stock++;
    }

    hygiene_missing = hygiene_needed - hygiene_stock;
    cleaning_missing = cleaning_needed - cleaning_stock;
    return {hygiene_missing,cleaning_missing};
}

/*
 * Getters & Setters
 */

std::vector<Room*> DataBase::getRooms() const {return rooms;}

std::vector<Employee*> DataBase::getEmployees()const {return employees;}

std::vector<Client*>* DataBase::getPointerClients() {return &clients;}

std::vector<Product *>* DataBase::getPointerStock_products(){return &stock_products;}

std::priority_queue<BuyProduct> * DataBase::getPointerBuy_products() {return &buy_products;}

std::vector<Book *>* DataBase::getPointerBooks() {return &books;}

std::vector<Book *>* DataBase::getPointerTemp_books() {return &temporary_books;}

std::vector<Book *> DataBase::getBooks() const {
    return books;
}

vector<Product *> DataBase::getStock_products() const {
    return stock_products;
}

std::vector<Client *> DataBase::getClients() const {
    return clients;
}

std::vector<Book *> DataBase::getTemp_books() const {
    return temporary_books;
}

priority_queue<BuyProduct> DataBase::getBuy_products() {
    return buy_products;
}

priority_queue<BuyProduct> * DataBase::getPointerShopInfStock() {
    return &shop_inf_stock;
}

BST<Vehicle *> * DataBase::getPointerVehicles_list() {
    return &vehicles_list;
}

BST<Vehicle *> DataBase::getVehiclesToDeliver() {
    return vehicles_to_deliver;
}

BST<Vehicle *>* DataBase::getPointerVehicle_stock_inf() {
    return &vehicles_stock_inf;
}

void DataBase::setEmployeesPayment(bool ep) {
    employees_payment = ep;
}

bool DataBase::getEmployeesPayment() {
    return employees_payment;
}








