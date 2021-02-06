#ifndef Access
#define Access

	#include <iostream>
	#include <string>

	
	class UserAccount
	{
		private:
						
		protected:
			double checkingBalance;
			double savingsBalance;
			double money;
			
			
		public:
			virtual double Depositor(double deposit) {};
			virtual double Withdrawl(double withdraw) {};
			virtual void Display() = 0;
			virtual void note() = 0; 
			UserAccount(double initialBalance) { money = initialBalance; } 
		
			virtual ~UserAccount() = default;
			UserAccount() = default;
			UserAccount& operator=(UserAccount&& value) 
			{ 
				money = std::move(value.money);
				return*this;
			} 
		
			UserAccount& operator=(const UserAccount&) {return*this;}
	}; 
	
	class Checking : public UserAccount
	{ 
		public: 
				Checking(double initialBalance) : UserAccount(initialBalance){checkingBalance = money;	};	
				void note() override
				{	
					std::cout << "Checking Account Balance: " << checkingBalance << '\n'; 
				}
			
			Checking& operator=(Checking&&) = default; 
			Checking& operator=(const Checking&) = default;
		
			~Checking() {}; 
			
			double Depositor(double deposit) override {
				checkingBalance = checkingBalance + deposit;
				return checkingBalance;
			} 
			
			double Withdrawl(double withdraw) override {
				double temp = checkingBalance;
				checkingBalance = checkingBalance - withdraw;
				if(checkingBalance < 0 && checkingBalance >= - 5)
				{
					std::cout << "Your Checking Is Below $0.00" << "\n";
					return checkingBalance;
				}
				else if(checkingBalance < -5 && checkingBalance >= -50)
				{
					std::cout << "Your Checking Is Below $(5.00)" << "\n";
					std::cout << "As A Result Your Account Will Incur a $15.00 Charge." << "\n";
					checkingBalance = checkingBalance - 15;
					return checkingBalance;
				}
				else if(checkingBalance < -50)
				{
					std::cout << "Insufficient Funds." << "\n";
					checkingBalance = temp;
					return temp;
				}
				else
				{
					return checkingBalance;
				}
			}
			
			void Display() override {
				std::cout << "Checking Balance: " << checkingBalance << "\n";
			}
	}; 
	
	
	class Savings : public UserAccount
	{ 
		public: 
				Savings(double initialBalance) : UserAccount(initialBalance){ savingsBalance = money; };	
				void note() override
				{	
					std::cout << "Savings Account Balance: " << savingsBalance << "\n"; 
				}
			
			Savings& operator=(Savings&&) = default; 
			Savings& operator=(const Savings&) = default;
		
			~Savings() {}; 
			
			double Depositor(double deposit) override {
				savingsBalance = savingsBalance + deposit;
				return savingsBalance;
			} 
			
			double Withdrawl(double withdraw) override {
				double temp = savingsBalance;
				savingsBalance = savingsBalance - withdraw;
				/*
				Savings accounts are not allowed to go under $0.00
				*/
				if(savingsBalance < 0.00)
				{
					std::cout << "Insufficient Funds." << "\n";
					savingsBalance = temp;
					return savingsBalance;
				}
				else
				{
					return savingsBalance;
				}
			}
			
			void Display() override {
				std::cout << "Savings Balance: " << savingsBalance << "\n";
			}
	}; 
	


#endif
