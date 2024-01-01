
/*
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Base class for all types of staff
class StaffMember {
public:
    StaffMember(string name, int age, string gender, string contact);
    virtual void displayInfo() = 0;
    virtual string getCSVFormat() = 0;
    string getname()const;
protected:
    string name;
    int age;
    string gender;
    string contact;
};

#pragma once
#include <string>
using namespace std;

class Doctor {
public:
    Doctor(string name, int age, string gender, string position, double salary, string phoneNumber);
    string getInfo() const;
    Doctor(int id, string name, string specialization);
private:
    string name;
    int id;
    string specialization;
    int age;
    string gender;
    string position;
    double salary;
    string phoneNumber;
};

class Nurse {
public:
    Nurse(string name, int id, string department);
    string toCsvFormat() const;
    int getId() const;

private:
    string name;
    int id;
    string department;
};

class NurseCoordinationSystem {
public:
    NurseCoordinationSystem();
    void addNurse(const Nurse& nurse);
    void removeNurse(int id);
    void displayNurses() const;
    void saveToCSV() const;

private:
    vector<Nurse> nurses;
    string filename;
};



// Derived class for Cleaners
class Cleaner : public StaffMember {
public:
    Cleaner(string name, int age, string gender, string contact);
    void displayInfo() override;
    string getCSVFormat() override;
};

// Derived class for Guards
class Guard : public StaffMember {
public:
    Guard(string name, int age, string gender, string dutyTime, string contact);
    void displayInfo() override;
    string getCSVFormat() override;

protected:
    string dutyTime;
};

// Derived class for Administration Staff
class AdminStaff : public StaffMember {
public:
    AdminStaff(string name, int age, string gender, string contact);
    void displayInfo() override;
    string getCSVFormat() override;
};
//Derived classes for Cleaners, Guards, and AdminStaff
// ... (No changes needed here)

// Hospital Staff Department
class HospitalStaffDepartment {
public:
    HospitalStaffDepartment();
    void addCleaner(const string& name, int age, const string& gender, const string& contact);
    void addGuard(const string& name, int age, const string& gender, const string& dutyTime, const string& contact);
    void addAdminStaff(const string& name, int age, const string& gender, const string& contact);
    void removeStaffMember(const string& name); // New function to remove a staff member
    void displayAllStaff() const;
    void readDataFromFiles(); // New function to read data from the CSV file
    ~HospitalStaffDepartment();

private:
    vector<StaffMember*> staffMembers;
    string filename;

    void writeToCSV() const; // Changed to not require parameters
    void loadFromCSV();      // New function to load staff data from the CSV file
};


#endif // HOSPITALSTAFFDEPARTMENT_H

*/
#ifndef HOSPITALSTAFFDEPARTMENT_H
#define HOSPITALSTAFFDEPARTMENT_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "../OOP Project 2/Data/Departments/Persondata.h"

using namespace std;

// Derived class for Cleaners
class Staffmember : public Person {
public:
    Staffmember(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutytime, const string& salary, const string& position);
    string getFormattedDetails() ;
   // string getFormattedDetails() ;
private:
    string dutyTime;
    string salary;
    string position;

};
/*
class StaffmemberManager : public PersonManager {
    void addPerson(const Person& person) override;
    void removePerson(const string& id, const string& filename);
    void displayAllPeople(const string& filename) const;
    virtual void saveToFile(const string& filename, const Person& person) const;
};
*/

class Cleaner  : public Staffmember {
public:
    Cleaner(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position);
};
/*
// Derived class for Guards
class Guard :public Staffmember {
public:
    Guard(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position);
    
};*/

// Derived class for Administration Staff
class AdminStaff : public Staffmember {
public:
    AdminStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position);
};

// Derived class for Doctors
class Doctor : public Staffmember {
public:
    Doctor(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position);

};

// Derived class for Nurses
class Nurse : public Staffmember {
public:
    Nurse(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position);

};

// Derived class for Environmental and Facility Services
class FacilityServicesStaff : public Staffmember {
public:
    FacilityServicesStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position);

};

// Derived class for Social Services
class SocialServicesStaff : public Staffmember {
public:
    SocialServicesStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position);

};

// Derived class for Support Staff
class SupportStaff : public Staffmember {
public:
    SupportStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position);

};

// Derived class for Hospitalists
class Hospitalist : public Staffmember {
public:
    Hospitalist(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position);

};

// Derived class for Nutrition and Dietary Service Staff
class DietaryServiceStaff : public Staffmember {
public:
    DietaryServiceStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position);

};
/*
// Derived class for Emergency Medical Services (EMS) Staff
class EMSStaff : public Staffmember {
public:
    EMSStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position);

};

// Derived class for Infection Control and Quality Improvement Staff
class InfectionControlStaff : public Staffmember {
public:
    InfectionControlStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position);

};
*/
// Hospital Staff Department
class HospitalStaffDepartment: public PersonManager {
public:
    HospitalStaffDepartment();
    void addCleaner(Cleaner& cleaner);
 //   void addGuard( Guard& guard);
    void addAdminStaff( AdminStaff& adminStaff);
    void addDoctor( Doctor& doctor);
    void addNurse( Nurse& nurse);

    void addFacilityServicesStaff( FacilityServicesStaff& facilityStaff);
    void addSocialServicesStaff( SocialServicesStaff& socialStaff);
    void addSupportStaff( SupportStaff& supportStaff);
    void addHospitalist( Hospitalist& hospitalist);
    void addDietaryServiceStaff( DietaryServiceStaff& dietaryStaff);
//    void addEMSStaff( EMSStaff& emsStaff);
//    void addInfectionControlStaff( InfectionControlStaff& infectionControlStaff);
    void displayAllPeople(const string& filename, string& category) const;
  //  void displayStaffmember(string& filename);
    void removeStaffMember(const string& id, string& filename);
    void displayAllStaff(string& dept) const;
  
    

   
// void addDiagnosticTherapeuticStaff(const DiagnosticTherapeuticStaff& diagnosticStaff);
//  void addPharmacyStaff(const PharmacyStaff& pharmacyStaff);
//  void addITSupportStaff(const ITSupportStaff& itStaff);
   // void readDataFromFiles();

private:
 //   vector<StaffMember*> staffMembers;
  //  NurseCoordinationSystem nurseCoordSystem;
    string filename;

 //   void writeToCSV() const;
   // void loadFromCSV();
};
/*
// Derived class for NurseCoordinationSystem
class NurseCoordinationSystem {
public:
    NurseCoordinationSystem();
    void addNurse(const Nurse& nurse);
    void removeNurse(int id);
    void displayNurses() const;
    void saveToCSV() const;

private:
    vector<Nurse> nurses;
    string filename;
};

// Derived class for Diagnostic and Therapeutic Services
class DiagnosticTherapeuticStaff : public Person {
public:
    DiagnosticTherapeuticStaff(string id, string name, int age, string gender, string department);
    void displayInfo() override;
    string getCSVFormat() override;
};

// Derived class for Pharmacy Staff
class PharmacyStaff : public Person {
public:
    PharmacyStaff(string id, string name, int age, string gender, string position, double salary);
    void displayInfo() override;
    string getCSVFormat() override;

private:
    string position;
    double salary;
};

// Derived class for IT and Technology Support
class ITSupportStaff : public Person {
public:
    ITSupportStaff(string id, string name, int age, string gender, string position, double salary);
    void displayInfo() override;
    string getCSVFormat() override;

private:
    string position;
    double salary;
};
*/
#endif // HOSPITALSTAFFDEPARTMENT_H
