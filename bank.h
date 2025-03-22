#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include <mutex>
#include "BankAccount.h"

using namespace std;

class Bank {
private:
    vector<BankAccount> accounts;
    mutex mtx;

public:
    void addAccount(int accNum, string holder, double bal);
    BankAccount* findAccount(int accNum);
    void processTransactions();
    void loadTransactionHistory();
};

#endif

