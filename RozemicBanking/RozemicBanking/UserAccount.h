//
// Created by User on 2/1/2021.
//

#ifndef SSE657_USERACCOUNT_H
#define SSE657_USERACCOUNT_H


using namespace std;

/** A user account that has a balance that can be changed by deposits and withdrawals. */
class UserAccount {

private:
    double balance;

public:
    UserAccount();

    UserAccount(double initialBalance);

    void deposit(double amount);

    void withdraw(double amount);

    double getBalance();

};

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

#endif //SSE657_USERACCOUNT_H
