#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <mutex>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    double balance;
    mutex mtx;

public:
    BankAccount(int accNum, string holder, double bal);
    BankAccount(const BankAccount&) = delete;
    BankAccount& operator=(const BankAccount&) = delete;
    BankAccount(BankAccount&& other) noexcept;

    int getAccountNumber() const;
    double getBalance() const;
    void deposit(double amount);
    bool withdraw(double amount);
    bool transfer(BankAccount& receiver, double amount);
    void logTransaction(const string& type, double amount, int receiver = -1);
    void printAccountDetails() const;
};

#endif
