#ifndef ACCESS
#define ACCESS

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

// #include <vector> and <string> from json.hpp
#include "../External/json.hpp"

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

    public:
        std::string password;
        std::string firstname;
        std::string lastname;
        std::string address;
        std::string city;
        std::string state;
        std::string zipcode;
        
        //Constructor
        CustomerInfo(std::string password = "N/A",   
                        std::string firstname = "N/A",
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
            swap(lhs.password, rhs.password);
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



class BankAccount
{
    private:
        double balance;

        static double transactionLimit;

        double transactionTotal;

    public:
        BankAccount();

        BankAccount(double initialBalance);

        double getBalance();

        double getTransactionTotal();

        void deposit(double amount);

        void withdraw(double amount);

        std::vector<std::string> getTransactions();

        void addTransaction(std::string transaction);

        std::vector<std::string> transactionList;

        double getTransactionLimit(); 

        void setTransactionLimit(double limit);     

        bool checkLimit(double amount); 

        void addToTransactionTotal(double amount); 
};

/** A user account that has a balance that can be changed by deposits and withdrawals. */
class UserAccounts 
{
    friend class BankAccountFixture;

private:
    BankAccount checking;
    BankAccount savings;
    CustomerInfo customer;
    
    static UserAccounts *instance;

    /** Constructs a user account with a balance of zero. */
    UserAccounts() {
        checking = 0;
        savings = 0;
    }

    void printLimitExceeded();

public:
    static UserAccounts* createAccount();

    void deposit(double amount, bool isSavings);

    void withdraw(double amount);

    void transfer(char sending, char receiving, double amount);

    CustomerInfo getCustomer();

    void setCustomer(CustomerInfo c);

    BankAccount getChecking();

    void setChecking(BankAccount check);

    BankAccount getSavings();

    void setSavings(BankAccount save);

    nlohmann::json getJson();

    nlohmann::json setJson(
        double c_balance, double c_total, 
        double c_limit, std::vector<std::string> c_transactions,
        double s_balance, double s_total,
        double s_limit, std::vector<std::string> s_transactions,
        std::string password, std::string firstname, std::string lastname,
        std::string address, std::string city, 
        std::string state, std::string zipcode);

    void setJson(nlohmann::json obj);
};

#endif