#include <iostream>
#include <vector>
using namespace std;

// Base Class: Person (Virtual Base Class)
class Person {
protected:
    int P_Code;
    string P_Name;
public:
    Person(int code, string name) : P_Code(code), P_Name(name) {}
    virtual void display() {
        cout << "P_Code: " << P_Code << " | Name: " << P_Name;
    }
};

// Derived Class: Account (Virtual Base Class)
class Account : virtual public Person {
protected:
    int Ac_No;
    double Balance;
public:
    Account(int code, string name, int accNo, double bal) : Person(code, name), Ac_No(accNo), Balance(bal) {}
};

// Derived Class: Official (Virtual Base Class)
class Official : virtual public Person {
protected:
    string Designation;
    int Experience;
public:
    Official(int code, string name, string desig, int exp) : Person(code, name), Designation(desig), Experience(exp) {}
};

// Derived Class: Employee (Inherits Account & Official)
class Employee : public Account, public Official {
public:
    Employee(int code, string name, int accNo, double bal, string desig, int exp)
        : Person(code, name), Account(code, name, accNo, bal), Official(code, name, desig, exp) {}

    void display() override {
        Person::display();
        cout << " | Ac_No: " << Ac_No << " | Balance: " << Balance
             << " | Designation: " << Designation << " | Experience: " << Experience << " years\n";
    }

    bool isHOD() { return Designation == "H.O.D"; }
};

// Main Function
int main() {
    int n, code, accNo, exp;
    double balance;
    string name, desig;
    
    cout << "Enter number of employees: ";
    cin >> n;

    vector<Employee> employees;

    // Taking employee details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter P_Code, Name: ";
        cin >> code >> ws;
        getline(cin, name);

        cout << "Enter Ac_No, Balance: ";
        cin >> accNo >> balance;

        cout << "Enter Designation, Experience (years): ";
        cin >> ws;
        getline(cin, desig);
        cin >> exp;

        employees.emplace_back(code, name, accNo, balance, desig, exp);
    }

    // Displaying all employees
    cout << "\nEmployee Master Table:\n";
    for (auto& emp : employees) {
        emp.display();
    }

    // Displaying H.O.D Employees
    cout << "\nH.O.D Employees:\n";
    for (auto& emp : employees) {
        if (emp.isHOD()) emp.display();
    }

    return 0;
}
