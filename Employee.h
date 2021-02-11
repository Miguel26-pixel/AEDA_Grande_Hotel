//
// Created by migam on 10/27/2020.
//

#ifndef GRANDE_HOTEL_CENTRAL_EMPLOYEE_H
#define GRANDE_HOTEL_CENTRAL_EMPLOYEE_H

#include <iostream>
#include <vector>
#include <string>

class Book;

/**
 * Class Employee
 * Class to create employees
*/
class Employee {
    std::string name;                                           ///< private member string name of the employee ex. Miguel
    int nif;                                                    ///< private member int nif ex. 236758941
    int work_years;                                             ///< private member int work_years : number of years the employee has been working
    double salary;                                              ///< private member salary

public:

    Employee();
    /**
     * Employee constructor
     * @param name
     * @param nif
     * @param work_years
     * @param salary
    */
    Employee(std::string name, int nif, int work_years, double salary);

    /**
     * Default destructor
    */
    ~Employee();

    /**
     * Virtual class function
     * Return the role of the employee ex. Manager
    */
    virtual std::string employeeRole(){ return "Employee";};


    /**
     * Class function
     * Return the employee's name
    */
    std::string getName();

    /**
     * Class function
     * Return the nif
    */
    int getNIF();

    /**
     * Class function
     * Return the number of years the employee has worked already
    */
    int getWorkYears();

    /**
     * Class function
     * Return employee's salary
    */
    double getSalary();

    /**
     *
    */
    double getValuePromotion(std::string roomtype); //documentation not done

    /**
     * Class function
     * @param name
     * Set the employee's name as argument "name"
    */
    void setName(std::string name);

    /**
     * Class function
     * @param nif
     * Set the employee's nif as argument "nif"
    */
    void setNIF(int nif);

    /**
     * Class function
     * @param work_years
     * Set the employee's work_years as argument "work_years"
    */
    void setWorkYears(int work_years);

    /**
     * Class function
     * @param salary
     * Set the employee's salary as argument "salary"
    */
    void setSalary(double salary);

    /**
     * Class operator
     * @param employee
     * Compare two different employees
     * Return true if name and nif of the two are equal
    */
    bool operator == (Employee employee){
        return (employee.name == name && employee.nif == nif);
    }
};

/**
     * SubClass public of Employee
    */
class Reception : public Employee{
public:
    Reception();
    /**
     * Reception constructor
     * @param name
     * @param nif
     * @param work_years
     * @param salary
    */
    Reception(std::string name, int nif, int work_years, double salary);

    /**
     * Default reception constructor
    */
    ~Reception();


    /**
     * Virtual SubClass function
     * Return "Reception"
    */
    virtual std::string employeeRole(){  return "Reception"; };

};


/**
 * SubClass public of Reception
*/
class Responsible : public Reception{
    std::vector<int> floors;                                    ///< private vector of floors attributed to this responsible
public:
    Responsible();
    /**
     * Responsible constructor
     * @param name
     * @param nif
     * @param work_years
     * @param salary
    */
    Responsible(std::string name, int nif, int work_years, double salary);

    /**
     * Default responsible constructor
    */
    ~Responsible();

    /**
     * SubClass function
     * @param floor : floor to add into floors
    */
    void assignFloor(int floor);

    /**
     * SubClass function
     * @param floor : floor to remove from floors
    */
    void removeFloor(int floor);
 
    /**
     * Virtual SubClass function
     * Return "Responsible"
    */

    virtual std::string employeeRole(){ return "Responsible";};
};


/**
     * SubClass public of Employee
*/
class Cleaning : public Employee{
    std::string shift;                                          ///< private string shift : "day" or "night"
public:
    Cleaning();
    /**
     * SubClass Cleaning costructor
     * @param name
     * @param nif
     * @param work_years
     * @param salary
     * @param shift
    */
    Cleaning(std::string name, int nif, int work_years, double salary, std::string shift);

    /**
     * Default Cleaning constructor
    */
    ~Cleaning();

    /**
     * SubClass function
     * Change the shift :
     * "day" -> "night"
     * "night" -> "day"
    */
    void ChangeShift();

    /**
     * Virtual SubClass function
     * Return "Cleaning"
    */
    virtual std::string employeeRole(){ return "Cleaning"; };
};

/**
   * SubClass public of Employee
*/
class Manager : public Employee{
public:
    Manager();
    /**
     * SubClass Cleaning costructor
     * @param name
     * @param nif
     * @param work_years
     * @param salary
     * @param shift
    */
    Manager(std::string name, int nif, int work_years, double salary);

    /**
     * Default Manager constructor
    */
    ~Manager();
    
    /**
     * Virtual SubClass function
     * Return "Manager"
    */
    virtual std::string employeeRole(){ return "Manager";}

};


#endif //GRANDE_HOTEL_CENTRAL_EMPLOYEE_H
