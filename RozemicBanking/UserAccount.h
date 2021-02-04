//
// Created by User on 2/1/2021.
//

#ifndef SSE657_USERACCOUNT_H
#define SSE657_USERACCOUNT_H

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

#endif //SSE657_USERACCOUNT_H
