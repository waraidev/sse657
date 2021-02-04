//
// Created by User on 2/1/2021.
//

#include "UserAccount.h"

using namespace std;

/** Constructs a user account with a balance of zero. */
UserAccount::UserAccount() {
    this->checkingBalance = 0;
    this->savingsBalance = 0;
}

/**
 * Constructs a user account with a given balance.
 * @param initialBalance The initial balance.
 */
UserAccount::UserAccount(double initialBalance) {
    this->checkingBalance = initialBalance;
    this->savingsBalance = 0;
}

/**
 * Gets the CustomerInfo object associated
 * with the UserAccount
 */
CustomerInfo UserAccount::getCustomer() {
    return this->customer;
}

/**
 * Gets the CustomerInfo object associated
 * with the UserAccount
 */
CustomerInfo UserAccount::setCustomer(CustomerInfo c) {
    this->customer = c;
    return c;
}

/**
 * Deposits money into the user's checking or savings account.
 * @param amount The amount to deposit.
 */
void UserAccount::deposit(double amount, bool isSavings) {
    if(isSavings) {
        double currSavings = this->savingsBalance;
        this->savingsBalance += amount;
        cout << "Your new savings balance is (";
        cout << currSavings;
        cout << " + ";
        cout << amount;
        cout << "): $";
        cout << this->savingsBalance << endl;
    } else {
        double currChecking = this->checkingBalance;
        this->checkingBalance += amount;
        cout << "Your new checking balance is (";
        cout << currChecking;
        cout << " + ";
        cout << amount;
        cout << "): $";
        cout << this->checkingBalance << endl;
    }
}

/**
 * Withdraws money into the user's checking account.
 * @param amount The amount to withdraw.
 */
void UserAccount::withdraw(double amount) {
    double current = this->checkingBalance;
    this->checkingBalance -= amount;
    cout << "Your new checking balance is (";
    cout << current;
    cout << " - ";
    cout << amount;
    cout << "): $";
    cout << this->checkingBalance << endl;
}

void UserAccount::transfer(char sending, char receiving, double amount) {
    if(sending == 'C' && receiving == 'S') {
        this->checkingBalance -= amount;
        this->savingsBalance += amount;
    } else if(sending == 'S' && receiving == 'C') {
        this->savingsBalance -= amount;
        this->checkingBalance += amount;
    } else {
        cout << "Error in input: No funds were transferred." << endl;
    }

    cout << "Your checking balance is $" << this->checkingBalance << endl;
    cout << "Your savings balance is $" << this->savingsBalance << endl; 
}

/**
 * Gets the current balance of the bank account.
 * @return The current balance.
 */
double UserAccount::getBalance(bool isSavings) {
    if(isSavings) {
        return this->savingsBalance;
    }
    
    return this->checkingBalance;
}