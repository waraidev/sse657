#include "Access.h"
#include <sstream>

using namespace std;

namespace stdplus {
    std::string to_string(double d) {
        ostringstream s;
        s << setprecision(numeric_limits<double>::digits10) << d;
        return s.str();
    }
}

double BankAccount::transactionLimit = 0;

BankAccount::BankAccount() {
    this->balance = 0;
    this->transactionTotal = 0;
}

BankAccount::BankAccount(double initialBalance) {
    this->balance = initialBalance;
    this->transactionTotal = 0;
}

BankAccount::BankAccount(double balance, double transactionLimit,
            double transactionTotal, std::vector<std::string> transactions) 
{
    this->balance = balance;
    this->transactionLimit = transactionLimit;
    this->transactionTotal = transactionTotal;
    this->transactionList = transactions;
}

/**
 * Gets the current balance of the bank account.
 * @return The current balance.
 */
double BankAccount::getBalance() {
    return this->balance;
}

double BankAccount::getTransactionTotal() {
    return this->transactionTotal;
}

/**
 * Deposits money into the user's account.
 * @param amount The amount to deposit.
 */
void BankAccount::deposit(double amount) {
    this->balance += amount;

    time_t now = time(0);
    char* dt = ctime(&now);

    addTransaction("Deposited $" + stdplus::to_string(amount) + " at " + dt);
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



    addTransaction("Withdrew $" + stdplus::to_string(amount) + " at " + dt);
    addToTransactionTotal(amount);
}

vector<string> BankAccount::getTransactions() {
    return this->transactionList;
}

void BankAccount::addTransaction(string transaction) {
    this->transactionList.push_back(transaction);
}

double BankAccount::getTransactionLimit() {
    return this->transactionLimit;
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