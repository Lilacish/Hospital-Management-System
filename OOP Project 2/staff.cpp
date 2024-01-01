#include "staff.h"

// Staffmember implementation
Staffmember::Staffmember(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Person(id, name, age, contactNumber, address), dutyTime(dutyTime), salary(salary), position(position) {}

// Cleaner implementation
Cleaner::Cleaner(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Staffmember(id, name, age, contactNumber, address, dutyTime, salary, position) {}

// Guard implementation
/*Guard::Guard(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Staffmember(id, name, age, contactNumber, address, dutyTime, salary, position) {}*/
// AdminStaff implementation
AdminStaff::AdminStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Staffmember(id, name, age, contactNumber, address, dutyTime, salary, position) {}
Doctor::Doctor(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Staffmember(id, name, age, contactNumber, address, dutyTime, salary, position) {}
Nurse::Nurse(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Staffmember(id, name, age, contactNumber, address, dutyTime, salary, position) {}
FacilityServicesStaff::FacilityServicesStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Staffmember(id, name, age, contactNumber, address, dutyTime, salary, position) {}
SocialServicesStaff::SocialServicesStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Staffmember(id, name, age, contactNumber, address, dutyTime, salary, position) {}
SupportStaff::SupportStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Staffmember(id, name, age, contactNumber, address, dutyTime, salary, position) {}
Hospitalist::Hospitalist(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Staffmember(id, name, age, contactNumber, address, dutyTime, salary, position) {}
DietaryServiceStaff::DietaryServiceStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Staffmember(id, name, age, contactNumber, address, dutyTime, salary, position) {}

/*
SStaff::EMSStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Staffmember(id, name, age, contactNumber, address, dutyTime, salary, position) {}
InfectionControlStaff::InfectionControlStaff(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Staffmember(id, name, age, contactNumber, address, dutyTime, salary, position) {}
*/

// HospitalStaffDepartment implementation
HospitalStaffDepartment::HospitalStaffDepartment() {
    // You might want to load existing staff members from the file here
    // readDataFromFiles();
}
string Staffmember:: getFormattedDetails() {
    stringstream ss;
    ss << id << "," << name << "," << age << "," << contactNumber << "," << address << "," << dutyTime << "," << salary << "," << position;
    return ss.str();
}

void HospitalStaffDepartment::addCleaner( Cleaner& cleaner) {
    ofstream file("cleaner.csv", ios::app);
    if (file.is_open()) {
        file << cleaner.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "cleaner.csv" << endl;
    }
   
}

void HospitalStaffDepartment::addAdminStaff(AdminStaff& adminStaff) {

    ofstream file("adminStaff.csv", ios::app);
    if (file.is_open()) {
        file << adminStaff.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "adminStaff.csv" << endl;
    }
}
void HospitalStaffDepartment::addDoctor(Doctor& doctor) {
  
    ofstream file("doctor.csv", ios::app);
    if (file.is_open()) {
        file << doctor.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "doctor.csv" << endl;
    }
}
void HospitalStaffDepartment::addNurse(Nurse& nurse) {
    ofstream file("nurse.csv", ios::app);
    if (file.is_open()) {
        file << nurse.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << filename + ".csv" << endl;
    }
}
void HospitalStaffDepartment::addFacilityServicesStaff( FacilityServicesStaff& facilityStaff){
   
    ofstream file("facilityStaff.csv", ios::app);
    if (file.is_open()) {
        file << facilityStaff.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "facilityStaff.csv" << endl;
    }
}
void HospitalStaffDepartment::addSocialServicesStaff(SocialServicesStaff& socialStaff) {
    ofstream file("socialStaff.csv", ios::app);
    if (file.is_open()) {
        file << socialStaff.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "socialStaff.csv" << endl;
    }
}
void HospitalStaffDepartment::addSupportStaff(SupportStaff& supportStaff) {
    ofstream file("supportStaff.csv", ios::app);
    if (file.is_open()) {
        file << supportStaff.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "supportStaff.csv" << endl;
    }
}
void HospitalStaffDepartment::addHospitalist(Hospitalist& hospitalist) {
    ofstream file("hospitalist.csv", ios::app);
    if (file.is_open()) {
        file << hospitalist.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "hospitalist.csv" << endl;
    }
}
void HospitalStaffDepartment::addDietaryServiceStaff(DietaryServiceStaff& dietaryStaff) {
    ofstream file("dietaryStaff.csv", ios::app);
    if (file.is_open()) {
        file << dietaryStaff.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "dietaryStaff.csv" << endl;
    }
}


void HospitalStaffDepartment::removeStaffMember(const string& id, string& filename) {
    // Remove staff member from the vector and update the file
    removePerson(id, filename);
}


void HospitalStaffDepartment::displayAllPeople(const string& filename, string& category) const {
    string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + filename + "/Staff/" + category;
    ifstream file(filetype + ".csv");
    if (!file.is_open()) {
        cerr << "Error opening file: " << filetype << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
void HospitalStaffDepartment::displayAllStaff(string& dept) const {
    //string filename = "../OOP Project 2/Data/Departments/MedicalDepartments/" + dept + "/Patients/patient";
  /*  displayAllPeople(".. / OOP Project 2 / Data / Departments / MedicalDepartments / " + dept + "/ Staff/cleaner.csv");
    displayAllPeople(".. / OOP Project 2 / Data / Departments / MedicalDepartments / " + dept + "/ Staff/guard.csv" );
    displayAllPeople(".. / OOP Project 2 / Data / Departments / MedicalDepartments / " + dept + "/ Staff/adminStaff" );
    displayAllPeople(".. / OOP Project 2 / Data / Departments / MedicalDepartments / " + dept + "/ Staff/doctor" );
    displayAllPeople(".. / OOP Project 2 / Data / Departments / MedicalDepartments / " + dept + "/ Staff/nurse" );
    displayAllPeople(".. / OOP Project 2 / Data / Departments / MedicalDepartments / " + dept + "/ Staff/facilityStaff");
    displayAllPeople(".. / OOP Project 2 / Data / Departments / MedicalDepartments / " + dept + "/ Staff/socialStaff");
    displayAllPeople(".. / OOP Project 2 / Data / Departments / MedicalDepartments / " + dept + "/ Staff/supportStaff");
    displayAllPeople(".. / OOP Project 2 / Data / Departments / MedicalDepartments / " + dept +  " / Staff /hospitalist");
    displayAllPeople(".. / OOP Project 2 / Data / Departments / MedicalDepartments / " + dept + "/ Staff/dietaryStaff");
  //  displayAllPeople("infectionControlStaff.csv");
  */ 
  string a = "cleaner";
  string b = "guard";
  string c = "adminStaff";
  string d = "doctor";
  string e = "nurse";
  string f = "facilityStaff";
  string g = "socialStaff";
  string h = "supportStaff";
  string i = "hospitalist";
  string j = "dietaryStaff";
    displayAllPeople(dept, a);
    displayAllPeople(dept, b);
    displayAllPeople(dept, c);
    displayAllPeople(dept, d);
    displayAllPeople(dept, e);
    displayAllPeople(dept, f);
    displayAllPeople(dept, g);
    displayAllPeople(dept, h);
    displayAllPeople(dept, i);
    displayAllPeople(dept, j);

}
/*
void HospitalStaffDepartment::readDataFromFiles() {
    // Load staff data from the file
}

void HospitalStaffDepartment::writeToCSV() const {
    // Write all staff members to the CSV file
}

void HospitalStaffDepartment::loadFromCSV() {
    // Load staff members from the CSV file
}

HospitalStaffDepartment::~HospitalStaffDepartment() {
    // Clean up any resources if needed
    // If you're using dynamic memory allocation, make sure to properly deallocate
}
*//*
void  HospitalStaffDepartment::displayStaffmember(string& filename) {
    displayAllPeople(filename);
}*/
/*
// StaffmemberManager implementation
void StaffmemberManager::addPerson(const Person& person) {
    // Assuming staffmember.csv is the file where you want to save staff members
    saveToFile("staffmember.csv", person);
}

void StaffmemberManager::removePerson(const string& id, const string& filename) {
    // Assuming staffmember.csv is the file where you want to remove staff members from
    PersonManager::removePerson(id, "staffmember.csv");
}

void StaffmemberManager::displayAllPeople(const string& filename) const {
    // Assuming staffmember.csv is the file where you want to display staff members from
    PersonManager::displayAllPeople("staffmember.csv");
}

void StaffmemberManager::saveToFile(const string& filename, const Person& person) const {
    PersonManager::saveToFile("staffmember.csv", person);
}
*/
/*
void HospitalStaffDepartment::addInfectionControlStaff( InfectionControlStaff& infectionControlStaff) {
    ofstream file("infectionControlStaff.csv", ios::app);
    if (file.is_open()) {
        file << infectionControlStaff.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "infectionControlStaff.csv" << endl;
    }
}*/