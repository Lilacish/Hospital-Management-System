/*
#include "person.h"
#include <fstream>
#include <iostream>
#include <sstream>

Person::Person(const string& id, const string& name, int age, const string& contactNumber, const string& address)
    : id(id), name(name), age(age), contactNumber(contactNumber), address(address) {}

string Person::getFormattedDetails() const {
    stringstream ss;
    ss << id << "," << name << "," << age << "," << contactNumber << "," << address;
    return ss.str();
}

string Person::getId() const {
    return id;
}

void PersonManager::addPerson(const Person& person) {
    saveToFile("people.csv", person);
}
void PersonManager::removePerson(const string& id, const string& filename) {
   
    ifstream file(filename + ".csv");
    ofstream tempFile(filename + "temp_.csv");

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string currentId;
        getline(ss, currentId, ',');
        if (currentId != id) {
            tempFile << line << endl;
        }
        else {
            cout << "Person with the ID: " << id << " has been removed." << endl;
        }
    }
    string a = filename + ".csv";
    string b = filename + "temp_.csv";
    remove(a.c_str());
    rename(b.c_str(), a.c_str());
}
// ... Other PersonManager methods remain unchanged ...
void PersonManager::displayAllPeople(const string& filename) const {
    ifstream file(filename + ".csv");
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

void PersonManager::saveToFile(const string& filename, const Person& person) const {
    ofstream file(filename + ".csv", ios::app);
    if (file.is_open()) {
        file << person.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << filename + ".csv" << endl;
    }
}
*/