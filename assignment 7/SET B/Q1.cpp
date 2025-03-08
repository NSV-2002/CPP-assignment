#include <iostream>
using namespace std;

// Base Class: Account
class Account {
protected:
    string name, contact;
    double balance;
public:
    Account(string n, string c, double b) : name(n), contact(c), balance(b) {}
    virtual void deposit(double amt) { balance += amt; }
    virtual void withdraw(double amt) {
        if (balance >= amt) balance -= amt;
        else cout << "Insufficient balance!\n";
    }
    virtual void applyCharges() = 0;
    virtual void display() const = 0;
};

// Derived Class: Saving_Account
class Saving_Account : public Account {
    const double minBal = 2000, charge = 500, interest = 0.10;
public:
    Saving_Account(string n, string c, double b) : Account(n, c, b) {}
    void applyCharges() override {
        balance += balance * interest;
        if (balance < minBal) balance -= charge;
    }
    void display() const override {
        cout << "Savings | Name: " << name << " | Balance: ₹" << balance << endl;
    }
};

// Derived Class: Current_Account
class Current_Account : public Account {
    const double minBal = 5000, charge = 1000;
public:
    Current_Account(string n, string c, double b) : Account(n, c, b) {}
    void applyCharges() override {
        if (balance < minBal) balance -= charge;
    }
    void display() const override {
        cout << "Current | Name: " << name << " | Balance: ₹" << balance << endl;
    }
};

// Main Function
int main() {
    Account* acc;
    int type, choice;
    string name, contact;
    double balance, amt;

    cout << "1. Savings Account  2. Current Account\nChoose: ";
    cin >> type;
    cout << "Enter Name, Contact, Initial Balance: ";
    cin >> name >> contact >> balance;
    acc = (type == 1) ? new Saving_Account(name, contact, balance) : new Current_Account(name, contact, balance);

    do {
        cout << "\n1. Deposit  2. Withdraw  3. Apply Charges  4. Display  5. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) { cout << "Amount: "; cin >> amt; acc->deposit(amt); }
        else if (choice == 2) { cout << "Amount: "; cin >> amt; acc->withdraw(amt); }
        else if (choice == 3) acc->applyCharges();
        else if (choice == 4) acc->display();
    } while (choice != 5);

    delete acc;
    return 0;
}
