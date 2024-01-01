/*#pragma once
#pragma once
#include <vector>
#include <string>
using namespace std;


class Doctor {
public:
    Doctor(string name, int age, string gender, string position, double salary, string phoneNumber);
    string getInfo() const;
    Doctor(int id, string name, string specialization);
private:

    int id;
    string name;
    string specialization;
    int age;
    string gender;
    string position;
    double salary;
    string phoneNumber;
};
class Department {
public:
    void addDoctor(const Doctor& doctor);
    void saveToFile() const;
    void displayAllDoctors() const;
    Department();

private:
    vector<Doctor> doctors;
    string filename;
};
*/
#pragma once

#ifndef FACILITY_H
#define FACILITY_H
#include<iostream>
#include <string>
#include <vector>
#include "staff.h"
#include "../../OOP Project/OOP Project/patientscoordinationdepartment.h"
using namespace std;


class Room {
public:
    Room(string& id, bool isAvailable);
  //  void updateRoomDetails(const string& type, bool isAvailable);
    string getFormattedDetails() const;
    string getId();
private:
    string id;
    bool isAvailable;
};

class RoomItem {
public:
    RoomItem(string& id, const string& name, string& quantity);
  //  void updateItemDetails(const string& name, string& quantity);
    string getFormattedDetails() const;
    string getId();
private:
    string id;
    string name;
    string quantity;
};
/*
class Department {
public: 
    Department(string& name);
private:
    string name;
};
*/
class Departmentmanagement: public HospitalStaffDepartment  {
public:
    Departmentmanagement();
    void displaydepts();
    void updateRoom(string& department, string roomId, const Room& updatedRoom);
    void updateItem(string& department, string& roomId, string itemId, const RoomItem& updatedItem);
    void displayrooms(string& department);
    void displayitems(string& department, string roomId);
 //   void displayFacilities();
    void saveitemToFile(string& department, string roomId, RoomItem& item) const;
    void removeitem(string& department, string roomId, string& id) const;

    //   void saveroomToFile(Room& room) const;
    //   void displaystaff() const;
   //  void loadFromCSV();
    // void addRoom(Room& room);
   //    //  void addItem(Item& item);
    // vector<Room> rooms;
   //  vector<Item> items;
};


#endif // FACILITY_H

#pragma once
