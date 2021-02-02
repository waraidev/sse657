#ifndef CUSTOMER_INPUT
#define CUSTOMER_INPUT

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

//	mutex mutually;
//
//	//Setup For Multithreaded Code
//	class thread_guard
//	{
//		private:
//			thread& t;
//		public:
//			explicit thread_guard(thread& t_) : t(t_) { }
//
//			~thread_guard()
//			{
//				if(t.joinable())
//				{
//					t.join();
//				}
//			}
//
//			thread_guard(thread_guard const&)=delete;
//			thread_guard& operator=(thread_guard const&)=delete;
//
//	};

class CustomerInfo {
private:
    string firstname;
    string lastname;
    string address;
    string city;
    string state;
    string zipcode;

    //Overloaded stream Operator
    friend ostream &operator<<(ostream &output, const CustomerInfo &info);

protected:

public:
    //Constructor
    CustomerInfo(string firstname = "N/A",
                 string lastname = "N/A",
                 string address = "N/A",
                 string city = "N/A",
                 string state = "N/A",
                 string zip = "N/A");

    //Copy Constructor
    CustomerInfo(const CustomerInfo &value);

    //Overloaded Assignment
    CustomerInfo &operator=(CustomerInfo &unknown);

    //Destructor
    ~CustomerInfo();

    //Insert
    void insert(const string &words);

    //swap Function
    void swap(CustomerInfo &lhs, CustomerInfo &rhs) {
        using std::swap;
        swap(lhs.firstname, rhs.firstname);
        swap(lhs.lastname, rhs.lastname);
        swap(lhs.address, rhs.address);
        swap(lhs.city, rhs.city);
        swap(lhs.state, rhs.state);
        swap(lhs.zipcode, rhs.zipcode);
    }
};

//Constructor
CustomerInfo::CustomerInfo(string first, string last, string address, 
        string city, string state, string zip) {
    this->firstname = first;
    this->lastname = last;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zipcode = zip;
}

//Copy Constructor
CustomerInfo::CustomerInfo(const CustomerInfo &value) {
    this->firstname = value.firstname;
    this->lastname = value.lastname;
    this->address = value.address;
    this->city = value.city;
    this->state = value.state;
    this->zipcode = value.zipcode;
}

//Overloaded Assignment
CustomerInfo &CustomerInfo::operator=(CustomerInfo &unknown) {
    swap(*this, unknown);
    return *this;
}

//Destructor
CustomerInfo::~CustomerInfo() {
    cout << "Destructor Called\n";
}

ostream &operator<<(ostream &output, const CustomerInfo &info) {
    output << "First Name:\t" << info.firstname << "\n";
    output << "Last Name:\t" << info.lastname << "\n";
    output << "Address:\t" << info.address << "\n";
    output << "City:\t\t" << info.city << "\n";
    output << "State:\t\t" << info.state << "\n";
    output << "Zip Code:\t" << info.zipcode << "\n";

    return output;
}

#endif
