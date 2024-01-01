#ifndef security_h
#define security_h

#include<iostream>
#include <string>
#include <vector>
#include "staff.h"

using namespace std;
class Guard :public Staffmember {
public:
    Guard(const string& id, const string& name, string& age, const string& contactNumber, const string& address, const string& dutyTime, const string& salary, const string& position);
};
class Securitymanager : public PersonManager {
    void addguard(Guard& guard);

};
#endif 
