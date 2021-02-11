//
// Created by migam on 11/17/2020.
//

#include "Files.h"
#include "Client.h"
#include "Employee.h"
#include "Product.h"
#include "Room.h"
#include "Book.h"
#include "Date.h"



using namespace std;

template <class T>
void loadRoom(T *room, ifstream &rooms_file){
    stringstream ss;
    string line, st1;
    int num1 = 0 , num2 = 0;
    for (int i = 0; i < 4; i++)
    {
        getline(rooms_file, line);
        ss = std::stringstream(line);

        if ( i == ROOM_ID){
            ss >> st1 >>num1;
            room->setFloor(num1/10);
            room->setNumber(num1%10);
        }
        if ( i == ROOM_AVAILABLE ){
            ss >> st1 >> num1;
            room->setAvailable(num1);
        }
        if ( i == ROOM_CAPACITY){
            ss >> st1 >> num1;
            room->setCapacity(num1);
        }
    }

}

template <class T>
void loadBookRoom(T *room, ifstream &rooms_file){
    stringstream ss;
    string line, st1;
    int num1 = 0 ;
    for (int i = 0; i < 3; i++)
    {
        getline(rooms_file, line);
        ss = std::stringstream(line);

        if ( i == ROOM_ID){
            ss >> st1 >>num1;
            room->setFloor(num1 / 10);
            room->setNumber(num1 % 10);
        }
        if ( i == ROOM_CAPACITY){
            ss >> st1 >> num1;
            room->setAvailable(num1);
        }
        if ( i == ROOM_AVAILABLE){
            ss >> st1 >> num1;
            room->setCapacity(num1);
        }
    }

}

template <class T>
void loadEmployee(T *employee, ifstream &employees_file){
    stringstream ss;
    string line, st1, st2;
    int num1 = 0 , num2 = 0;
    for (int i = 0; i < 5; i++)
    {
        getline(employees_file, line);
        ss = std::stringstream(line);

        if ( i == NAME){
            ss >> st1 >>st2;
            employee->setName(st2);
        }
        if ( i == NIF ){
            ss >> st1 >> num1;
            employee->setNIF(num1);
        }
        if ( i == WORK_YEARS){
            ss >> st1 >> num1;
            employee->setWorkYears(num1);
        }
        if ( i == SALARY){
            ss >> st1 >> num1;
            employee->setSalary(num1);
        }
    }

}

void updateClientsFile(const std::vector<Client*>& client){
    std::ofstream outfile;
    std::ifstream infile;
    std::string line;
    for (auto it : client) {
        outfile.open("Clients.txt", std::fstream::app);
        outfile << "Name: " << it->getName() << std::endl;
        outfile << "NIF: " << to_string(it->getIntNIF()) << std::endl;
        outfile << "GroupSize: " << it->getGroupSize() << std::endl;
        outfile << "OldClient: " << it->getOld_Client() << std::endl;
        outfile << "Present: " << it->getPresent() << std::endl;
        outfile << "RoomNumber: " << it->getRoomNumber() << std::endl;
        outfile << "Stays: " << it->getStays() << std::endl;
        outfile << "-----------------------------------------------------" << std::endl;
    }
    outfile.close();
}

void updateEmployeesFile(const std::vector<Employee*>& employee){
    std::ofstream outfile;
    std::ifstream infile;
    std::string line;
    for (auto it : employee) {
        outfile.open("Employee.txt", std::fstream::app);
        outfile << "Job: " << it->employeeRole() << std::endl;
        outfile << "Name: " << it->getName() << std::endl;
        outfile << "NIF: " << std::to_string(it->getNIF()) << std::endl;
        outfile << "WorkYears: " << std::to_string(it->getWorkYears()) << std::endl;
        outfile << "Salary: " << std::to_string(it->getSalary()) << std::endl;
        outfile << "-----------------------------------------------------" << std::endl;
    }
    outfile.close();
}

void updateRoomsFile(const std::vector<Room*>& room){
    std::ofstream outfile;
    std::ifstream infile;
    std::string line;
    for (auto it : room) {
        outfile.open("Rooms.txt", std::fstream::app);
        outfile << "RoomType: " << it->RoomType() << std::endl;
        outfile << "RoomID: " << std::to_string(it->getFloor()) << it->getNumber() << std::endl;
        outfile << "Available: " << it->getAvailable() << std::endl;
        outfile << "Capacity: " << std::to_string(it->getCapacity()) << std::endl;
        outfile << "-----------------------------------------------------" << std::endl;
    }
    outfile.close();
}

void updateProductStockFile(const std::vector<Product*>& product){
    std::ofstream outfile;
    std::ifstream infile;
    std::string line;
    for (auto it : product) {
        outfile.open("StockProducts.txt", std::fstream::app);
        outfile << "Type: " << it->getType() << std::endl;
        outfile << "Quality: " << it->getQuality() << std::endl;
        outfile << "Price: " << std::to_string(it->getPrice()) << std::endl;
        outfile << "-----------------------------------------------------" << std::endl;
    }
    outfile.close();
}

void updateVehiclesFile(const BST<Vehicle*>& vehicle){
    std::ofstream outfile;
    std::ifstream infile;
    std::string line;
    BSTItrIn<Vehicle*> it(vehicle);
    while(!it.isAtEnd()){
        outfile.open("Vehicles.txt", std::fstream::app);
        outfile << "Registration: " << it.retrieve()->getRegistration() << std::endl;
        outfile << "km: " << it.retrieve()->getKM() << std::endl;
        outfile << "Seats: " << std::to_string(it.retrieve()->getNumber_Seats()) << std::endl;
        outfile << "-----------------------------------------------------" << std::endl;
    }
    outfile.close();
}

void updateProductToBuyFile(priority_queue<BuyProduct> buyProducts){
    std::ofstream outfile;
    std::ifstream infile;
    std::string line;
    priority_queue<BuyProduct> temp = buyProducts;
    while(!temp.empty()) {
        BuyProduct it = temp.top();
        outfile.open("BuyProducts.txt", std::fstream::app);
        outfile << "Type: " << it.getProduct()->getType() << std::endl;
        outfile << "Quality: " << it.getProduct()->getQuality() << std::endl;
        outfile << "Price: " << std::to_string(it.getProduct()->getPrice()) << std::endl;
        outfile << "Provider: " << (it.getProvider()) << std::endl;
        outfile << "Rating: " << std::to_string(it.getRating()) << std::endl;
        outfile << "Stock: " << std::to_string(it.getValueStock()) << std::endl;
        outfile << "-----------------------------------------------------" << std::endl;
        temp.pop();
    }
    outfile.close();
}

void updateBookFile(std::vector<Book*> book){
    std::ofstream outfile;
    std::ifstream infile;
    std::string line;
    outfile.open("Book.txt", std::fstream::app);
    for (auto it : book) {
        outfile << "Name: " << it->getClient()->getName() << std::endl;
        outfile << "NIF: " << to_string(it->getClient()->getIntNIF()) << endl;
        outfile << "GroupSize: " << std::to_string(it->getClient()->getGroupSize()) << std::endl;
        outfile << "OldClient: " << it->getClient()->getOld_Client() << std::endl;
        outfile << "Present: " << it->getClient()->getPresent() << std::endl;
        outfile << "RoomType: " << it->getRoom()->RoomType() << std::endl;
        outfile << "RoomID: " << std::to_string(it->getRoom()->getFloor()) << std::to_string(it->getRoom()->getNumber()) << std::endl;
        outfile << "Available: " << it->getRoom()->getAvailable() << std::endl;
        outfile << "Capacity: " << it->getRoom()->getCapacity() << std::endl;
        if ((it->getCheckin_date().day < 10)) {
            outfile << "Check-inDate: " << "0" << std::to_string(it->getCheckin_date().day)<< "/";
        } else {
            outfile << "Check-inDate: " <<std::to_string(it->getCheckin_date().day)<< "/";
        }
        if ((it->getCheckin_date().month < 10)) {
            outfile << "Check-inDate: " << "0" << std::to_string(it->getCheckin_date().month)<< "/";
        } else {
            outfile << "Check-inDate: " <<std::to_string(it->getCheckin_date().month)<< "/";
        }
        outfile << std::to_string(it->getCheckin_date().year) << std::endl;
        if ((it->getCheckout_date().day < 10)) {
            outfile << "Check-outDate: " << "0" << std::to_string(it->getCheckout_date().day)<< "/";
        } else {
            outfile << "Check-outDate: " <<std::to_string(it->getCheckout_date().day)<< "/";
        }
        if ((it->getCheckout_date().month < 10)) {
            outfile << "Check-outDate: " << "0" << std::to_string(it->getCheckout_date().month)<< "/";
        } else {
            outfile << "Check-outDate: " <<std::to_string(it->getCheckout_date().month)<< "/";
        }
        outfile << "-----------------------------------------------------" << std::endl;
    }
    outfile.close();
}

void loadFiles(DataBase * database){
    std::ifstream clients_file("Clients.txt");
    std::ifstream rooms_file("Rooms.txt");
    std::ifstream product_on_stock_file("StockProducts.txt");
    std::ifstream product_to_buy_file("BuyProducts.txt");
    std::ifstream book_file("Book.txt");
    std::ifstream employees_file("Employee.txt");
    std::ifstream vehicles_file("Vehicles.txt");
    std::string line, st1, st2, st3 = "0";
    int st4;
    char dt[10];


    std::stringstream ss;
    unsigned int d,m,y = 0;
    std::string dummy = "";
    while(!clients_file.eof()) {
        Client * client = new Client();
        for (int i = 0; i != 8; i++) {
            getline(clients_file, line);
            ss = std::stringstream(line);
            if (i == NAME) {
                ss >> st2 >> st1;
                if ((st1) == "-1") break;
                client->setName(st1);
            } else {
                ss >> st2 >> st4;
                if (i == NIF) {
                    client->setNIF(st4);
                }
                if (i == GROUP_SIZE) {
                    client->setGroupSize(st4);
                }
                if (i == HISTORY) {
                    client->setOld_Client(st4);
                }
                if (i == PRESENT) {
                    client->setPresent(st4);
                }
                if (i == ROOM_NUMBER) {
                    client->setRoomNumber(st4);
                }
                if (i == STAYS){
                    client->setStays(st4);
                }
            }
        }

        if (client->getStays() > 2)
        {
            ClientInitial ci(client->getName()[0], client);
            database->addFrequentClient(ci);
        }
        addElement(client, database->getPointerClients());
    }

    while(!rooms_file.eof())
    {
        string room_type;
        getline(rooms_file, line);
        ss = std::stringstream(line);
        ss >> st1 >>room_type;

        if (room_type=="NoViewRoom") {
            NoViewRoom *room = new NoViewRoom();
            loadRoom(room, rooms_file);
            database->addRoomElement(room);
        }
        else if (room_type=="ViewRoom") {
            ViewRoom *room= new ViewRoom();
            loadRoom(room, rooms_file);
            database->addRoomElement(room);
        }
        else {
            SuiteRoom *room= new SuiteRoom();
            loadRoom(room, rooms_file);
            database->addRoomElement(room);
        }
    }

    while(!employees_file.eof())
    {
        string employee_role;
        getline(employees_file, line);
        ss = std::stringstream(line);
        ss >> st1 >>employee_role;

        if (employee_role=="Manager") {
            Manager *employee = new Manager();
            loadEmployee(employee, employees_file);
            database->addEmployeeElement(employee);
        }
        else if (employee_role=="Reception") {
            Reception *employee= new Reception();
            loadEmployee(employee, employees_file);
            database->addEmployeeElement(employee);
        }
        else if (employee_role=="Cleaning") {
            Cleaning *employee= new Cleaning();
            loadEmployee(employee, employees_file);
            database->addEmployeeElement(employee);
        }
        else {
            Responsible *employee= new Responsible();
            loadEmployee(employee, employees_file);
            database->addEmployeeElement(employee);
        }
    }


    while(!product_on_stock_file.eof()) {
        Product *product = new Product();
        for (int i = 0; i != 4; i++) {
            getline(product_on_stock_file, line);
            ss = std::stringstream(line);

            if (i == TYPE) {
                ss >> st2 >> st1;
                product->setType(st1);
            }
            else if (i == QUALITY) {
                ss >> st2 >> st4;
                product->setQuality(st4);
            }
            else if (i == PRICE) {
                ss >> st2 >> st4;
                product->setPrice(st4);
            }
        }
        addElement(product, database->getPointerStock_products());
    }


    while(!product_to_buy_file.eof())
    {
        BuyProduct * bp = new BuyProduct();
        Product * product = new Product();
        for (int i= 0; i!=7 ;i++)
        {
            getline(product_to_buy_file, line);
            ss = std::stringstream(line);

            if (i == TYPE) {
                ss >> st2 >> st1;
                product->setType(st1);
            }
            else if (i == QUALITY) {
                ss >> st2 >> st4;
                product->setQuality(st4);
            }
            else if (i == PRICE) {
                ss >> st2 >> st4;
                product->setPrice(st4);
                bp->setProduct(product);
            }
            else if(i == PROVIDER){
                ss >> st2 >> st1;
                bp->setProvider(st1);
            }
            else if(i == RATING){
                ss >> st2 >> st4;
                bp->setRating(st4);
            }
            else if(i == STOCK){
                ss >> st2 >> st4;
                bp->setStock(st4);
            }
        }
        database->getPointerBuy_products()->push(*bp);
        database->getPointerShopInfStock()->push(*bp);
    }

    while(!vehicles_file.eof()) {
        Vehicle *v = new Vehicle();
        for (int i = 0; i != 4; i++) {
            getline(vehicles_file, line);
            ss = std::stringstream(line);

            if (i == REGISTRATION) {
                ss >> st2 >> st1;
                v->setRegistration(st1);
            }
            else if (i == DISTANCE) {
                ss >> st2 >> st4;
                v->setKm(st4);
            }
            else if (i == NO_SEATS) {
                ss >> st2 >> st4;
                v->setNumber_seats(st4);
            }
        }
        database->getPointerVehicles_list()->insert(v);
        database->getPointerVehicle_stock_inf()->insert(v);
    }

    while(!book_file.eof()) {
        Book *book= new Book();
        for (int i = 0; i !=8; i++) {
            getline(book_file, line);
            ss = std::stringstream(line);

            if (i == NAME) {
                ss >> st2 >> st1;
                book->getClient()->setName(st1);
            }
            if (i == NIF) {
                ss >> st2 >> st4;
                book->getClient()->setNIF(st4);
            }
            if (i == GROUP_SIZE) {
                ss >> st2 >> st4;
                book->getClient()->setGroupSize(st4);
            }
            if (i == HISTORY) {
                ss >> st2 >> st4;
                book->getClient()->setOld_Client(st4);
            }
            if (i == PRESENT) {
                ss >> st2 >> st4;
                book->getClient()->setPresent(st4);
            }
            if (i == ROOM_TYPE) {
                ss = std::stringstream(line);
                ss >> st1 >> st2;
                if (st2 == "NoViewRoom") {
                    NoViewRoom *room = new NoViewRoom();
                    loadBookRoom(room, book_file);
                    book->setRoom(room);
                }
                else if (st2 == "ViewRoom") {
                    ViewRoom *room= new ViewRoom();
                    loadBookRoom(room, book_file);
                    book->setRoom(room);
                }
                else {
                    SuiteRoom *room= new SuiteRoom();
                    loadBookRoom(room, book_file);
                    book->setRoom(room);
                }

            }
            if(i == DATE){
                ss >> st2 >> dt;
                d= (dt[0]-'0')*10+(dt[1]-'0');
                m = (dt[3]-'0')*10+(dt[4]-'0');
                y = (dt[6]-'0')*1000+(dt[7]-'0')*100+(dt[8]-'0')*10+(dt[9]-'0');
                Date * date = new Date(d,m,y);
                getline(book_file, line);
                ss = std::stringstream(line);
                ss >> st2 >> dt;
                d= (dt[0]-'0')*10+(dt[1]-'0');
                m = (dt[3]-'0')*10+(dt[4]-'0');
                y = (dt[6]-'0')*1000+(dt[7]-'0')*100+(dt[8]-'0')*10+(dt[9]-'0');
                Date * dat = new Date(d,m,y);
                book->setCheckDate(date,dat);
            }

        }
        book -> getClient()->setRoomNumber(book->getRoom()->getNumber());
        addElement(book,database->getPointerBooks());
        addElement(book->getClient(), database->getPointerClients());
    }
}

