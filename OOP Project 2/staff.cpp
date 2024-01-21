#include "staff.h"
#include <cstdio>
#include <stdio.h>
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

void HospitalStaffDepartment::addCleaner( string& dept, Cleaner& cleaner) {
    string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + dept + "/Staff/cleaner.csv";
    ofstream file(filetype, ios::app);
    if (file.is_open()) {
        file << cleaner.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "cleaner.csv" << endl;
    }
}

void HospitalStaffDepartment::addAdminStaff(string& dept, AdminStaff& adminStaff) {
    string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + dept + "/Staff/adminStaff.csv";
    ofstream file(filetype, ios::app);
    if (file.is_open()) {
        file << adminStaff.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "adminStaff.csv" << endl;
    }
}
void HospitalStaffDepartment::addDoctor(string& dept, Doctor& doctor) {
    string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + dept + "/Staff/doctor.csv";

    ofstream file(filetype, ios::app);
    if (file.is_open()) {
        file << doctor.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "doctor.csv" << endl;
    }
    const vector<string> timeSlots = { "9:00", "10:00", "11:00", "12:00", "1:00", "2:00", "3:00", "4:00" };
        ofstream newfile("../OOP Project 2/Data/Departments/MedicalDepartments/" + dept + "/Staff/doctors/" + doctor.getId() + "_schedule.csv",ios::trunc);
        if (newfile.is_open()) {
            for (const auto& slot : timeSlots) {
                newfile << slot << ",Available\n";
            }
            newfile.close();
        }
        else {
            cerr << "Unable to create schedule file for doctor " << doctor.getId() << endl;
        }
    
}/*
void HospitalStaffDepartment::viewavailabledoctors(Doctor& doctor, string time) {

    ofstream file("doctor.csv", ios::app);
    if (file.is_open()) {
        file << doctor.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "doctor.csv" << endl;
    }
}
void HospitalStaffDepartment::updateDoctor(Doctor& doctor, string time) {

    ofstream file("doctor.csv", ios::app);
    if (file.is_open()) {
        file << doctor.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "doctor.csv" << endl;
    }
}
*/
void HospitalStaffDepartment::addNurse(string& dept, Nurse& nurse) {
    string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + dept + "/Staff/nurse.csv";

    ofstream file(filetype, ios::app);
    if (file.is_open()) {
        file << nurse.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << filename + ".csv" << endl;
    }
}
void HospitalStaffDepartment::addFacilityServicesStaff(string& dept, FacilityServicesStaff& facilityStaff){
    string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + dept + "/Staff/facilityStaff.csv";

    ofstream file(filetype, ios::app);
    if (file.is_open()) {
        file << facilityStaff.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "facilityStaff.csv" << endl;
    }
}
void HospitalStaffDepartment::addSocialServicesStaff(string& dept, SocialServicesStaff& socialStaff) {
    string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + dept + "/Staff/socialStaff.csv";

    ofstream file(filetype, ios::app);
    if (file.is_open()) {
        file << socialStaff.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "socialStaff.csv" << endl;
    }
}
void HospitalStaffDepartment::addSupportStaff(string& dept, SupportStaff& supportStaff) {
    string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + dept + "/Staff/supportStaff.csv";

    ofstream file(filetype, ios::app);
    if (file.is_open()) {
        file << supportStaff.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "supportStaff.csv" << endl;
    }
}
void HospitalStaffDepartment::addHospitalist(string& dept, Hospitalist& hospitalist) {
    string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + dept + "/Staff/hospitalist.csv";

    ofstream file(filetype, ios::app);
    if (file.is_open()) {
        file << hospitalist.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "hospitalist.csv" << endl;
    }
}
void HospitalStaffDepartment::addDietaryServiceStaff(string& dept, DietaryServiceStaff& dietaryStaff) {
    string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + dept + "/Staff/dietaryStaff.csv";

    ofstream file(filetype, ios::app);
    if (file.is_open()) {
        file << dietaryStaff.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "dietaryStaff.csv" << endl;
    }
}


void HospitalStaffDepartment::removeStaffMember(const string& id, const string& filename) {
    // Remove staff member from the vector and update the file
    removePerson(id, filename);
    string doctorschedule = filename + "s/" + id + "_schedule.csv";
    remove(doctorschedule.c_str());
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
static bool x = true;
void HospitalStaffDepartment::seedoctorAvailability(string& deptt) {
    string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctor.csv";
    ifstream file(filetype);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filetype << endl;
        return;
    }
    string line;
    do {
            getline(file, line);
            stringstream ss(line);
            string currentId;
            getline(ss, currentId, ',');

            checkDoctorAvailability(deptt, currentId);
        
    }while (x);
      file.close();
}
void HospitalStaffDepartment::checkDoctorAvailability(string deptt, const string& doctorId) {
    string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctors/";
    ifstream file("../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctors/" + doctorId + "_schedule.csv");
    string line, time, status, name, contact;
    if (file.is_open()) {
        do {
                getline(file, line);
                stringstream ss(line);
                getline(ss, time, ',');
                getline(ss, status, ',');
                if (status == "Available") {
                   
                    string docinfo = "../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctor";
                    ifstream file(docinfo + ".csv");
                    if (!file.is_open()) {
                        cerr << "Error opening file: " << docinfo << endl;
                    }
                    else {
                        string line;
                        while (getline(file, line)) {
                            stringstream ss(line);
                            string currentId;

                            getline(ss, currentId, ',');
                            if (currentId == doctorId)
                            {
                                getline(ss, name, ',');
                                getline(ss, contact, ',');
                                getline(ss, contact, ',');

                            }
                        }
                    }
                    cout << "Earliest available slot for " + name + " is at " + time + ".\n Doctor's contact : " + contact + "\n";
                    x = false;
                    cout << "Do you want to book this appointment ? \n 1.Yes \n 2.No" << endl;
                    int y;
                    cin >> y;
                    if (y == 1) {
                        string fileaddress = "../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctors/";
                        bookappointment(deptt, doctorId, time, fileaddress);
                    }
                    else { cout << "Appointment not booked.\n"; }
                };
        } while (x);
        file.close();
    }
    else {
        cout << "Unable to open schedule file for doctor " + doctorId << endl;
    }
}
void HospitalStaffDepartment::checkallDoctorAvailability(string deptt) {
   
    string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctor.csv";
    ifstream file(filetype);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filetype << endl;
    }
    else {
        string line, currentId;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, contact;
        getline(ss, currentId, ',');
        getline(ss, name, ',');
        getline(ss, contact, ',');
        getline(ss, contact, ',');


        string filetype2 = "../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctors/";
        ifstream file2(filetype2 + currentId + "_schedule.csv");
        string line, time, status;
        vector <string> slots;
        if (file2.is_open()) {
            bool x = true;
            while(getline(file2, line)){
                stringstream ss(line);
                getline(ss, time, ',');
                getline(ss, status, ',');
                if (status == "Available") {
                    slots.push_back(time);
                };
                }
                cout << "Available Slots: \n" << "Doctor Id : " << currentId << "\n Name : " << name << "\nTime : \n";
                for (string x : slots)
                {
                    cout << x << endl;
                }
                cout << ".\nDoctor's contact : " << contact << "\n";
            file2.close();
        }
        else {
            cout << "Unable to open schedule file for doctor " + currentId << endl;
        }
        }
    cout << "Do you want to Book appointment ?\n1. Yes\n2.No\n";
    int k;
    string id, selecttime;
    cin >> k;
    if(k==1){
    cout << "Which Appointment do you want to book ? ";
    cout << "Enter Doctor Id: "; cin >> id;
    cout << "\nEnter Slot Time: "; cin >> selecttime;

        string fileaddress = "../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctors/";
        bookappointment(deptt, currentId, selecttime, fileaddress);
    }
    else { cout << "Appointment not booked.\n"; }

    }
    file.close();
    
    /*string filetype = "../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctors/";
    ifstream file(filetype + doctorId + "_schedule.csv");
    string line, time, status, name, contact;
    bool x = true;
    if (file.is_open()) {
        do {
            getline(file, line);
            stringstream ss(line);
            getline(ss, time, ',');
            getline(ss, status, ',');
            if (status == "Available") {
                x = false;
                string docinfo = "../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctor";
                ifstream file(docinfo + ".csv");
                if (!file.is_open()) {
                    cerr << "Error opening file: " << docinfo << endl;
                }
                else {
                    string line;
                    while (getline(file, line)) {
                        stringstream ss(line);
                        string currentId;

                        getline(ss, currentId, ',');
                        if (currentId == doctorId)
                        {
                            getline(ss, name, ',');
                            getline(ss, contact, ',');
                            getline(ss, contact, ',');

                        }
                    }
                }
                cout << "Earliest available slot for " + name + " is at " + time + ".\n Doctor's contact : " + contact + "\n";
                cout << "Do you want to book this appointment ? \n 1.Yes \n 2.No" << endl;
                int y;
                cin >> y;
                if (y == 1) {
                    string fileaddress = "../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctors/";
                    bookappointment(deptt, doctorId, time, fileaddress);
                }
                else { cout << "Appointment not booked.\n"; }
            }
        } while (x);
        file.close();
    }
    else {
        cout << "Unable to open schedule file for doctor " + doctorId << endl;
    }*/
}
void HospitalStaffDepartment::bookappointment(string deptt, string docId, string time, const string address) {

    ifstream file(address + docId + "_schedule.csv");
    ofstream tempFile(address + docId + "_scheduletemp_.csv", ios::trunc);

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string readtime;
        getline(ss, readtime, ',');
        if (readtime != time) {
            tempFile << line << endl;

        }
        else
        {
            tempFile << time << "," << "Not Available" << endl;
            cout << "Appointment for the time " + time + "has been booked." << endl;
        }
    }

    file.close();
    tempFile.close();

    ifstream tempFile2(address + docId + "_scheduletemp_.csv");
    ofstream file2(address + docId + "_schedule.csv", ios::trunc);
    while (getline(tempFile2, line)) {
        stringstream ss(line);
        file2 << line << endl;
    }
}
void HospitalStaffDepartment::freeslot(string deptt, string docId, string time) {

    ifstream file("../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctors/" + docId + "_schedule.csv");
    ofstream tempFile("../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctors/" + docId + "_scheduletemp_.csv", ios::trunc);

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string readtime;
        getline(ss, readtime, ',');
        if (readtime != time) {
            tempFile << line << endl;

        }
        else
        {
            tempFile << time << "," << "Available" << endl;
            cout << "Slot for the time " + time + "has been relieved." << endl;
        }
    }

    file.close();
    tempFile.close();

    ifstream tempFile2("../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctors/" + docId + "_scheduletemp_.csv");
    ofstream file2("../OOP Project 2/Data/Departments/MedicalDepartments/" + deptt + "/Staff/doctors/" + docId + "_schedule.csv", ios::trunc);
    while (getline(tempFile2, line)) {
        stringstream ss(line);
        file2 << line << endl;
    }
}
    /*
    const char* l = "C:/Users/Hamza Irshad/source/repos/OOP Project 2/OOP Project 2/Data/Departments/MedicalDepartments/Cardiology/Staff/doctors/001_schedule.csv";
    int p=remove(l);
    string a = address + docId + "_schedule.csv";
    const char* c = a.c_str();
    string b = address + docId + "_scheduletemp_.csv";
    const char* d = b.c_str();
    std::remove(a.c_str());
    int x = rename(d, c);
    */


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