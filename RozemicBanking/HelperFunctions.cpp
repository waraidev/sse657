#include <string>
#include <array>
#include "Accounts/Access.h"

using namespace std;

//Declarations

double savingsBalance(UserAccounts accounts);
double checkingBalance(UserAccounts accounts);

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

/**
 * Gets the balance of the user's savings account
 * @returns double
 */
double savingsBalance(UserAccounts accounts) {
    return accounts.getSavings().getBalance();
}

/**
 * Gets the balance of the user's checking account
 * @returns double
 */
double checkingBalance(UserAccounts accounts) {
    return accounts.getChecking().getBalance();
}
