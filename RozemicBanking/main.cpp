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
#include "Accounts/CustomerInfo.cpp"
#include "HelperFunctions.cpp"

using namespace std;

int main(void) {
    array<string, 6> customer;
    double initBalance;
    double limit;

    //Setup customer account//
    customer = customerHome("John", "Doe");

    cout << "What is your initial balance?" << endl;

    cin >> initBalance;

    UserAccounts *accounts = accounts->createAccount();

    initAccounts(accounts, initBalance);

    accounts->setCustomer(CustomerInfo(customer[0], customer[1], customer[2], customer[3], customer[4], customer[5]));

    cout << accounts->getCustomer().printInfo() << endl;
    cout << "Your checking balance is $" << checkingBalance(accounts) << endl;
    cout << "Your savings balance is $" << savingsBalance(accounts) << endl;

    cout << "What would you like your daily transaction limit for checking and savings to be? ";
    cin >> limit;
    accounts->getChecking().setTransactionLimit(limit);
    accounts->getSavings().setTransactionLimit(limit);

    cout << "Your daily limit is $" << limit << endl;

    //Account Services//
    char service;
    double amount;

    //Depositing
    char accountType;
    bool savings;

    //Transfer
    string sending;
    char verifyTransfer;

    while(toupper(service) != 'E') {
        cout << "Do you want to withdraw, deposit, or transfer?\n";
        cout << "Withdraw: (W)\nDeposit: (D)\nTransfer: (T)\nExit: (E)\n" << "Choose an option: ";

        cin >> service;
        cout << endl;

        switch (toupper(service)) {   //Withdrawing and Depositing//
            case 'W':
                cout << "How much do you want to withdraw? ";
                cin >> amount;
                if (checkingBalance(accounts) - amount < 0)
                    cout << "Error: insufficient funds. You only have $" << checkingBalance(accounts) << " in your account." << endl;
                else
                    accounts->withdraw(amount);
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

                accounts->deposit(amount, savings);
                break;

            case 'T':   //Transferring money

                cout << "From Account (Checking or Savings): ";
                cin >> sending;
                if (toupper(sending[0]) == 'C') {
                    cout << "\nTransfer Type: Checking --> Savings (Yes or No)" << endl;
                    cout << "Choose Y/N: ";
                    cin >> verifyTransfer;
                    cout << endl;
                    if (toupper(verifyTransfer) == 'Y') {
                        cout << "How much do you want to transfer? ";
                        cin >> amount;
                        accounts->transfer('C', 'S', amount); //Transfer from Checking to Savings
                    } else {
                        cout << "No money was transferred." << endl;
                    }
                } else if (toupper(sending[0]) == 'S') {
                    cout << "\nTransfer Type: Savings --> Checking (Yes or No)" << endl;
                    cout << "Choose Y/N: ";
                    cin >> verifyTransfer;
                    cout << endl;
                    if (toupper(verifyTransfer) == 'Y') {
                        cout << "How much do you want to transfer? ";
                        cin >> amount;
                        accounts->transfer('S', 'C', amount); //Transfer from Savings to Checking
                    } else {
                        cout << "No money was transferred." << endl;
                    }
                } else {
                    cout << "Error: Incorrect input. No money was transferred." << endl;
                }
                break;

            case 'E':
                break;

            default:
                cout << "Incorrect choice!" << endl;
                break;
        }
    }

    //Finishing Bank Use//
    cout << "Thank you for choosing Rozemic Banking! Have a great day!" << endl;


    return 0;
}
