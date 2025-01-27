#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

class Employee {
private:
    int empNo;
    string name;
    double basicSalary;
    double da;
    double hra;
    double allowances;

public:
    void acceptDetails() {
        cout << "Enter Employee Number: ";
        cin >> empNo;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        cout << "Enter Dearness Allowance (DA): ";
        cin >> da;
        cout << "Enter House Rent Allowance (HRA): ";
        cin >> hra;
        cout << "Enter Other Allowances: ";
        cin >> allowances;
    }

    double calculateGrossSalary() const {
        return basicSalary + da + hra + allowances;
    }

    void generatePaySlip() const {
        cout << "\n----------- PAY SLIP -----------\n";
        cout << left << setw(20) << "Employee No:" << empNo << endl;
        cout << left << setw(20) << "Employee Name:" << name << endl;
        cout << left << setw(20) << "Basic Salary:" << fixed << setprecision(2) << basicSalary << endl;
        cout << left << setw(20) << "Dearness Allowance:" << da << endl;
        cout << left << setw(20) << "House Rent Allowance:" << hra << endl;
        cout << left << setw(20) << "Other Allowances:" << allowances << endl;
        cout << left << setw(20) << "Gross Salary:" << calculateGrossSalary() << endl;
        cout << "--------------------------------\n";
    }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee* employees = new Employee[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Employee " << i + 1 << ":\n";
        employees[i].acceptDetails();
    }

    cout << "\n-------- Employee Pay Slips --------\n";
    for (int i = 0; i < n; i++) {
        employees[i].generatePaySlip();
    }

    delete[] employees;
    return 0;
}
