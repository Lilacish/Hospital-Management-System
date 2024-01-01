/*#include "Department.h"
#include <iostream>
#include <fstream>
#include <sstream>
void Department::addDoctor(const Doctor& doctor) {
    doctors.push_back(doctor);
}

void Department::saveToFile() const {
    ofstream file(filename);
    for (const auto& doctor : doctors) {
        file << doctor.getInfo() << endl;
    }
    file.close();
}

void Department::displayAllDoctors() const {
    for (const auto& doctor : doctors) {
        cout << doctor.getInfo() << endl;
    }
}

Department::Department() : filename("doctors.csv") {}

Doctor::Doctor(string name, int age, string gender, string position, double salary, string phoneNumber)
    : name(name), age(age), gender(gender), position(position), salary(salary), phoneNumber(phoneNumber) {}
Doctor::Doctor(int id, string name, string specialization) : id(id), name(name), specialization(specialization) {}
string Doctor::getInfo() const {
    stringstream ss;
    ss << name << ", " << age << ", " << gender << ", " << position << ", " << salary << ", " << phoneNumber;
    return ss.str();
}
*/
#include "Dept.h"
#include <fstream>
#include <sstream>

// Room class implementation
Room::Room(string& id,  bool isAvailable)
    : id(id), isAvailable(isAvailable) {}
/*
void Room::updateRoomDetails(const string& type, bool isAvailable) {
    this->type = type;
    this->isAvailable = isAvailable;
}
*/
string Room::getFormattedDetails() const {
    stringstream ss;
    ss << id << ", "  << (isAvailable ? "Available" : "Occupied");
    return ss.str();
}

// Item class implementation
RoomItem::RoomItem(string& id, const string& name, string& quantity)
    : id(id), name(name), quantity(quantity) {}
/*
void RoomItem::updateItemDetails(const string& name, string& quantity) {
    this->name = name;
    this->quantity = quantity;
}
*/
string RoomItem::getFormattedDetails() const {
    stringstream ss;
    ss << id << ", " << name << ", " << quantity;
    return ss.str();
}

// FacilityManager class implementation
/*void Department::addRoom(Room& room) {
    rooms.push_back(room);
    saveToFile();
}
*/
/*
Department::Department(string& name) :name(name) {

}*/
Departmentmanagement::Departmentmanagement() {

}
void Departmentmanagement::displaydepts() {
    ifstream file("Departments.csv");
    if (!file.is_open()) {
        cerr << "Error opening file: " << "Departments.csv" << endl;
        return;
    }
    string line;
    string data;
    cout << " Room Id, Status" << endl;
    while (getline(file, line)) {
        istringstream ss(line);
        getline(ss, line, ',');
        cout << line <<endl;
    }
}

void Departmentmanagement::updateRoom(string& department, string roomId, const Room& updatedRoom){
    string filename = "../OOP Project 2/Data/Departments/" + department + "Rooms.csv";
    ifstream file(filename);
    ofstream tempFile(filename+"temp.csv");

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string currentId;
        getline(ss, currentId, ',');
        if (currentId != roomId) {
            tempFile << line << endl
                ;

        }
        else
            tempFile << updatedRoom.getFormattedDetails() << endl;

    }
    file.close();
    tempFile.close();
    string a = filename + ".csv";
    string b = filename + "temp.csv";
   
    remove(a.c_str());
    rename(b.c_str(), a.c_str());
}
/*
void Department::addItem(Item& item) {
    items.push_back(item);
    saveToFile();
}
*/
void Departmentmanagement::updateItem(string& department, string& roomId, string itemId, const RoomItem& updatedItem) {
    string filename = "../OOP Project 2/Data/Departments/MedicalDepartments/" + department + "/Rooms/" + roomId;
    ifstream file(filename+".csv");
    ofstream tempFile(filename + "temp.csv");

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string currentId;
        getline(ss, currentId, ',');
        if (currentId != itemId) {
            tempFile << line << endl
                ;

        }
        else
            tempFile << updatedItem.getFormattedDetails() << endl;

    }
    file.close();
    tempFile.close();
    string a = filename + ".csv";
    string b = filename + "temp.csv";

    remove(a.c_str());
    rename(b.c_str(), a.c_str());
}



/*
void Department::displayFacilities()  {
    loadFromCSV();
    cout << "Rooms:\n";
    for (const auto& room : rooms) {
        cout << room.getFormattedDetails() << endl;
    }
    cout << "\nItems:\n";
    for (const auto& item : items) {
        cout << item.getFormattedDetails() << endl;
    }
}*/

void Departmentmanagement::removeitem(string& department, string roomId, string& id) const {
    string filename = "../OOP Project 2/Data/Departments/MedicalDepartments/" + department + "/Rooms/" + roomId ;
    ifstream file(filename+".csv");
    ofstream tempFile(filename + "temp.csv");

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string currentId;
        getline(ss, currentId, ',');
        if (currentId != id) {
            tempFile << line << endl;

        }
        else
            cout << "Item with the ID : " << id << " have been removed.\n";
    }
    file.close();
    tempFile.close();
    string a = filename + ".csv";
    string b = filename + "temp.csv";

    remove(a.c_str());
    rename(b.c_str(), a.c_str());

}
void Departmentmanagement::displayrooms(string& department) {
    string filename = "../OOP Project 2/Data/Departments/MedicalDepartments/" + department + "/Rooms.csv";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << "Rooms.csv" << endl;
        return;
    }
    string line;
    string data;

    while (getline(file, line)) {
        istringstream ss(line);
        string id, type, isAvailableStr;
        getline(ss, id, ',');
        getline(ss, isAvailableStr, ',');
        bool isAvailable = (isAvailableStr == "Available" ? true : false);
        cout << id  << " , " << isAvailableStr << endl;
    }
}
void Departmentmanagement::displayitems(string& department, string roomId) {
    string filename = "../OOP Project 2/Data/Departments/MedicalDepartments/" + department + "/Rooms/" + roomId + ".csv";
    ifstream ifile(filename);
    if (!ifile.is_open()) {
        cerr << "Error opening file: " << filename+".csv" << endl;
        return;
    }
    cout << "ID, Name, Quantity" << endl;
    string line;
    string data;

    while (getline(ifile, line)) {
        istringstream ss(line);
        stringstream iss(line);
        string id, name, quantity;
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, quantity, ',');

        cout << id << " , " << name << " , " << quantity << endl;
    }
}
/*
void Departmentmanagement::displayFacilities() {
    ifstream file("Rooms.csv");
    if (!file.is_open()) {
        cerr << "Error opening file: " << "Rooms.csv" << endl;
        return;
    }
    string line;
    string data;

    while (getline(file, line)) {
        istringstream ss(line);
        string id, type, isAvailableStr;
        getline(ss, id, ',');
        getline(ss, type, ',');
        getline(ss, isAvailableStr, ',');
        bool isAvailable = (isAvailableStr == "Available" ? true : false);
        cout << id << " , " << type << " , " << isAvailableStr << endl;
    }
    ifstream ifile("Items.csv");
    if (!ifile.is_open()) {
        cerr << "Error opening file: " << "Items.csv" << endl;
        return;
    }


    while (getline(ifile, line)) {
        istringstream ss(line);
        stringstream iss(line);
        string id, name, quantity;
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, quantity, ',');

        cout << id << " , " << name << " , " << quantity << endl;
    }
}*/
// void Department::displaystaff() const{}

/*void Department::saveroomToFile(Room& room) const {
    ofstream file("Rooms.csv", ios::app);

    if (file.is_open()) {
            file << room.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "Rooms.csv" << endl;
    }
}*/
void Departmentmanagement::saveitemToFile(string& department, string roomId, RoomItem& item) const {
    string filename = "../OOP Project 2/Data/Departments/MedicalDepartments/" + department + "/Rooms/" + roomId + ".csv";
    ofstream itemfile(filename, ios::app);
    if (itemfile.is_open()) {
        itemfile << item.getFormattedDetails() << endl;
        itemfile.close();
    }
    else {
        cout << "Unable to open file: " << filename + ".csv" << endl;
    }
}

string Room::getId() {
    return id;
}
string RoomItem::getId() {
    return id;
}

/*void Department::loadFromCSV() {
    // Clear existing data
    rooms.clear();
    items.clear();

    // Load Rooms
    std::ifstream roomsFileStream("Rooms.csv", ios::app);
    string line;
    if (roomsFileStream.is_open()) {
        while (getline(roomsFileStream, line)) {
            // Parse the line to create a Room object and add it to rooms vector
            // Assuming the line format is: id,type,isAvailable
            std::stringstream ss(line);
            string id, type, isAvailableStr;
            getline(ss, id, ',');
            getline(ss, type, ',');
            getline(ss, isAvailableStr, ',');
            bool isAvailable = (isAvailableStr == "Available" ? true : false);
            rooms.push_back(Room(id, type, isAvailable));
        }
        roomsFileStream.close();
    }
    else {
        std::cerr << "Unable to open file: " << "Rooms.csv" << "\n";
    }

    // Load Items
    std::ifstream itemsFileStream("Items.csv", ios::app);
    if (itemsFileStream.is_open()) {
        while (getline(itemsFileStream, line)) {
            // Parse the line to create an Item object and add it to items vector
            // Assuming the line format is: id,name,quantity
            std::stringstream ss(line);
            string id, name, quantity;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, quantity, ',');
            items.push_back(Item(id, name, quantity));
        }
        itemsFileStream.close();
    }
    else {
        std::cerr << "Unable to open file: " << "Items.csv" << "\n";
    }
}*/