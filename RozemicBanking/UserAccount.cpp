//
// Created by User on 2/1/2021.
//

#include "UserAccount.h"

using namespace std;

/** Constructs a user account with a balance of zero. */
UserAccount::UserAccount() {
    balance = 0;
}

/**
 * Constructs a user account with a given balance.
 * @param initialBalance The initial balance.
 */
UserAccount::UserAccount(double initialBalance) {
    balance = initialBalance;
}

/**
 * Gets the CustomerInfo object associated
 * with the UserAccount
 */
CustomerInfo UserAccount::getCustomer() {
    return customer;
}

/**
 * Gets the CustomerInfo object associated
 * with the UserAccount
 */
CustomerInfo UserAccount::setCustomer(CustomerInfo c) {
    customer = c;
    return customer;
}

/**
 * Deposits money into the user's account.
 * @param amount The amount to deposit.
 */
void UserAccount::deposit(double amount) {
    balance = balance + amount;
}

/**
 * Withdraws money into the bank account.
 * @param amount The amount to withdraw.
 */
void UserAccount::withdraw(double amount) {
    balance = balance - amount;
}

/**
 * Gets the current balance of the bank account.
 * @return The current balance.
 */
double UserAccount::getBalance() {
    return balance;
}