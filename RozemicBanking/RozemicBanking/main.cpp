//
//  main.cpp
//  RozemicBanking
//
//  Created by Eric Wiley on 1/14/21.
//

	#include <iostream>
	#include <string>
	#include <array>
	/***************************************************************
	<array> was chosen due to the input requirements being the same
	for all users.
	****************************************************************/
	
	
	std::array<std::string,4> customerHome(std::string firstname="N/A",std::string lastname="N/A",std::string address="N/A",std::string zip="N/A" )
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
		
		if (zip == "N/A")
		{
			std::cout << "Enter Zip Code:\n";
			std::cin >> input1;
			zip = input1;
		}
		
		std::array<std::string,4> newcustomer{firstname,lastname,address,zip};
		
		return newcustomer;
		
	}


	int main(void)
	{
		std::array<std::string,4> customer;
		
		
		customer = customerHome("John","Doe");
		for(int i=0; i < 4; i++)
			std::cout << customer[i] << "\n";
		
		return 0;
	}
