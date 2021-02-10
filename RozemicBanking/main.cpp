//
//  main.cpp
//  RozemicBanking
//
//  Created by Eric Wiley on 1/14/21.
//

#include <iostream>
#include <string>
#include <array>
#include "Accounts/UserAccounts.cpp"
#include "Accounts/BankAccount.cpp"
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

    //Setup customer account//
    customer = customerHome("John", "Doe");

    cout << "What is your initial balance?" << endl;

    cin >> initBalance;

    UserAccounts accounts(initBalance);

    accounts.setCustomer(CustomerInfo(customer[0], customer[1], customer[2], customer[3], customer[4], customer[5]));

    cout << accounts.getCustomer().printInfo() << endl;
    //cout << account.getCustomer() << endl;
    cout << "Your checking balance is $" << accounts.getChecking().getBalance() << endl;
    cout << "Your savings balance is $" << accounts.getSavings().getBalance() << endl;

    //Account Services//
    char service;
    double amount;

    //Depositing
    char accountType;
    bool savings;

    //Transfer
    string sending;
    char verifyTransfer;

    cout << "Do you want to withdraw, deposit, or transfer?\n";
    cout << "Withdraw: (W)\nDeposit: (D)\nTransfer: (T)\nExit: (E)\n" << "Choose an option: ";

    cin >> service;
    cout << endl;

    switch (toupper(service)) {   //Withdrawing and Depositing//
        case 'W':
            cout << "How much do you want to withdraw? ";
            cin >> amount;
            if (accounts.getChecking().getBalance() - amount < 0)
                cout << "Error: insufficient funds. You only have $" << accounts.getChecking().getBalance() << " in your account." << endl;
            else
                accounts.withdraw(amount);
            break;

        case 'D':
            cout << "Do you want to deposit to checking or savings?\n Choose C or S: ";
            cin >> accountType;
            cout << endl;
            switch (toupper(accountType)) {
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

            accounts.deposit(amount, savings);
            break;

        case 'T':   //Transferring money

            cout << "From Account (Checking or Savings): ";
            cin >> sending;
            if (tolower(sending[0]) == 'c') {
                cout << "\nTransfer Type: Checking --> Savings (Yes or No)" << endl;
                cout << "Choose Y/N: ";
                cin >> verifyTransfer;
                cout << endl;
                if (verifyTransfer == 'Y' || verifyTransfer == 'y') {
                    cout << "How much do you want to transfer? ";
                    cin >> amount;
                    accounts.transfer('C', 'S', amount); //Transfer from Checking to Savings
                } else {
                    cout << "No money was transferred." << endl;
                }
            } else if (tolower(sending[0]) == 's') {
                cout << "\nTransfer Type: Savings --> Checking (Yes or No)" << endl;
                cout << "Choose Y/N: ";
                cin >> verifyTransfer;
                cout << endl;
                if (verifyTransfer == 'Y' || verifyTransfer == 'y') {
                    cout << "How much do you want to transfer? ";
                    cin >> amount;
                    accounts.transfer('S', 'C', amount); //Transfer from Savings to Checking
                } else {
                    cout << "No money was transferred." << endl;
                }
            } else {
                cout << "Error: Incorrect input. No money was transferred." << endl;
            }
            break;


        default:
            cout << "Incorrect choice!" << endl;
            break;
    }

    cout << endl;

    //Finishing Bank Use//
    cout << "Thank you for choosing Rozemic Banking! Have a great day!" << endl;


    return 0;
}
