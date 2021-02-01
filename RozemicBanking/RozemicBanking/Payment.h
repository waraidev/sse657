//
// Created by User on 1/29/2021.
//

#ifndef SSE657_PAYMENT_H
#define SSE657_PAYMENT_H

#include <string>

using namespace std;

class Payment {

public:
    /** The amount of money to be paid. */
    double amount;
    /** The account number of the person purchasing the item. */
    string purchaserId;
    /** The account number of the person selling the item. */
    string sellerId;

    Payment(double amount, string purchaserId, string sellerId);
private:

};


#endif //SSE657_PAYMENT_H
