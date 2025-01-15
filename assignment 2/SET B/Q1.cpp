#include <iostream>
#include <iomanip>   // For formatting output
#include <string>
using namespace std;

class Department {
private:
    int Dept_Id;
    string Dept_Name;
    int Establishment_Year;
    int No_of_Faculty;
    int No_of_Students;

public:
    // Function to accept department details
    void acceptDetails() {
        cout << "Enter Department ID: ";
        cin >> Dept_Id;
        cin.ignore();  // Clear the input buffer

        cout << "Enter Department Name: ";
        getline(cin, Dept_Name);

        cout << "Enter Establishment Year: ";
        cin >> Establishment_Year;

        cout << "Enter Number of Faculty Members: ";
        cin >> No_of_Faculty;

        cout << "Enter Number of Students: ";
        cin >> No_of_Students;
    }

    // Function to display department details
    void displayDetails() const {
        cout << setw(10) << Dept_Id
             << setw(20) << Dept_Name
             << setw(15) << Establishment_Year
             << setw(15) << No_of_Faculty
             << setw(15) << No_of_Students << endl;
    }

    // Getter for Department Name
    string getDeptName() const {
        return Dept_Name;
    }

    // Getter for Establishment Year
    int getEstablishmentYear() const {
        return Establishment_Year;
    }
};

int main() {
    int n, choice, year;
    string searchName;

    cout << "Enter the number of departments: ";
    cin >> n;

    Department* departments = new Department[n];  // Dynamic array

    do {
        cout << "\n--- Department Management Menu ---\n";
        cout << "1. Accept Department Details\n";
        cout << "2. Display Department Details by Name\n";
        cout << "3. Display Departments by Establishment Year\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter details for Department " << i + 1 << ":\n";
                    departments[i].acceptDetails();
                }
                break;

            case 2:
                cout << "\nEnter Department Name to Search: ";
                cin.ignore();
                getline(cin, searchName);

                cout << "\nDepartment Details:\n";
                cout << setw(10) << "Dept ID"
                     << setw(20) << "Dept Name"
                     << setw(15) << "Est. Year"
                     << setw(15) << "Faculty"
                     << setw(15) << "Students" << endl;
                cout << "---------------------------------------------------------------\n";

                for (int i = 0; i < n; i++) {
                    if (departments[i].getDeptName() == searchName) {
                        departments[i].displayDetails();
                    }
                }
                break;

            case 3:
                cout << "\nEnter Establishment Year to Search: ";
                cin >> year;

                cout << "\nDepartments Established in " << year << ":\n";
                cout << setw(10) << "Dept ID"
                     << setw(20) << "Dept Name"
                     << setw(15) << "Est. Year"
                     << setw(15) << "Faculty"
                     << setw(15) << "Students" << endl;
                cout << "---------------------------------------------------------------\n";

                for (int i = 0; i < n; i++) {
                    if (departments[i].getEstablishmentYear() == year) {
                        departments[i].displayDetails();
                    }
                }
                break;

            case 4:
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    delete[] departments;  // Free dynamically allocated memory
    return 0;
}
