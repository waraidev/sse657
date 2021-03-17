//
// Created by User on 2/1/2021.
//

#include "Access.h"

using namespace std;
using json = nlohmann::json;

UserAccounts* UserAccounts::instance = 0;

/**
 * Creates a persisting instance of UserAccounts
 * with the Singleton design pattern. This allows
 * the checking and savings accounts to be non-static,
 * yet persistent throughout code run.
 */ 
UserAccounts* UserAccounts::createAccount() {
    if(!instance) {
        instance = new UserAccounts();
    }

    return instance;
}

/**
 * Gets the CustomerInfo object associated
 * with the UserAccount
 */
CustomerInfo UserAccounts::getCustomer() {
    return this->customer;
}

/**
 * Gets the CustomerInfo object associated
 * with the UserAccount
 */
void UserAccounts::setCustomer(CustomerInfo c) {
    this->customer = c;
}

/**
 * Deposits money into the user's checking or savings account.
 * @param amount The amount to deposit.
 */
void UserAccounts::deposit(double amount, bool isSavings) {
    if(isSavings && this->savings.checkLimit(amount)) {
        double currSavings = this->savings.getBalance();
        this->savings.deposit(amount);
        cout << "Your new savings balance is (";
        cout << currSavings;
        cout << " + ";
        cout << amount;
        cout << "): $";
        cout << this->savings.getBalance() << endl;
    } else if(!isSavings && this->checking.checkLimit(amount)){
        double currChecking = this->checking.getBalance();;
        this->checking.deposit(amount);
        cout << "Your new checking balance is (";
        cout << currChecking;
        cout << " + ";
        cout << amount;
        cout << "): $";
        cout << this->checking.getBalance() << endl;
    } else {
        printLimitExceeded();
    }
}

/**
 * Withdraws money into the user's account.
 * @param amount The amount to withdraw.
 */
void UserAccounts::withdraw(double amount) {
    if(this->checking.checkLimit(amount)) {
        double current = this->checking.getBalance();
        this->checking.withdraw(amount);
        cout << "Your new checking balance is (";
        cout << current;
        cout << " - ";
        cout << amount;
        cout << "): $";
        cout << this->checking.getBalance() << endl;
    } else {
        printLimitExceeded();
    }
}

void UserAccounts::transfer(char sending, char receiving, double amount) {
    if(this->checking.checkLimit(amount) && this->savings.checkLimit(amount)) {
        if(sending == 'C' && receiving == 'S') {
            this->checking.withdraw(amount);
            this->savings.deposit(amount);
        } else if(sending == 'S' && receiving == 'C') {
            this->savings.withdraw(amount);
            this->checking.deposit(amount);
        } else {
            cout << "Error in input: No funds were transferred." << endl;
        }
    } else {
        printLimitExceeded();
    }

    cout << "Your checking balance is $" << this->checking.getBalance() << endl;
    cout << "Your savings balance is $" << this->savings.getBalance() << endl; 
}

BankAccount UserAccounts::getChecking() {
    return this->checking;
}

void UserAccounts::setChecking(BankAccount check) {
    this->checking = check;
}

BankAccount UserAccounts::getSavings() {
    return this->savings;
}

void UserAccounts::setSavings(BankAccount save) {
    this->savings = save;
}

void UserAccounts::printLimitExceeded() {
    cout << "Transaction Limit was exceeded with this purchase.";
    cout << " Transaction will not be processed." << endl;
}

json UserAccounts::getJson() {
    fstream file;
    json j;
    file.open("../json/accounts.json");
    if(file) {
        file >> j;
    } else {
        j = {
            { "Accounts", {
                { "Checking", {
                    { "Balance", "" },
                    { "TransactionTotal", "" },
                    { "TransactionLimit", "" },
                    { "Transactions", {
                        {}
                    }}
                }},
                { "Savings", {
                    { "Balance", "" },
                    { "TransactionTotal", "" },
                    { "TransactionLimit", "" },
                    { "Transactions", {
                        {}
                    }}
                }},
                { "CustomerInfo", {
                    { "FirstName", "" },
                    { "LastName", "" },
                    { "Address", "" },
                    { "City", "" },
                    { "State", "" },
                    { "ZipCode", ""}
                }}
            }}
        };

        file << j;
    }

    return j;
}

void UserAccounts::setJson(json obj) {

}