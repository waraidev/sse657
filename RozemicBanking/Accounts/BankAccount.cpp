#include "Access.h"

using namespace std;

double BankAccount::transactionLimit = 0;

BankAccount::BankAccount() {
    this->balance = 0;
    this->transactionTotal = 0;
}

BankAccount::BankAccount(double initialBalance) {
    this->balance = initialBalance;
    this->transactionTotal = 0;
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

    time_t now = time(0);
    char* dt = ctime(&now);

    addTransaction("Deposited $" + to_string(amount) + " at " + dt);
    addToTransactionTotal(amount);
}

/**
 * Withdraws money into the user's account.
 * @param amount The amount to withdraw.
 */
void BankAccount::withdraw(double amount) {
    this->balance -= amount;

    time_t now = time(0);
    char* dt = ctime(&now);

    addTransaction("Withdrew $" + to_string(amount) + " at " + dt);
    addToTransactionTotal(amount);
}

vector<string> BankAccount::getTransactions() {
    return this->transactionList;
}

void BankAccount::addTransaction(string transaction) {
    this->transactionList.push_back(transaction);
}

/**
 * Sets the limit of daily transactions
 * @param limit The limit amount.
 */
void BankAccount::setTransactionLimit(double limit) {
    transactionLimit = limit;
}

/**
 * Checks if daily transactions have exceeded transactionLimit
 * @param amount The transaction amount.
 */
bool BankAccount::checkLimit(double amount) {
    return (transactionTotal + amount) <= this->transactionLimit;
}

/**
 * Adds money amount to transactionTotal
 */
void BankAccount::addToTransactionTotal(double amount) {
    this->transactionTotal += amount;
}