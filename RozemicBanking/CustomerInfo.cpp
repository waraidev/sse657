	#include <iostream>
	#include <string>
	#include <array>
	#include "CustomerInfo.h"
	#include "Access.h"
	
	using namespace std;

	
	/***************************************************************
	<array> was chosen due to the input requirements being the same
	for all users.
	****************************************************************/


	std::array<std::string,6> customerHome(std::string firstname="N/A",std::string lastname="N/A",std::string address="N/A",std::string city="N/A",std::string state="N/A",std::string zip="N/A")
	{
		/*************************************************************
		This function will be used to input user information.
		Defaulting to N/A will allow searches for incomplete entries.
		**************************************************************/
		std::string input1;
		if (firstname == "N/A")
		{
			std::cout << "Enter First Name:\n";
			std::cin >> input1;
			firstname = input1;
		}		


		if (lastname == "N/A")
		{
			std::cout << "Enter Last Name:\n";
			std::cin >> input1;
			lastname = input1;
		}

		if (address == "N/A")
		{
			std::cout << "Enter Address:\n";
			/***************************************************
			Use getline to allow input that will be more than a 
			word long.
			****************************************************/
			std::getline(std::cin,input1);
			std::cin.ignore();
			address = input1;
		}

		if (city == "N/A")
		{
			std::cout << "Enter City:\n";
			std::cin >> input1;
			city = input1;
		}

		if (state == "N/A")
		{
			std::cout << "Enter State:\n";
			std::cin >> input1;
			state = input1;
		}

		if (zip == "N/A")
		{
			std::cout << "Enter Zip Code:\n";
			std::cin >> input1;
			zip = input1;
		}

		std::array<std::string,6> newcustomer{firstname,lastname,address,city,state,zip};

		return newcustomer;

	}


	int main(void)
	{
		std::array<std::string,6> customer;
		double initBalance;


		customer = customerHome("John","Doe","3301 Mercer Dr.","Macon","GA","31098");
		
		cout << "How Much Money Will You Use To Open Your Checking Account?" << endl;
		cin >> initBalance;	
		//caccount = checking account	
		Checking caccount(initBalance);
		
		cout << "How Much Money Will You Use To Open Your Savings Account?" << endl;
		cin >> initBalance;
		//saccount = savings account
		Savings saccount(initBalance);
		
		/*
		account1 points to the checking account.
		account2 points to the savings account.
		*/
		UserAccount *account1 = &caccount;
		UserAccount *account2 = &saccount;
		account1->Depositor(125);
		account2->Withdrawl(125);
		
		account1->Display();
		account2->Display();
		
		account1->Withdrawl(500);
		account2->Depositor(500);
		
		account1->Display();
		account2->Display();

		CustomerInfo newCustomer(customer[0],customer[1],customer[2],customer[3],customer[4],customer[5]);
		std::cout << newCustomer << "\n";
		

		return 0;
	}
