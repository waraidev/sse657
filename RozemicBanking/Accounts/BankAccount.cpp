#include "Access.h"

using namespace std;

BankAccount::BankAccount() {
    this->balance = 0;
}

BankAccount::BankAccount(double initialBalance) {
    this->balance = initialBalance;
}

/**
 * Gets the current balance of the bank account.
 * @return The current balance.
 */
double BankAccount::getBalance() {
    return this->balance;
}

/**
 * Deposits money into the user's account.
 * @param amount The amount to deposit.
 */
void BankAccount::deposit(double amount) {
    this->balance += amount;
}

/**
 * Withdraws money into the user's account.
 * @param amount The amount to withdraw.
 */
void BankAccount::withdraw(double amount) {
    this->balance -= amount;
}

vector<string> BankAccount::getTransactions() {
    return this->transactionList;
}

vector<string> BankAccount::addTransaction(string transaction) {
    this->transactionList.push_back(transaction);
    
    return this->transactionList;
}