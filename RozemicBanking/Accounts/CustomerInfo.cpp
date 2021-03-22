#include <iostream>
#include <string>
#include "Access.h"
	
using namespace std;

//Constructor
CustomerInfo::CustomerInfo(string password, string first, string last, string address, 
                            string city, string state, string zip) 
{
    this->password = password;
    this->firstname = first;
    this->lastname = last;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zipcode = zip;
}

//Copy Constructor
CustomerInfo::CustomerInfo(const CustomerInfo &value) 
{
    this->password = value.password;
    this->firstname = value.firstname;
    this->lastname = value.lastname;
    this->address = value.address;
    this->city = value.city;
    this->state = value.state;
    this->zipcode = value.zipcode;
}

//Destructor
CustomerInfo::~CustomerInfo() 
{
    //std::cout << "Destructor Called\n";
}

//Overloaded Assignment
CustomerInfo &CustomerInfo::operator=(CustomerInfo &unknown) {
    swap(*this, unknown);
    return *this;
}

string CustomerInfo::printInfo() {
	return "First Name:\t" + this->firstname + "\n"
		+ "Last Name:\t" + this->lastname + "\n"
    	+ "Address:\t" + this->address + "\n"
    	+ "City:\t\t" + this->city + "\n"
    	+ "State:\t\t" + this->state + "\n"
    	+ "Zip Code:\t" + this->zipcode + "\n"
        + "Password Status:\t Valid!";
}
