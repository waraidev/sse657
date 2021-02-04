
#include <iostream>
#include <string>
#include "CustomerInfo.h"
	
using namespace std;

//Getters
string CustomerInfo::getFirstName() {
	return this->firstname;
}

string CustomerInfo::getLastName() {
	return this->lastname;
}

string CustomerInfo::getAddress() {
	return this->address;
}

string CustomerInfo::getCity() {
	return this->city;
}

string CustomerInfo::getState() {
	return this->state;
}

string CustomerInfo::getZipCode() {
	return this->zipcode;
}

//Setters
string CustomerInfo::setFirstName(string first) {
	this->firstname = first;
	return first;
}

string CustomerInfo::setLastName(string last) {
	this->lastname = last;
	return last;
}

string CustomerInfo::setAddress(string address) {
	this->address = address;
	return address;
}

string CustomerInfo::setCity(string city) {
	this->city = city;
	return city;
}

string CustomerInfo::setState(string state) {
	this->state = state;
	return state;
}

string CustomerInfo::setZipCode(string zip) {
	this->zipcode = zip;
	return zip;
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
