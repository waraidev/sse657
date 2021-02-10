#include <iostream>
#include <string>
#include "Accounts/Access.h"
	
using namespace std;

//Constructor
CustomerInfo::CustomerInfo(std::string first, std::string last, std::string address, 
                            std::string city, std::string state, std::string zip) 
{
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
    	+ "Zip Code:\t" + this->zipcode + "\n";
}

// int main()
// {
// 	CustomerInfo addcustomer("John", "Doe","3001 Mercer University Dr", "Atlanta", "GA", "30341");
// 	std::cout << addcustomer << '\n';
// }
