#include <iostream>
using namespace std;

class Account;

void transferFunds(Account &from, Account &to, double amount);

class Account {
private:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    friend class Manager;
    friend void transferFunds(Account &from, Account &to, double amount);
};

class Manager {
public:
    void deposit(Account &acc, double amount) {
        if (amount > 0) {
            acc.balance += amount;
            cout << "Deposited $" << amount << " into account " << acc.accountNumber << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(Account &acc, double amount) {
        if (amount <= acc.balance && amount > 0) {
            acc.balance -= amount;
            cout << "Withdrew $" << amount << " from account " << acc.accountNumber << endl;
        } else {
            cout << "Insufficient funds or invalid amount!" << endl;
        }
    }

    void display(const Account &acc) {
        cout << "Account Number: " << acc.accountNumber
             << ", Balance: $" << acc.balance << endl;
    }
};

void transferFunds(Account &from, Account &to, double amount) {
    if (amount > 0 && from.balance >= amount) {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred $" << amount << " from Account " << from.accountNumber
             << " to Account " << to.accountNumber << endl;
    } else {
        cout << "Transfer failed: Insufficient balance or invalid amount." << endl;
    }
}

int main() {
    Account acc1(101, 1000.0);
    Account acc2(102, 500.0);

    Manager mgr;

    cout << "Initial Account States:\n";
    mgr.display(acc1);
    mgr.display(acc2);

    mgr.deposit(acc1, 200.0);
    mgr.withdraw(acc2, 100.0);
    transferFunds(acc1, acc2, 300.0);

    cout << "\nFinal Account States:\n";
    mgr.display(acc1);
    mgr.display(acc2);

    return 0;
}
