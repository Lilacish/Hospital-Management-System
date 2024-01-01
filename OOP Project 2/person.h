/*
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& id, const string& name, int age, const string& contactNumber, const string& address);
    string getFormattedDetails() const;
    string getId() const;

private:
    string id;
    string name;
    int age;
    string contactNumber;
    string address;
};

class PersonManager {
public:
    void addPerson(const Person& person);
    void removePerson(const string& id, const string& filename);
 //   void updatePerson(const string& id, const Person& updatedPerson);
    void displayAllPeople(const string& filename) const;
    void saveToFile(const string& filename, const Person& person) const;

private:
    vector<Person> people;
};

#endif // PERSON_H
*/