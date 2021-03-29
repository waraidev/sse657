#include <string>
#include <array>
#include <functional>
#include "Accounts/Access.h"

using namespace std;
using json = nlohmann::json;

// Declarations

bool businessAccount();

void submitTransaction(UserAccounts *accounts);

// Implementations

/**
 * Returns whether a business or personal account is being used.
 * The function uses user input via the command line.
 */
bool businessAccount() {
    char choice;

    cout << "Are you a business or Rozemic Banking user?" << endl;
    cout << "Choose 'B' for business and 'R' for Rozemic Banking" << endl;
    cout << "Choice: ";

    cin >> choice;

    switch(toupper(choice)) {
        case 'B':
            return true;
        case 'R':
            return false;
        default:
            cout << "Error: Invalid choice.";
            cout << "Thank you for choosing Rozemic Banking!" << endl;
            exit(1); 
    }
}

/**
 * Submits transactions from a business to the bank user via 
 * the account ID.
 */
void submitTransaction(UserAccounts *accounts) {
    string company;
    string description;
    double amount;

    cout << "What is the name of your company? -> ";
    cin.ignore(20, '\n');
    getline(cin, company);
    cout << "\n";

    cout << "Describe the product that was purchased:" << endl;
    cin.sync();
    getline(cin, description);
    cout << "\n";

    cout << "What was the price of the purchased product?" << endl;
    cin >> amount;
    cout << "\n";

    if(isnan(amount)) {
        cout << "The amount entered is invalid!" << endl;
        return;
    }

    accounts->withdraw(amount, description, company);

    cout << "Purchase amount has been withdrawn! Have a great day!" << endl;
}