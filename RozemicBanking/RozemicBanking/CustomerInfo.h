


	#ifndef CUSTOMER_INPUT
	#define CUSTOMER_INPUT
	
	#include <iostream>
	#include <string>
	#include <thread>
	#include <mutex>
	
	std::mutex mutually;
	
	//Setup For Multithreaded Code
	class thread_guard
	{
		private:
			std::thread& t;
		public:
			explicit thread_guard(std::thread& t_) : t(t_) { }
			
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
	
	class CustomerInfo
	{
		private:
			std::string firstname;
			std::string lastname;
			std::string address;
			std::string city;
			std::string state;
			int zipcode;
			
			//Overloaded stream Operator
			friend std::ostream& operator<<(std::ostream& ooutput, const CustomerInfo& info);
			
		protected:
						
		public:
			//Constructor
			CustomerInfo(std::string firstname = "N/A",
						 std::string lastname = "N/A",
						 std::string address = "N/A",
						 std::string city = "N/A",
						 std::string state = "N/A",
						 int zip = 10001);
			
			//Copy Constructor
			CustomerInfo(const CustomerInfo& value);
			
			//Overloaded Assignment
			CustomerInfo& operator=(CustomerInfo& unknown);
			
			//Destructor
			~CustomerInfo();
			
			//Insert
			void insert(const std::string& words);
			
			//swap Function
			void swap(CustomerInfo& lhs, CustomerInfo& rhs)
			{
				using std::swap;
				swap(lhs.firstname, rhs.firstname);
				swap(lhs.lastname,rhs.lastname);
				swap(lhs.address,rhs.address);
				swap(lhs.city,rhs.city);
				swap(lhs.state,rhs.state);
				swap(lhs.zipcode,rhs.zipcode);
			}
	};
	
	//Constructor
	CustomerInfo::CustomerInfo(std::string f, std::string l, std::string a, std::string c, std::string s, int z)
	{
		this->firstname = f;
		this->lastname = l;
		this->address = a;
		this->city = c;
		this->state = s;
		this->zipcode = z;		     						   	
	}
	
	//Copy Constructor
	CustomerInfo::CustomerInfo(const CustomerInfo& value)
	{
		this->firstname = value.firstname;
		this->lastname = value.lastname;
		this->address = value.address;
		this->city = value.city;
		this->state = value.state;
		this->zipcode = value.zipcode;
	}
	
	//Overloaded Assignment
	CustomerInfo& CustomerInfo::operator=(CustomerInfo& unknown)
	{
		swap(*this,unknown);
		return *this;
	}
	
	//Destructor
	CustomerInfo::~CustomerInfo()
	{
		std::cout << "Destructor Called\n";
	}
	
	std::ostream& operator<<(std::ostream& ooutput, const CustomerInfo& info)
	{
		ooutput << "First Name: " 	<< info.firstname << "\n";
		ooutput << "Last Name: "  	<< info.lastname << "\n";
		ooutput << "Address: " 		<< info.address << "\n";
		ooutput << "City: " 		<< info.city << "\n";
		ooutput << "State: " 		<< info.state << "\n";
		ooutput << "Zip Code:" 		<< info.zipcode << "\n";		
	}
	
	#endif
