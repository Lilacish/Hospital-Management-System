
#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& id, const string& name, string& age, const string& contactNumber, const string& address);
    virtual string getFormattedDetails() const;
    string getId() const;

protected:
    string id;
    string name;
    string age;
    string contactNumber;
    string address;
};

class PersonManager {
public:
   virtual void addPerson(const Person& person);
    void removePerson(const string& id, const string& filename);
   // void updatePersondata(const string& id, const Person& updatedPerson);
    void displayAllPeople(const string& filename) const;
    void saveToFile(const string& filename, const Person& person) const;

private:
    vector<Person> people;
};

#endif // PERSON_H
