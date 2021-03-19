#include <string>
#include <array>
#include "Accounts/Access.h"

using namespace std;
using json = nlohmann::json;

//Declarations

double savingsBalance(UserAccounts *accounts);
double checkingBalance(UserAccounts *accounts);

void initAccounts(UserAccounts *accounts, double initBalance);
UserAccounts* getAccount(bool hasAccount);


/***************************************************************
<array> was chosen due to the input requirements being the same
for all users.
****************************************************************/

array<string, 6> customerHome(
    string firstname = "N/A", 
    string lastname = "N/A", 
    string address = "N/A", 
    string city = "N/A", 
    string state = "N/A", 
    string zip = "N/A");

//Implementations

UserAccounts* getAccount(bool hasAccount) {
    array<string, 6> customer;
    double initBalance;
    double limit;

    if(hasAccount) {
        return 0;

    } else {
        //Setup customer account info
        customer = customerHome();

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

        return accounts;
    }
}

array<string, 6> customerHome(string firstname, string lastname, string address, string city, string state, string zip) {
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

void initAccounts(UserAccounts *accounts, double initBalance) {
    BankAccount check = BankAccount(initBalance);
    BankAccount save = BankAccount();

    accounts->setChecking(check);
    accounts->setSavings(save);
}

/**
 * Gets the balance of the user's savings account
 * @returns double
 */
double savingsBalance(UserAccounts *accounts) {
    return accounts->getSavings().getBalance();
}

/**
 * Gets the balance of the user's checking account
 * @returns double
 */
double checkingBalance(UserAccounts *accounts) {
    return accounts->getChecking().getBalance();
}
