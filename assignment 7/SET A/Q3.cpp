#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

// Base Classes
class Employee {
protected:
    string Name, Designation;
public:
    Employee(string name, string designation) : Name(name), Designation(designation) {}
};

class Project {
protected:
    int Project_Id;
    string Title;
public:
    Project(int id, string title) : Project_Id(id), Title(title) {}
};

// Derived Class using Multiple Inheritance
class Emp_Proj : public Employee, public Project {
public:
    int Duration;
    Emp_Proj(string name, string designation, int id, string title, int duration)
        : Employee(name, designation), Project(id, title), Duration(duration) {}

    void display() const {
        cout << left << setw(15) << Name << setw(15) << Designation
             << setw(10) << Project_Id << setw(20) << Title
             << setw(10) << Duration << " months" << endl;
    }
};

void displayProjects(const vector<Emp_Proj>& records, bool sortByDuration = false) {
    if (records.empty()) {
        cout << "No records available.\n"; return;
    }
    
    vector<Emp_Proj> sortedRecords = records;
    if (sortByDuration)
        sort(sortedRecords.begin(), sortedRecords.end(), [](const Emp_Proj& a, const Emp_Proj& b) {
            return a.Duration < b.Duration;
        });

    cout << left << setw(15) << "Name" << setw(15) << "Designation"
         << setw(10) << "Proj_ID" << setw(20) << "Title" << setw(10) << "Duration" << "\n";
    cout << string(70, '-') << endl;

    for (const auto& record : sortedRecords) record.display();
}

int main() {
    vector<Emp_Proj> records;
    int choice;

    do {
        cout << "\n1. Add Employee & Project\n2. Display Master Table\n3. Display Projects Sorted by Duration\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            string name, designation, title;
            int id, duration;
            cout << "Enter Name, Designation, Project ID, Title, Duration: ";
            cin.ignore();
            getline(cin, name);
            getline(cin, designation);
            cin >> id;
            cin.ignore();
            getline(cin, title);
            cin >> duration;

            records.emplace_back(name, designation, id, title, duration);
            cout << "Record added!\n";
        } 
        else if (choice == 2) displayProjects(records);
        else if (choice == 3) displayProjects(records, true);
        else if (choice != 4) cout << "Invalid choice!\n";
        
    } while (choice != 4);

    return 0;
}
