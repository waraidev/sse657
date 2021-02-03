//
// Created by User on 2/1/2021.
//

#ifndef SSE657_USERACCOUNT_H
#define SSE657_USERACCOUNT_H

#include "CustomerInfo.h"

/** A user account that has a balance that can be changed by deposits and withdrawals. */
class UserAccount {

private:
    double balance;

    CustomerInfo customer;

public:
    UserAccount();

    UserAccount(double initialBalance);

    void deposit(double amount);

    void withdraw(double amount);

    double getBalance();

    CustomerInfo getCustomer();

    CustomerInfo setCustomer(CustomerInfo c);

};

#endif //SSE657_USERACCOUNT_H
