#ifndef ACCESS
#define ACCESS

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

        //friend std::ostream &operator<<(std::ostream out, CustomerInfo &info);
};

/** A user account that has a balance that can be changed by deposits and withdrawals. */
class UserAccount 
{

private:
    double checkingBalance;
    double savingsBalance;

    CustomerInfo customer;

public:
    UserAccount();

    UserAccount(double initialBalance);

    void deposit(double amount, bool isSavings);

    void withdraw(double amount);

    void transfer(char sending, char receiving, double amount);

    double getBalance(bool isSavings);

    CustomerInfo getCustomer();

    CustomerInfo setCustomer(CustomerInfo c);

};

class Checking : public UserAccount 
{
    

};

#endif