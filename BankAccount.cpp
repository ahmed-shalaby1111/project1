#include "BankAccount.h"
#include <iostream>
#include <fstream>

using namespace std;


BankAccount::BankAccount(int accNum, string holder, double bal)
    : accountNumber(accNum), accountHolder(move(holder)), balance(bal) {}


BankAccount::BankAccount(BankAccount&& other) noexcept
    : accountNumber(other.accountNumber),
      accountHolder(move(other.accountHolder)),
      balance(other.balance) {}


int BankAccount::getAccountNumber() const {
    return accountNumber;
}


double BankAccount::getBalance() const {
    return balance;
}


void BankAccount::deposit(double amount) {
    lock_guard<mutex> lock(mtx);
    balance += amount;
    logTransaction("Deposit", amount);
    cout << "Deposited " << amount << " to account " << accountNumber << "\n";
}


bool BankAccount::withdraw(double amount) {
    lock_guard<mutex> lock(mtx);
    if (amount <= balance) {
        balance -= amount;
        logTransaction("Withdraw", amount);
        cout << "Withdrew " << amount << " from account " << accountNumber << "\n";
        return true;
    } else {
        cout << "Insufficient balance in account " << accountNumber << "\n";
        return false;
    }
}


bool BankAccount::transfer(BankAccount& receiver, double amount) {
    lock_guard<mutex> lock(mtx);
    if (withdraw(amount)) {
        receiver.deposit(amount);
        logTransaction("Transfer", amount, receiver.getAccountNumber());
        return true;
    }
    return false;
}


void BankAccount::logTransaction(const string& type, double amount, int receiver) {
    ofstream file("transactions.txt", ios::app);
    if (file.is_open()) {
        file << "Account " << accountNumber << " - " << type
             << ": $" << amount;
        if (receiver != -1) {
            file << " to Account " << receiver;
        }
        file << endl;
    }
}


void BankAccount::printAccountDetails() const {
    cout << "Account Number: " << accountNumber
         << "\nHolder: " << accountHolder
         << "\nBalance: $" << balance << "\n";
}
