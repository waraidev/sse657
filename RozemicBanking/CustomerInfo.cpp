
#include <iostream>
#include <string>
#include "CustomerInfo.h"
	
using namespace std;

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
