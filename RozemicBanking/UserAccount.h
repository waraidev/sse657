//
// Created by User on 2/1/2021.
//

#ifndef SSE657_USERACCOUNT_H
#define SSE657_USERACCOUNT_H

#include "CustomerInfo.h"

/** A user account that has a balance that can be changed by deposits and withdrawals. */
class UserAccounts {

private:
    double checkingBalance;
    double savingsBalance;

    CustomerInfo customer;

public:
    UserAccounts();

    UserAccounts(double initialBalance);

    void deposit(double amount, bool isSavings);

    void withdraw(double amount);

    void transfer(char sending, char receiving, double amount);

    double getBalance(bool isSavings);

    CustomerInfo getCustomer();

    CustomerInfo setCustomer(CustomerInfo c);

};

#endif //SSE657_USERACCOUNT_H
