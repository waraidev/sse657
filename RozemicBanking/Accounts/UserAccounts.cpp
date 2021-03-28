//
// Created by User on 2/1/2021.
//

#include "Access.h"
#include <functional>

using json = nlohmann::json;
using namespace std;

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
 * Retrieves all UserAccounts data from a JSON file. 
 * Must only be run after UserAccounts object
 * is initialized and password is checked.
 */
void UserAccounts::setAccountData(json jFile, string account_id) {
    json info = jFile["Users"][account_id]["CustomerInfo"];
    json checking = jFile["Users"][account_id]["Accounts"]["Checking"];
    json savings = jFile["Users"][account_id]["Accounts"]["Savings"];

    CustomerInfo c = CustomerInfo(
        info["Password"],
        info["FirstName"],
        info["LastName"],
        info["Address"],
        info["City"],
        info["State"],
        info["ZipCode"]
    );

    BankAccount check = BankAccount(
        checking["Balance"],
        checking["TransactionLimit"],
        0, // TransactionTotal
        checking["Transactions"]
    );

    BankAccount save = BankAccount(
        savings["Balance"],
        savings["TransactionLimit"],
        0, // TransactionTotal
        savings["Transactions"]
    );

    setCustomer(c);
    setChecking(check);
    setSavings(save);
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

/**
 * Transfers money between checking and savings accounts.
 * @param sending Char that represents where the money is sent from.
 * @param receiving Char that represent where the money is sent to.
 */
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

/**
 * Gets checking account.
 */
BankAccount UserAccounts::getChecking() {
    return this->checking;
}

/**
 * Sets checking account
 */
void UserAccounts::setChecking(BankAccount check) {
    this->checking = check;
}

/**
 * Gets savings account.
 */
BankAccount UserAccounts::getSavings() {
    return this->savings;
}

/**
 * Sets savings account.
 */
void UserAccounts::setSavings(BankAccount save) {
    this->savings = save;
}

/**
 * Prints statement if transaction limit is exceeeded.
 * (Private function)
 */
void UserAccounts::printLimitExceeded() {
    cout << "Transaction Limit was exceeded with this purchase.";
    cout << " Transaction will not be processed." << endl;
}

/**
 * Gets JSON file for program.
 */
json UserAccounts::getJson() {
    fstream file("RozemicBanking/json/accounts.json", fstream::in);
    json j;
    if(file) {
        file >> j;
    }

    file.close();
    return j;
}

/**
 * Sets JSON file for program. Params are account data.
 * @param jFile Default is NULL. Leave blank if JSON file does
 * not exist.
 */
json UserAccounts::setJson(
    double c_balance, double c_total, 
    double c_limit, vector<string> c_transactions,
    double s_balance, double s_total,
    double s_limit, vector<string> s_transactions,
    string password, string firstname, string lastname, 
    string address, string city, 
    string state, string zipcode,
    json jFile) 
    {

    hash<string> str_hash;

    if(jFile == NULL) {
        json temp = {
            { "Users", {
                { uuid::generate_uuid(), {
                    { "Accounts", {
                        { "Checking", {
                            { "Balance", c_balance },
                            { "TransactionTotal", c_total },
                            { "TransactionLimit", c_limit },
                            { "Transactions", c_transactions }
                        }},
                        { "Savings", {
                            { "Balance", s_balance },
                            { "TransactionTotal", s_total },
                            { "TransactionLimit", s_limit },
                            { "Transactions", s_transactions }
                        }},
                    }},
                    { "CustomerInfo", {
                        { "Password", to_string(str_hash(password))},
                        { "FirstName", firstname },
                        { "LastName", lastname },
                        { "Address", address },
                        { "City", city },
                        { "State", state },
                        { "ZipCode", zipcode }
                    }}
                }}
            }}
        };

        jFile = temp;

        
    } else {
        json temp = {
            { "Accounts", {
                { "Checking", {
                    { "Balance", c_balance },
                    { "TransactionTotal", c_total },
                    { "TransactionLimit", c_limit },
                    { "Transactions", c_transactions }
                }},
                { "Savings", {
                    { "Balance", s_balance },
                    { "TransactionTotal", s_total },
                    { "TransactionLimit", s_limit },
                    { "Transactions", s_transactions }
                }},
            }},
            { "CustomerInfo", {
                { "Password", to_string(str_hash(password))},
                { "FirstName", firstname },
                { "LastName", lastname },
                { "Address", address },
                { "City", city },
                { "State", state },
                { "ZipCode", zipcode }
            }}
        };

        jFile["Users"][uuid::generate_uuid()] = temp;
    }

    fstream file("RozemicBanking/json/accounts.json", 
        fstream::in | fstream::out | fstream::trunc);
    if(file) {
        file << setw(4) << jFile;
    }
    file.close();

    return jFile;
}

void UserAccounts::setJson(json obj) {
    fstream file;
    file.open("../json/accounts.json", fstream::out | fstream::trunc);
    file << obj;
    file.close();
}