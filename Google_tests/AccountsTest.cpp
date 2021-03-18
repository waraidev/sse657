//
// Created by User on 3/12/2021.
//

#include "gtest/gtest.h"
#include "../RozemicBanking/Accounts/Access.h"
#include "../RozemicBanking/Accounts/BankAccount.cpp"
#include "../RozemicBanking/Accounts/CustomerInfo.cpp"
#include "../RozemicBanking/Accounts/UserAccounts.cpp"
#include "../RozemicBanking/HelperFunctions.cpp"


class BankAccountFixture : public ::testing::Test {
protected:

    virtual void SetUp() {
        userAccount = new UserAccounts();
        bankAccount = new BankAccount();

        bankAccount->deposit(90);
        initAccounts(userAccount, 90);
        bankAccount->setTransactionLimit(50);
    }

    virtual void TearDown() {
        delete userAccount;
        delete bankAccount;
    }

    UserAccounts *userAccount;
    BankAccount *bankAccount;
};

TEST_F(BankAccountFixture, BankBalanceTest) {
    EXPECT_EQ(bankAccount->getBalance(), 90);
    EXPECT_EQ(checkingBalance(userAccount), 90);
}

TEST_F(BankAccountFixture, TransactionLimitTest) {

    EXPECT_TRUE(userAccount->getChecking().checkLimit(49));
    EXPECT_TRUE(userAccount->getChecking().checkLimit(50));
    EXPECT_FALSE(userAccount->getChecking().checkLimit(51));
}

TEST_F(BankAccountFixture, WithdrawTest) {
    userAccount->withdraw(49);
    EXPECT_EQ(checkingBalance(userAccount), 41);

    // Transaction limit exceeded; no money gets withdrawn
    userAccount->withdraw(2);
    EXPECT_EQ(checkingBalance(userAccount), 41);
}

TEST_F(BankAccountFixture, TransferTest) {
    // Transfer from checking to savings
    userAccount->transfer('C', 'S', 40);
    EXPECT_EQ(checkingBalance(userAccount), 50);
    EXPECT_EQ(savingsBalance(userAccount), 40);

    // Transaction limit exceeded; no money gets transferred
    userAccount->transfer('S', 'C', 20);
    EXPECT_EQ(checkingBalance(userAccount), 50);
    EXPECT_EQ(savingsBalance(userAccount), 40);

    // Error message since you can't transfer to the same account; no money gets transferred
    userAccount->transfer('S', 'S', 5);
    EXPECT_EQ(checkingBalance(userAccount), 50);
    EXPECT_EQ(savingsBalance(userAccount), 40);

    // Transfer from savings to checking
    userAccount->transfer('S', 'C', 10);
    EXPECT_EQ(checkingBalance(userAccount), 60);
    EXPECT_EQ(savingsBalance(userAccount), 30);
}

