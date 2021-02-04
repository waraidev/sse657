//
//  main.cpp
//  RozemicBanking
//
//  Created by Eric Wiley on 1/14/21.
//

#include <iostream>
#include <string>
#include <array>
#include "UserAccount.cpp"
#include "CustomerInfo.cpp"

using namespace std;


/***************************************************************
<array> was chosen due to the input requirements being the same
for all users.
****************************************************************/


array<string, 6> customerHome(string firstname = "N/A", string lastname = "N/A", string address = "N/A",
             string city = "N/A", string state = "N/A", string zip = "N/A") {
    /*************************************************************
    This function will be used to input user information.
    Defaulting to N/A will allow searches for incomplete entries.
    **************************************************************/
    string input1;
    if (firstname == "N/A") {
        cout << "Enter First Name:\n";
        cin >> input1;
        firstname = input1;
        cout << endl;
    }


    if (lastname == "N/A") {
        cout << "Enter Last Name:\n";
        cin >> input1;
        lastname = input1;
        cout << endl;
    }

    if (address == "N/A") {
        cout << "Enter Address: (Hit ENTER twice!)" << endl;
        /***************************************************
        Use getline to allow input that will be more than a
        word long.
        ****************************************************/
        getline(cin, input1);
        cin.ignore();
        address = input1;
        cout << endl;
    }

    if (city == "N/A") {
        cout << "Enter City:\n";
        cin >> input1;
        city = input1;
        cout << endl;
    }

    if (state == "N/A") {
        cout << "Enter State:\n";
        cin >> input1;
        state = input1;
        cout << endl;
    }

    if (zip == "N/A") {
        cout << "Enter Zip Code:\n";
        cin >> input1;
        zip = input1;
        cout << endl;
    }

    array<string, 6> newcustomer = {firstname, lastname, address, city, state, zip};

    return newcustomer;

}

int main(void) {
    array<string, 6> customer;
    double initBalance;    

    customer = customerHome("John", "Doe");

    cout << "What is your initial balance?" << endl;

    cin >> initBalance;

    UserAccount account(initBalance);

    account.setCustomer(CustomerInfo(customer[0], customer[1], customer[2], customer[3], customer[4], customer[5]));

    cout << account.getCustomer().printInfo() << endl;
    //cout << account.getCustomer() << endl;
    cout << "Your checking balance is $" << account.getBalance(false) << endl;
    cout << "Your savings balance is $" << account.getBalance(true) << endl;

    char withdraw;
    double amount;
    char accountType;
    bool savings;

    cout << "Do you want to withdraw or deposit?\n Choose W or D: ";

    cin >> withdraw;
    cout << endl;

    switch (withdraw)
    {
    case 'W':
        cout << "How much do you want to withdraw? ";
        cin >> amount;
        account.withdraw(amount);
        break;
    
    case 'D':
        cout << "Do you want to deposit to checking or savings?\n Choose C or S: ";
        cin >> accountType;
        cout << endl;
        switch(accountType)
        {
            case 'C':
                savings = false;
                cout << "How much do you want to deposit? ";
                cin >> amount;
                break;

            case 'S':
                savings = true;
                cout << "How much do you want to deposit? ";
                cin >> amount;
                break;

            default:
                cout << "Incorrect choice!" << endl;
                amount = 0;
                break;
        }

        account.deposit(amount, savings);
        break;
        

    default:
        cout << "Incorrect choice!" << endl;
        break;
    }


    return 0;
}
