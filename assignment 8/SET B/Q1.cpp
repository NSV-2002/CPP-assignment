#include <iostream>
using namespace std;

// Abstract Base Class: Student
class Student {
protected:
    string name;
    int rollNo;
public:
    Student(string n, int r) : name(n), rollNo(r) {}
    virtual void display() = 0; // Pure virtual function (Abstract Class)
    virtual ~Student() {} // Virtual destructor
};

// Derived Class: Engineering
class Engineering : public Student {
public:
    Engineering(string n, int r) : Student(n, r) {}
    void display() override {
        cout << "Engineering Student | Roll No: " << rollNo << " | Name: " << name << endl;
    }
};

// Derived Class: Medicine
class Medicine : public Student {
public:
    Medicine(string n, int r) : Student(n, r) {}
    void display() override {
        cout << "Medicine Student | Roll No: " << rollNo << " | Name: " << name << endl;
    }
};

// Derived Class: Science
class Science : public Student {
public:
    Science(string n, int r) : Student(n, r) {}
    void display() override {
        cout << "Science Student | Roll No: " << rollNo << " | Name: " << name << endl;
    }
};

// Main Function
int main() {
    int n, roll;
    string name, course;
    
    cout << "Enter number of students: ";
    cin >> n;
    
    Student* students[n]; // Array of base class pointers

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Roll No & Name: ";
        cin >> roll >> ws;
        getline(cin, name);
        
        cout << "Enter Course (Engineering/Medicine/Science): ";
        cin >> course;

        if (course == "Engineering") 
            students[i] = new Engineering(name, roll);
        else if (course == "Medicine") 
            students[i] = new Medicine(name, roll);
        else 
            students[i] = new Science(name, roll);
    }

    // Displaying student details
    cout << "\nStudent Details:\n";
    for (int i = 0; i < n; i++) {
        students[i]->display();
        delete students[i]; // Free memory
    }

    return 0;
}
