//
// Created by User on 1/29/2021.
//

#include "Payment.h"

Payment::Payment(double amount, string purchaserId, string sellerId) {
    this->amount = amount;
    this->purchaserId = purchaserId;
    this->sellerId = sellerId;
}