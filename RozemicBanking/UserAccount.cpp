//
// Created by User on 2/1/2021.
//

#include "UserAccount.h"


/**
 * Constructs a user account with a given balance.
 * @param initialBalance The initial balance.
 */
UserAccount::UserAccount(double initialBalance) {
    balance = initialBalance;
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