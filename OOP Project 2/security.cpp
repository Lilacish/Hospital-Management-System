#include "security.h"

Guard::Guard(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position)
    : Staffmember(id, name, age, contactNumber, address, dutyTime, salary, position) {}


void Securitymanager::addguard(Guard& guard) {
    ofstream file("guards.csv", ios::app);
    if (file.is_open()) {
        file << guard.getFormattedDetails() << endl;
        file.close();
    }
    else {
        cout << "Unable to open file: " << "guard.csv" << endl;
    }

}
