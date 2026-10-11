// Topic 8: Classes Basics
// A class bundles data (members) with the functions that work on it (methods).
// Private data is protected: outside code must use the public methods.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o classes_basics 08_classes_basics.cpp
// Run:     ./classes_basics

#include <iostream>
#include <string>

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    // Constructor: runs when an object is created.
    BankAccount(const std::string& ownerName, double startingBalance) {
        owner = ownerName;
        balance = startingBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Returns true if the withdrawal worked.
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Getters: let outside code read private data.
    double getBalance() const {
        return balance;
    }

    void print() const {
        std::cout << owner << " has " << balance << " naira\n";
    }
};

int main() {
    BankAccount account("Ada", 5000);
    account.print();

    account.deposit(2500);
    account.print();

    if (account.withdraw(1000)) {
        std::cout << "Withdrew 1000\n";
    }
    account.print();

    // This fails because there is not enough money.
    if (!account.withdraw(100000)) {
        std::cout << "Withdrawal of 100000 refused\n";
    }

    // account.balance = 1000000;       // ERROR: balance is private

    std::cout << "Final balance: " << account.getBalance() << '\n';

    // --- Two objects are independent of each other ---
    BankAccount other("Bola", 300);
    other.print();
    account.print();

    return 0;
}
