#include <iostream>
using namespace std;

// Base Class: Student (Virtual Base Class)
class Student {
protected:
    int Roll_No;
    string Name, Class_Name;
public:
    Student(int roll, string name, string cls) : Roll_No(roll), Name(name), Class_Name(cls) {}
    virtual void display() {
        cout << "Roll No: " << Roll_No << " | Name: " << Name << " | Class: " << Class_Name << endl;
    }
};

// Derived Class: Internal_Marks (Virtual Base Class)
class Internal_Marks : virtual public Student {
protected:
    int IntM[5]; // Internal Marks for 5 subjects
public:
    Internal_Marks(int roll, string name, string cls, int marks[])
        : Student(roll, name, cls) {
        for (int i = 0; i < 5; i++) IntM[i] = marks[i];
    }
};

// Derived Class: External_Marks (Virtual Base Class)
class External_Marks : virtual public Student {
protected:
    int ExtM[5]; // External Marks for 5 subjects
public:
    External_Marks(int roll, string name, string cls, int intMarks[], int extMarks[])
        : Student(roll, name, cls), Internal_Marks(roll, name, cls, intMarks) {
        for (int i = 0; i < 5; i++) ExtM[i] = extMarks[i];
    }
};

// Derived Class: Result (Inherits from Internal_Marks & External_Marks)
class Result : public Internal_Marks, public External_Marks {
    int Total[5]; // Total marks for 5 subjects
public:
    Result(int roll, string name, string cls, int intMarks[], int extMarks[])
        : Student(roll, name, cls), Internal_Marks(roll, name, cls, intMarks), External_Marks(roll, name, cls, intMarks, extMarks) {
        for (int i = 0; i < 5; i++) Total[i] = IntM[i] + ExtM[i];
    }

    void displayResult() {
        display(); // Display Student Details
        cout << "----------------------------------------\n";
        cout << "Sub  | Internal | External | Total | Status\n";
        cout << "----------------------------------------\n";
        for (int i = 0; i < 5; i++) {
            cout << " " << i + 1 << "   |   " << IntM[i] << "    |   " << ExtM[i] 
                 << "    |  " << Total[i] << "  | ";
            if (IntM[i] >= 20 && ExtM[i] >= 20 && Total[i] >= 40)
                cout << "PASS\n";
            else
                cout << "FAIL\n";
        }
        cout << "----------------------------------------\n";
    }
};

// Main Function
int main() {
    int n, roll, intMarks[5], extMarks[5];
    string name, cls;
    
    cout << "Enter number of students: ";
    cin >> n;
    
    Result* students[n];

    // Input student details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter Roll No, Name, Class: ";
        cin >> roll >> ws;
        getline(cin, name);
        getline(cin, cls);
        
        cout << "Enter 5 Internal Marks: ";
        for (int &mark : intMarks) cin >> mark;
        
        cout << "Enter 5 External Marks: ";
        for (int &mark : extMarks) cin >> mark;

        students[i] = new Result(roll, name, cls, intMarks, extMarks);
    }

    // Display Results
    cout << "\nStudent Results:\n";
    for (int i = 0; i < n; i++) {
        students[i]->displayResult();
        delete students[i]; // Free memory
    }

    return 0;
}
