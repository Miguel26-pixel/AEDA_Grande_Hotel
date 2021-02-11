//
// Created by migam on 10/27/2020.
//

#include "Employee.h"
#include "Book.h"
#include "Exception.h"

using namespace std;


/**
     * Employee constructor
    */
Employee::Employee(string name, int nif, int work_years, double salary) {
    this -> name = name;
    this -> nif = nif;
    this -> work_years = work_years;
    this -> salary = salary;
}

/**
     * Default destructor
    */
Employee::~Employee(){}

/**
     * Return the employee's name
    */
std::string Employee::getName(){
    return name;
}

/**
     * Return the nif
    */
int Employee::getNIF(){
    return nif;
}

/**
     * Return the number of years the employee has worked already
    */
int Employee::getWorkYears(){
    return work_years;
}

/**
     * Return employee's salary
    */
double Employee::getSalary(){
    return salary;
}

/**
     * SubClass public of Employee
    */
Reception::Reception(std::string name, int nif, int work_years, double salary) : Employee(name,nif,work_years,salary){}

/**
     * Default reception constructor
    */
Reception::~Reception() {}

Reception::Reception() {};

/**
     * Responsible constructor
    */
Responsible::Responsible(std::string name, int nif, int work_years, double salary) : Reception(name, nif, work_years, salary){}

/**
     * Default responsible constructor
    */
Responsible::~Responsible() {};

/**
     * SubClass Cleaning costructor
    */
Cleaning::Cleaning(std::string name, int nif, int work_years, double salary, std::string shift): Employee(name, nif, work_years, salary) {
    this -> shift = shift;
}

/**
     * Default Cleaning constructor
    */
Cleaning::~Cleaning() {}

/**
     * SubClass Cleaning costructor
    */
Manager::Manager(std::string Name, int NIF, int WorkYears, double Salary): Employee(Name,NIF,WorkYears,Salary){}

/**
     * Default Manager constructor
    */
Manager::~Manager() {}

Manager::Manager() {};


/**
     * @param floor : floor to add into floors
    */
void Responsible::assignFloor(int floor){

    for (int i=0; i<floors.size();i++){
        if(floors[i]==floor) {
            cout << "This floor has already been given";
            throw FloorAlreadyAssigned(floor);
        }
    }
    floors.push_back(floor);
}

/**
     * @param floor : floor to remove from floors
    */
void Responsible::removeFloor(int floor){
    try {
        vector<int>::iterator it;
        for (it = floors.begin(); it != floors.end(); it++)
            if (*it == floor) {
                floors.erase(it);
                cout << "This floor has been removed";
                return;
            }
        throw FloorNotAssigned(floor);

    } catch (FloorNotAssigned)
    { cout << "This floor is not assigned to this responsible"; }
}

Responsible::Responsible() {}

/**
     * "day" -> "night"
     * "night" -> "day"
    */
void Cleaning::ChangeShift(){
    if(shift=="day")
        shift="night";
    else
        shift="day";
}

Cleaning::Cleaning() {};



/*
 * Getters & Setters
 */

/**
     * Set the employee's name as argument "name"
    */
void Employee::setName(std::string name) {
    this -> name = name;
}

/**
     * Set the employee's nif as argument "nif"
    */
void Employee::setNIF(int nif) {
    this -> nif = nif;
}

/**
     * Set the employee's work_years as argument "work_years"
    */
void Employee::setWorkYears(int work_years) {
    this -> work_years = work_years;
}

/**
     * Set the employee's salary as argument "salary"
    */
void Employee::setSalary(double salary) {
    this -> salary = salary;
}

Employee::Employee() {

}


