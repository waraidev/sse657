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
#include "BusinessTransactions.cpp"

using namespace std;
using json = nlohmann::json;

int main(void) {

    UserAccounts *accounts;

    if(businessAccount()) {
        string id;
        cout << "What is the ID of the purchasing account?" << endl;
        cin >> id;
        cout << endl;

        accounts = accounts->createAccount();
        json jFile = accounts->getJson();
        
        try {
            if(jFile["Users"].at(id) != 0) {
                cout << "You choose ID number: " << id << endl;
            }
        } catch (json::exception& e) {
            cout << "Invalid ID: " << e.id << endl;
            return 0;
        }

        accounts->setAccountData(jFile, id);

        submitTransaction(accounts);

        saveJson(accounts, jFile);

        return 0;
    }

    char hasAccount;

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
        cout << "We apologize, but this account either does not exist or your password is incorrect!" << endl;
    } else {
        accountServices(accounts);

        json jFile = accounts->getJson();

        // Save to JSON
        if(jFile == NULL)
            saveJson(accounts);
        else
            saveJson(accounts, jFile);
    }

    //Finishing Bank Use//
    cout << "Thank you for choosing Rozemic Banking! Have a great day!" << endl;


    return 0;
}
