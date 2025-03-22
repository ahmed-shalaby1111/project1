#include "Bank.h"
#include <iostream>
#include <fstream>

using namespace std;

void Bank::addAccount(int accNum, string holder, double bal) {
    lock_guard<mutex> lock(mtx);
    accounts.emplace_back(accNum, holder, bal);
}


BankAccount* Bank::findAccount(int accNum) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNum) {
            return &acc;
        }
    }
    return nullptr;
}


void Bank::loadTransactionHistory() {
    ifstream file("transactions.txt");
    if (file.is_open()) {
        cout << "Transaction History:\n";
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No transaction history found.\n";
    }
}
