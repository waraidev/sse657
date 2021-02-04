#ifndef CUSTOMER_INPUT
#define CUSTOMER_INPUT

#include <iostream>
#include <string>

/*
#include <thread>
#include <mutex>

	mutex mutually;

	//Setup For Multithreaded Code
	class thread_guard
	{
		private:
			thread& t;
		public:
			explicit thread_guard(thread& t_) : t(t_) { }

			~thread_guard()
			{
				if(t.joinable())
				{
					t.join();
				}
			}

			thread_guard(thread_guard const&)=delete;
			thread_guard& operator=(thread_guard const&)=delete;

	};
*/

class CustomerInfo 
{
    private:
        std::string firstname;
        std::string lastname;
        std::string address;
        std::string city;
        std::string state;
        std::string zipcode;

    protected:

    public:

        //Getters
        std::string getFirstName();
        std::string getLastName();
        std::string getAddress();
        std::string getCity();
        std::string getState();
        std::string getZipCode();

        //Setters
        std::string setFirstName(std::string first);
        std::string setLastName(std::string last);
        std::string setAddress(std::string address);
        std::string setCity(std::string city);
        std::string setState(std::string state);
        std::string setZipCode(std::string zip);

        //Constructor
        CustomerInfo(std::string firstname = "N/A",
                        std::string lastname = "N/A",
                        std::string address = "N/A",
                        std::string city = "N/A",
                        std::string state = "N/A",
                        std::string zip = "N/A");

        //Copy Constructor
        CustomerInfo(const CustomerInfo &value);

        //Overloaded Assignment
        CustomerInfo &operator=(CustomerInfo &unknown);

        //Destructor
        ~CustomerInfo();
    
        //swap Function
        void swap(CustomerInfo &lhs, CustomerInfo &rhs) 
        {
            using std::swap;
            swap(lhs.firstname, rhs.firstname);
            swap(lhs.lastname, rhs.lastname);
            swap(lhs.address, rhs.address);
            swap(lhs.city, rhs.city);
            swap(lhs.state, rhs.state);
            swap(lhs.zipcode, rhs.zipcode);
        }

        std::string printInfo();
};

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
    std::cout << "Destructor Called\n";
}

#endif
