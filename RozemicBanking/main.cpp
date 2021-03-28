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
using json = nlohmann::json;

int main(void) {
    char hasAccount;

    UserAccounts *accounts;

    cout << "Do you already have an account with Rozemic Banking? (Y/N)" << endl;

    cin >> hasAccount;
    cout << endl;

    switch(toupper(hasAccount)) {
        case 'Y':
            accounts = getAccount(true);
            break;

        case 'N':
            accounts = getAccount(false);
            break;
        
        default:
            cout << "Error: Invalid choice, the program will exit now!" << endl;
            return 0;
    }

    if(accounts == 0) {
        cout << "We apologize, but this account does not exist!" << endl;
    } else {
        accountServices(accounts);

        //Save to JSON
        saveJson(accounts);
    }

    //Finishing Bank Use//
    cout << "Thank you for choosing Rozemic Banking! Have a great day!" << endl;


    return 0;
}
