#include <iostream>
#include "Bank.h"

using namespace std;

int main() {
    Bank bank;

    int numAccounts;
    cout << "Enter the number of accounts: ";
    cin >> numAccounts;

    for (int i = 0; i < numAccounts; ++i) {
        int accNum;
        string name;
        double balance;

        cout << "Enter the account number: ";
        cin >> accNum;
        cin.ignore();
        cout << "Enter the account holder's name: ";
        getline(cin, name);
        cout << "Enter the balance: ";
        cin >> balance;

        bank.addAccount(accNum, name, balance);
    }

    bank.processTransactions();
    bank.loadTransactionHistory();

    return 0;
}
