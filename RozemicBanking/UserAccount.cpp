//
// Created by User on 2/1/2021.
//

#include "UserAccount.h"

using namespace std;

/** Constructs a user account with a balance of zero. */
UserAccount::UserAccount() {
    this->balance = 0;
}

/**
 * Constructs a user account with a given balance.
 * @param initialBalance The initial balance.
 */
UserAccount::UserAccount(double initialBalance) {
    this->balance = initialBalance;
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
 * Deposits money into the user's account.
 * @param amount The amount to deposit.
 */
void UserAccount::deposit(double amount) {
    this->balance += amount;
}

/**
 * Withdraws money into the bank account.
 * @param amount The amount to withdraw.
 */
void UserAccount::withdraw(double amount) {
    this->balance -= amount;
}

/**
 * Gets the current balance of the bank account.
 * @return The current balance.
 */
double UserAccount::getBalance() {
    return this->balance;
}