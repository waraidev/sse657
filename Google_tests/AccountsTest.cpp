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
    EXPECT_EQ(userAccount->getChecking().getBalance(), 90);
}

TEST_F(BankAccountFixture, TransactionLimitTest) {

    userAccount->getChecking().setTransactionLimit(50);
    EXPECT_TRUE(userAccount->getChecking().checkLimit(49));
    EXPECT_TRUE(userAccount->getChecking().checkLimit(50));
    EXPECT_FALSE(userAccount->getChecking().checkLimit(51));

}

//TEST(BankAccountTest, ExampleBalance){
//    BankAccount bankAccount;
//    bankAccount.deposit(90);
//    EXPECT_EQ(bankAccount.getBalance(), 90);
//}