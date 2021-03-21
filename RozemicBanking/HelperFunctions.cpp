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
void accountServices(UserAccounts *accounts);
void saveJson(UserAccounts *accounts);



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

void accountServices(UserAccounts *accounts) {
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
}

void saveJson(UserAccounts *accounts) {
    json jsonFile = accounts->setJson(
        //Checking
        checkingBalance(accounts),                      // Account Balance
        accounts->getChecking().getTransactionTotal(),  // Transaction Total
        accounts->getChecking().getTransactionLimit(),  // Transaction Limit
        accounts->getChecking().getTransactions(),      // Vector of all transactions
        //Savings
        savingsBalance(accounts),                       // Account Balance                    
        accounts->getSavings().getTransactionTotal(),   // Transaction Total
        accounts->getSavings().getTransactionLimit(),   // Transaction Limit
        accounts->getSavings().getTransactions(),       // Vector of all transactions
        //Customer Info
        accounts->getCustomer().firstname,      // First Name
        accounts->getCustomer().lastname,       // Last Name
        accounts->getCustomer().address,        // Address
        accounts->getCustomer().city,           // City
        accounts->getCustomer().state,          // State
        accounts->getCustomer().zipcode         // Zip Code
        );
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
        cin.ignore(1000, '\n');
        getline(cin, input1);
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
