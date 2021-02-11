//
// Created by aluis on 19/11/2020.
//

#include "UserInterface.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <climits>
#include <map>
#include "bst.h"
#include "binaryTree.h"
#include "ClientInitial.h"

using namespace std;

/**
* Default Class constructor
*/
UserInterface::UserInterface(){};


void UserInterface::login(DataBase *dataBase) {
    cout << "\nWELCOME TO GRANDE HOTEL CENTRAL" << endl;
    Login login;
    string name;
    int nif;
    cout << "\n----Authentication----" << endl;
    cout << "\nAttention: name must be only one word.\n";

    do{
        cout << "Name:";
        cin >> name;
        cin.ignore(INT_MAX, '\n');
        cout << "NIF:";
        cin >> nif;

        if (cin.fail()) {
            cout << "Invalid NIF.";
            cin.clear();
        }
        cin.ignore(INT_MAX, '\n');

    } while( cin.fail() || !login.userLogin(dataBase, name, nif) );
    user = login.getUser();
}

/**
* Show the action which one with index
* Return the index that the user chose
*/
int UserInterface::chooseAction(std::vector<std::string> actions) {
    bool manager_menu = false;
    if (actions.size()>3) {
        manager_menu = true;
        cout << endl << VIEW_OPTIONS;
    }

    for(int i = 0; i < actions.size(); i++){
        if (i == 7 && manager_menu) cout << endl << ACTIONS_OPTIONS;
        std::cout << "\n[" << i+1 << "] " << actions[i];}
    int action;
    cout << "Enter a number:\n";
    cin >> action;

    if (cin.fail()) {
        cout << "Invalid action number.";
        cin.clear();
    }
    cin.ignore(INT_MAX, '\n');
    return action;
}

/**
* Print all the information about the user
*/
void UserInterface::printPersonalFolder() {
    cout << "\n---- Personal Folder - " << user->getName() << "----\n";
    cout << "Name:" << user -> getName() << endl;
    cout << "NIF:" << std::to_string(user -> getNIF()) << endl;
    cout << "WorkYears:" << std::to_string(user -> getWorkYears()) << endl;
    cout << "Salary: " << std::to_string(user -> getSalary()) <<  endl;
}

void UserInterface::deliverVehicles() {

    dataBase->vehiclesToDeliver();
    BST<Vehicle*> vehicles_list = dataBase->getVehiclesToDeliver();


    if(vehicles_list.isEmpty()) {
        cout << "There are no vehicles to deliver";
        return;
    }
    BSTItrIn<Vehicle*> it(vehicles_list);

    cout << "These are the vehicles that need to be delivered:\n";

    int n = 1;
    while(!it.isAtEnd())
    {
        cout << "[" << n << "] ";
        cout << "Registration: " << it.retrieve()->getRegistration() << endl;
        cout << "KM: " << it.retrieve()->getKM() << endl;
        cout << "Number_Seats: " << it.retrieve()->getNumber_Seats() << endl;
        cout << "-------------------------------------\n";
        it.advance();
        n++;
    }

    int vehicle_to_deliver;
    cout << "\nEnter the number of the vehicle to deliver, or 0 to deliver them all\n";
    cin >> vehicle_to_deliver;
    BSTItrIn<Vehicle*> del(dataBase->getVehiclesToDeliver());
    if (vehicle_to_deliver == 0){
        Vehicle *v = NULL;
        dataBase->deliverVehicles(v);
        cout << "\nVehicles delivered with success.";
        return;
    }
    int count = 0;
    while(!del.isAtEnd()){
        count ++;
        if (count == vehicle_to_deliver){
            dataBase->deliverVehicles(del.retrieve());
            cout << "\nVehicle delivered with success.";
            return;
        }
        del.advance();
    }
}

void UserInterface::viewFinances() {

    Date* date1;
    Date* date2;

    string in_date, out_date;
    int day1, month1, year1, day2, month2, year2;

    cout << "Insert time interval --\n";
    cout << "\nDate: dd mm yyyy";

    cin.ignore(100,'\n');
    cout << "Begin date:";
    getline(cin, in_date);
    istringstream ss(in_date);
    ss >> day1 >> month1 >> year1;

    cin.clear();
    cout << "End date:";
    getline(cin, out_date);
    istringstream ss2(out_date);
    ss2 >> day2 >> month2 >> year2;

    *date1 = Date(day1, month1, year1);
    *date2 = Date(day2,month2, year2);

    try{
        dateValidation(date1,date2);
    } catch (InvalidDate) {
        cout << "Invalid Date.";
    }

    if (*date1 > *todayDate() || *date2 > *todayDate()) {
        cout << "You can only access finances for past date.\n";
        cout << todayDate()->day << " " << todayDate()->month << todayDate()->year << endl;
        viewFinances();
    }


    Finances finances = Finances(dataBase,date1,date2);
    cout << "These are the hotel finances for the given period:\n";
    cout << "Products costs: " << finances.getProducts_cost() <<" euros\n" ;
    cout << "Employees Salaries: " << finances.getSalaries_cost() <<" euros\n" ;
    cout << "Total expenses: " << finances.getTotal_cost() <<" euros\n" ;
    cout << "Earnings: " << finances.getBooking_profit() <<" euros\n" ;
    cout << "Total Profit: " << finances.getProfit() << " euros\n";
}

void UserInterface::showStockProducts() {
    vector<Product*> stock = dataBase->getStock_products();
    map<Product*,int> temp  = {};

    for (int i = 0; i < stock.size(); i++){
        if(temp.find(stock[i]) != temp.end()){
            temp[stock[i]] ++;
        }
        else {
            temp.insert(pair<Product*,int>(stock[i],1));
        }
    }
    map<Product*, int>::iterator it;

    int i = 1;
    for(it = temp.begin(); it != temp.end(); it++){
        cout <<  "[" << i+1 << "] Quantity: "<< (*it).second << " | Tipo: " << (*it).first->getType()<< " | Price: " <<
        (*it).first->getPrice() << " | Quality: " << (*it).first->getQuality() << '\n';
    cout << "--------------------------------------------------------\n";
    i++;
    }
}

void UserInterface::showFreqClients() {
    for (auto f : dataBase->getFrequent_clients()){
        cout << "Name: " << f.getClient()->getName() << " | NIF: " << f.getClient()->getIntNIF()
        << " | Promotion: " << f.getClient()->getPromotion() << endl;
    }
}

void UserInterface::printBooks(Search search) {

    string in_date;
    int day1, month1, year1;

    cout << "\nDate: dd mm yyyy";
    cin.ignore(100,'\n');
    cout << "Check-in date:";
    getline(cin, in_date);
    istringstream ss(in_date);
    ss >> day1 >> month1 >> year1;

    Date *date1 = new Date(day1, month1, year1);
    if (search.dayBooks(*date1).empty()){
        cout << "There are no reservations on this check-in date.\n";
        return;
    }
    for (auto b: search.dayBooks(*date1)){
        cout << "Name: " << b->getClient()->getName() << endl;
        cout << "Nif: " << b->getClient()->getIntNIF() << endl;
        cout << "Room: " << b->getRoom()->getFloor() <<  b->getRoom()->getNumber()<< endl;
        cout << "Price: " << b->getReservation_price() << endl;
        cout << "-------------------------------------------------------\n";
    }
}

Vehicle UserInterface::reserveVehicle(unsigned kms, unsigned num_people) {
    Vehicle *v = dataBase->bestVehicle(num_people);
    dataBase->updateKms(kms, v);
    return (*v);
}

void UserInterface::applyChristmasPromotion() {
    cout << "The promotion will be applied to two groups of clients whose name first letters are the ones entered:\n";
    char i1, i2;
    cout << "Initials must be written in uppercase.\n" << "Initial 1:";
    cin >> i1;
    while(cin.fail() ||!(i1 >= 'A' && i1 <= 'Z')){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Please, insert a valid initial char.\n";
        cin >> i1;
    }
    cout << "Initial 2:";
    cin >> i2;
    while(cin.fail() || i2 == i1 || !(i2 >= 'A' && i2 <= 'Z')){
        cin.clear();
        cin.ignore(1000,'\n');
        if (i2 == i1) cout << "Please, insert an initial char other than the first:\n";
        else {cout << "Please, insert a valid initial char.\n";}
        cin >> i2;
    }

    if (! dataBase->applyPromotionByInitial(i1) ) {
        cout << "The system couldn't find clients with the given initial 1: " << i1;}
    else {cout << "The promotion was applied to the frequent clients whose name starts in "<< i1 << endl;}
    if (! dataBase->applyPromotionByInitial(i2) ) {
        cout << "The system couldn't find clients with the given initial 2: " << i2;}
    else {cout << "The promotion was applied to the frequent clients whose name starts in "<< i2 << endl;}
}

/**
 * Create new reservation
 * Check if Client already exists in dataBase
 * If not creates a new one
 * Creates a new object Book
 *
*/
void UserInterface::createReservation() {
    cout << "---- BOOKING ----";
    cout << "\nInsert Client information";

    string name;
    unsigned int nif, group_size;
    cout << "\nName:" ; cin >> name;
    cout << "NIF:" ; cin >> nif;
    cout << "Number of visitants:" ; cin >> group_size;

    try{ nifValidation(nif);
    } catch (InvalidNifException) {
        std::cout << "\nInvalid NIF.";
        return;
    }

    Client * client = new Client(name, group_size, nif, 1);

    if (!addElement(client, (dataBase->getPointerClients()))) // if client already exists in dataBase
        for (auto & it_client : *dataBase->getPointerClients())
            if(*it_client == *client) {
                if(it_client->incrementStays()){
                    ClientInitial ci(client->getName()[0],client);
                    dataBase->addFrequentClient(ci);
                }
            }

    cout << "Insert Booking dates --";
    cout << "\nDate: dd mm yyyy";

    int day1, month1, year1;
    string in_date;

    cin.ignore(100,'\n');
    cout <<"\nCheck-in date:";
    getline(cin, in_date);
    istringstream ss(in_date);
    ss >> day1 >> month1 >> year1;

    cin.clear();
    int day2, month2, year2;
    string out_date;
    cout << "Check-out date:";
    getline(cin, out_date);
    istringstream ss2(out_date);
    ss2 >> day2 >> month2 >> year2;

    Date * today = todayDate();

    try {
        try{
            Book* book = new Book(client, dataBase, day1, month1, year1, day2, month2, year2, today);
            addElement(book,dataBase->getPointerTemp_books());
            int answer;
            cout << "\nShuttle service to the airport?\n[1] Yes [2] No\n";
            cin >> answer;
            while(cin.fail() || (answer != 1 && answer != 2) ){
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "Please, 1 -> yes, 2 -> no.";
                cin >> answer;
            }

            //reserva um transporte,
            if(answer == 1) {
                int kms = 20; //constante hotel-airport;
                Vehicle v = reserveVehicle(kms, group_size); //retira o veículo da bst com menor kms
                cout << "Vehicles reserved with success.\n";
                cout << "Vehicles registrations: " << v.getRegistration() << endl;

            }
            cout << "Reservation made with success.\n";
        }
        catch(NoRoomsAvailable){
            cout << "The system could not find available rooms.";};

    } catch (InvalidDate) {
        std::cout << "Invalid dates, keep in mind that check-out must be after check-in.";
    }
}


void UserInterface::finishReservation() {
    cout << "-----------------------------------------------------" << std::endl;
    cout << "Name: " << dataBase->getTemp_books()[0]->getClient()->getName() << endl;
    cout << "RoomType: " << dataBase->getTemp_books()[0]->getRoom()->RoomType() << endl;
    cout << "RoomID: " << dataBase->getTemp_books()[0]->getRoom()->getFloor() <<
         dataBase->getTemp_books()[0]->getRoom()->getNumber() << endl;
    cout << "-----------------------------------------------------" << std::endl;
    setPromotion(dataBase->getTemp_books()[0]);
    addElement(dataBase->getTemp_books()[0],dataBase->getPointerBooks());
    dataBase->getPointerTemp_books()->erase(dataBase->getPointerTemp_books()->begin());
}

void UserInterface::showEmployees(Search search) {
    cout << "[1] Visualize all employees\n[2] Visualize Employees sorted by salary\n[3] Find employees by role\n";
    int answer;
    cin >> answer;
    while(cin.fail() || (answer != 1 && answer != 2 && answer != 3) ){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Please, insert a valid number.";
        cin >> answer;
    }

    if (answer == 1){
        for(auto e: dataBase->getEmployees()){
            cout << "Name: " << e->getName() << endl;
            cout << "NIF: " << e->getNIF() << endl;
            cout << "Role: " << e->employeeRole() << endl;
            cout << "Salary: " << e->getSalary() << endl;
            cout << "----------------------------------------\n";
        }
    }

    else if(answer == 2){
        for(auto e: search.sortEmployeesBySalary()){
            cout << "Salary: " << e->getSalary() << endl;
            cout << "Name: " << e->getName() << endl;
            cout << "NIF: " << e->getNIF() << endl;
            cout << "Role: " << e->employeeRole() << endl;
            cout << "----------------------------------------\n";
        }
    }

    else{
        string role;
        cout << "Role: ";
        cin >> role;
        while (role != "Manager" && role != "Cleaning" && role != "Responsible" && role != "Reception" ){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please, enter a valid role.\n";
            cin >> role;
        }
        for(auto e: search.findEmployeeByRole(role)){
            cout << "Name: " << e->getName() << endl;
            cout << "NIF: " << e->getNIF() << endl;
            cout << "Salary: " << e->getSalary() << endl;
            cout << "----------------------------------------\n";
        }
    }
}

/**
 * Create the employee with the inputs
 */
void UserInterface::createEmployee() {
    cout << "\n---- Manager - Adding Employee ----";
    cout << "\nInsert Employee's information --";
    string name, role, shift;
    unsigned int nif, salary;
    cin.ignore(100,'\n');
    cout << "\nName: " ; getline(cin, name);
    cout << "NIF: " ; cin >> nif;
    cout << "Role: " ; cin >> role;
    cout << "Salary: " ; cin >> salary;

    if (role == "Cleaning"){
        cout << "\nShift"; cin >> shift;
        Cleaning* cleaning = new Cleaning(name, nif,0,salary,shift);
        dataBase->addEmployeeElement(cleaning);
    }
    else if (role == "Responsible"){
        Responsible* responsible = new Responsible(name, nif, 0,salary);
        dataBase->addEmployeeElement(responsible);
    }
    else if (role == "Reception"){
        Reception* reception = new Reception(name,nif,0,salary);
        dataBase->addEmployeeElement(reception);
    }
    else cout << "\nThere is no employee position for the given name.";
}

/**
* Calculates the the price of the reservation
*/
void UserInterface::setPromotion(Book *book) {
    double total = 0;
    double promotion = 0;
    int answer = 0;
    int book_days = book->getCheckout_date() - book->getCheckin_date();
    if (!(book->getClient()->getOld_Client())) {
        if (book->getClient()->getStays() > 2 ){
            double promo = book->getClient()->getPromotion();
            if (promo == 0 && is_christmas){
                cout << "This is a frequent client. You can apply him a promotion\n";
            }
            if (promo != 0) cout << "This is a frequent client that already has a promotion"
                                                                "of " << promo << endl;
        }
        while (answer != 1 && answer != 2) {
            cout << "Would you like to apply a promotion (" << book->getRoom()->getPromotion()
                 << ")to this reservation?  \n[1] Yes [2] No\n" << endl;
            cin >> answer;
            //input validation needed
            if (answer == 1) {
                total += book->getRoom()->getBase_price() - book->getRoom()->getBase_price() * promotion;
                book->setReservation_price(total * book_days);
                cout << "\nPromotion applied with success.";
            }
            else if (answer != 2)
                cout << "\nInvalid answer.";
        }
    }
    book->setReservation_price(book->getRoom()->getBase_price() * book_days);
    cout << "\nThe final price for this reservation is " << book->getReservation_price() << endl;
}

void UserInterface::changeRating() {

    priority_queue<BuyProduct> temp;
    if(dataBase->getPointerBuy_products()->size()==0){
        cout << "The catalog is empty.";
        return;
    }
    for (int i = 0; i < dataBase->getPointerBuy_products()->size(); i++){
        BuyProduct bp = dataBase->getPointerBuy_products()->top();
        temp.push(bp);
        cout << "[" << i+1 << "]" << "Tipo: " << bp.getProduct()->getType()<< " | Price: " <<
             bp.getProduct()->getPrice() << " | Quality: " << bp.getProduct()->getQuality() <<
             " | Provider: " << bp.getProvider() <<
             " | Rating: " << bp.getRating() <<
             " | Stock: " << bp.getValueStock()<<"\n";

        dataBase->getPointerBuy_products()->pop();
    }

    int chosen_bp, new_rating;
    cout << "\nChoose the product which rating you want to change. If you do not want to to change the rating, enter 0.";
    cin >> chosen_bp;
    if (chosen_bp == 0) return;

    cout << "New Rating:";
    cin >> new_rating;

    for(int i = 0; i<temp.size(); i++){
        if(i == chosen_bp){
            BuyProduct bp(dataBase,temp.top().getProduct(),temp.top().getProvider(),new_rating,temp.top().getValueStock());
            temp.pop();
            dataBase->getPointerBuy_products()->push(bp);
        }
        else{
            dataBase->getPointerBuy_products()->push(temp.top());
            temp.pop();
        }
    }
}

/**
* Buy the products and see the cost of them
*/
void UserInterface::buyProducts(Search* search) {

    priority_queue<BuyProduct> temp;
    if(dataBase->getPointerBuy_products()->size() == 0){
        cout << "The catalog is empty.\n";
        return;
    }
    cout<< "Catalog:\n";

    for (int i = 0; !dataBase->getPointerBuy_products()->empty(); i++){
        BuyProduct bp = dataBase->getPointerBuy_products()->top();
        temp.push(bp);
        cout << "[" << i+1 << "]" << "Tipo: " << bp.getProduct()->getType()<< " | Price: " <<
             bp.getProduct()->getPrice() << " | Quality: " << bp.getProduct()->getQuality() <<
             " | Provider: " << bp.getProvider() <<
             " | Rating: " << bp.getRating() <<
             " | Stock: " << bp.getValueStock()<<"\n";

        dataBase->getPointerBuy_products()->pop();
    }
    cout << "--------------------------------------------------------\n";

    while(!temp.empty()){
        dataBase->getPointerBuy_products()->push(temp.top());
        temp.pop();
    }
    cout << "[0] Leave without buying.\n[1] Choose one product to buy\n[2] Buy the product with best rating\n[3] Buy products with stock between two specific values.\n";
    int answer;
    cin >> answer;
    while(cin.fail() || (answer != 1 && answer != 2 && answer != 3 && answer != 0) ){
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Please, insert a valid number.";
        cin >> answer;
    }

    if(answer==0){ return;};

    if (answer == 1){
        int number;
        cout << "Enter the number of the product you want to buy.";
        cin >> number;
        dataBase->buyChosenProduct(number);
        cout << "Product purchased with success";
    }
    if (answer == 2){
        cout << "Type: " << dataBase->getBuy_products().top().getProduct()->getType() << " Price: " <<
             dataBase->getBuy_products().top().getProduct()->getPrice() << " Rating: " << dataBase->getBuy_products().top().getRating() <<
             " Stock: " << dataBase->getBuy_products().top().getValueStock();
        dataBase->buyTopProduct();
        cout << "\nThis product was purchased with success.";

    }
    if(answer == 3){
        //copia priority para temporário

        int min, max;
        cout << "Enter the min value:"; cin >> min;
        cout << "Enter the max value:"; cin >> max;

        if(!dataBase->buyProductInInterval(min,max)){
            cout << "There are no buy products with stocks between the given values.\n";
            return;
        }
        cout << "Products purchased with success.";
    }
}

void UserInterface::showVehicles() {
    dataBase->vehiclesToDeliver();
    BST<Vehicle *> *vehicles_list = dataBase->getPointerVehicles_list();
    BSTItrIn<Vehicle *> it(*vehicles_list);
    int c = 0;
    while (!it.isAtEnd()) {
        cout << "Registration: " << it.retrieve()->getRegistration() << endl;
        cout << "KM: " << it.retrieve()->getKM() << endl;
        cout << "Number_Seats: " << it.retrieve()->getNumber_Seats() << endl;
        cout << "-------------------------------------\n";
        it.advance();
    }
}

void UserInterface::managerWarnings() {
    int count_vehicles = 0;
    dataBase->vehiclesToDeliver();
    BSTItrIn<Vehicle*> it(dataBase->getVehiclesToDeliver());
    while(!it.isAtEnd()){
        count_vehicles++;
        it.advance();
    }
    cout << endl;
    if(count_vehicles)  cout<< "~ " << count_vehicles << " vehicle(s) must be delivered.\n";

    if(!dataBase->getTemp_books().empty()) cout << "~ " << dataBase->getTemp_books().size() << " book(s) must be finished.\n";

    if (dataBase->missingProducts()[0] > 0) cout << "~ " << dataBase->missingProducts()[0] << " hygiene product(s) must be purchased.\n";

    if (dataBase->missingProducts()[1] > 0) cout << "~ " << dataBase->missingProducts()[1] << " cleaning product(s) must be purchased.\n";

    if(is_christmas) cout << "!It is Christmas! You must apply a promotion to old clients.\n";

    if(is_end_of_the_month) cout << "!It is End of the Month! You must pay the salaries.\n";

}

void UserInterface::cleaning() {
    int exit_flag = 1;
    do{
        cout << "\n----Cleaning - " << user->getName() << " ----";
        cout << "\nInsert what you want to do:";
        switch (chooseAction(cleaning_actions)) {
            case PERSONAL_FOLDER: //personal folder
                printPersonalFolder();
                break;
            case LOG_OUT(2): // logout
                return;
            default:
                cout << "\nInvalid action, choose a number from 1 to " << cleaning_actions.size() << endl;
        }
        cout << "\n\nWould you like to do anything else before leaving? \n[1] Yes [2] No\n";
        cin >> exit_flag;
    } while(!(exit_flag-1));
}

void UserInterface::responsible() {
    int exit_flag = 1;
    do{
    cout << "\n----Responsible - "<< user->getName() << " ----";
    cout << "\nInsert what you want to do:";

    switch(chooseAction(responsible_actions)){
        case PERSONAL_FOLDER: //personal folder
            printPersonalFolder();
            break;
        case LOG_OUT(2): //logout
            return;
        default:
            cout << "\nInvalid action, choose a number from 1 to " << responsible_actions.size() << endl;
    }
        cout << "\n\nWould you like to do anything else before leaving? \n[1] Yes [2] No\n";
        cin >> exit_flag;
    } while(!(exit_flag-1));
}

void UserInterface::reception(){
    int exit_flag = 1;
    do{
        cout << "\n---- Reception - "<< user->getName() << " ----";
        cout << "\nInsert what you want to do:";
        switch(chooseAction(reception_actions)){
            case PERSONAL_FOLDER: //personal fold
                printPersonalFolder();
                break;
            case BOOK:
                createReservation();
                break;
            case LOG_OUT(3):
                return;
            default:
                cout << "\nInvalid action, choose a number from 1 to " << reception_actions.size() << endl;
        }

        cout << "\n\nWould you like to do anything else before leaving? \n[1] Yes [2] No\n";
        cin >> exit_flag;
    } while(!(exit_flag-1));
}

void UserInterface::manager() {
    Search search1 = Search(*dataBase);
    int exit_flag = 1;
    string in_date = "", out_date= "";
    do{
        cout << "\n---- Manager - "<< user->getName() << " ----";
        managerWarnings();
        cout << "\nInsert what you want to do:";

        switch(chooseAction(manager_actions)){

            case PERSONAL_FOLDER:
                printPersonalFolder();
                break;

            case SEE_EMPLOYEES:
                showEmployees(search1);
                break;

            case BOOKS_PER_DAY:
                if (dataBase->getBooks().empty()) {
                    cout << "There are no reservations.";
                    break;
                }
                else{
                    printBooks(search1);
                }
                break;

            case STOCK_PRODUCTS:
                showStockProducts();
                break;

            case FINANCES:
                viewFinances();
                break;

            case SHOW_VEHICLES:
                if(dataBase->getPointerVehicles_list()->isEmpty()){
                    dataBase->resetVehicles();
                    cout << "The vehicles shop was reset.\n";
                }
                showVehicles();
                break;

            case FREQ_CLIENTS:
                showFreqClients();
                break;

            case FINISH_BOOK:
                if (dataBase->getTemp_books().empty()){
                    cout << "\nThere are no unfinished reservations.";
                    break;
                }
                cout << "There are " << dataBase->getTemp_books().size() << " unfinished reservations.\n";
                while(!(dataBase->getTemp_books().empty())) {
                    finishReservation();
                }
                break;

            case ADD_PRODUCTS:
                if(dataBase->getBuy_products().empty()){
                    dataBase->resetBuyProducts();
                    cout << "The catalog was reset.\n";
                }
                buyProducts(&search1);
                break;

            case CHANGE_RATING:
                if(dataBase->getBuy_products().empty()){
                    dataBase->resetBuyProducts();
                    cout << "The catalog was reset.\n";
                }
                changeRating();
                break;

            case ADD_EMPLOYEES:
                createEmployee();
                break;

            case PAY_SALARIES:
                if(!is_end_of_the_month) cout << "You can't pay salaries right now (only at the end of the month)\n";
                else{
                    dataBase->setEmployeesPayment(true);
                    cout << "Salaries payed.";
                }
                break;

            case DELIVER_VEHICLES:
                deliverVehicles();
                break;

            case APPLY_C_PROMO:
                if (!is_christmas) cout << "You can't apply Christmas Promotion right now (only when it's Christmas!).\n";
                else {
                    applyChristmasPromotion();
                }
                break;

            case UPDATE_HOTEL_DB:
                updateRoomsFile(dataBase->getRooms());
                updateClientsFile(dataBase->getClients());
                updateEmployeesFile(dataBase->getEmployees());
                updateBookFile(dataBase->getBooks());
                updateProductStockFile(dataBase->getStock_products());
                updateProductToBuyFile(dataBase->getBuy_products());
                updateVehiclesFile(*dataBase->getPointerVehicles_list());
                cout << "Files updated.\n";
                break;

            case LOG_OUT(16):
                return;

            default:
                cout << "\nInvalid action, choose a number from 1 to " << manager_actions.size() << endl;
        }

        cout << "\n\nWould you like to do anything else before leaving? \n[1] Yes [2] No\n";
        cin >> exit_flag;
    } while(exit_flag!=2);
}

/**
 * Return the user
 */
Employee *UserInterface::getUser() const {
    return user;
}

/**
 * Set the database of this UserInterface
 */
void UserInterface::setDataBase(DataBase *dataBase) {
    this -> dataBase = dataBase;
}



