#include <iostream>
using namespace std;

// Base Class: Student
class Student {
protected:
    int rollNo;
    string name;
public:
    Student(int r, string n) : rollNo(r), name(n) {}
    virtual void display() {
        cout << "Roll No: " << rollNo << " | Name: " << name;
    }
};

// Derived Class: Theory (Virtual Base Class)
class Theory : virtual public Student {
protected:
    int theoryMarks[5]; // Marks of 5 subjects
public:
    Theory(int r, string n, int m[]) : Student(r, n) {
        for (int i = 0; i < 5; i++) theoryMarks[i] = m[i];
    }
    int totalTheoryMarks() {
        int sum = 0;
        for (int m : theoryMarks) sum += m;
        return sum;
    }
};

// Derived Class: Practical (Virtual Base Class)
class Practical : virtual public Student {
protected:
    int practicalMarks[2]; // Marks of 2 practical subjects
public:
    Practical(int r, string n, int m[]) : Student(r, n) {
        for (int i = 0; i < 2; i++) practicalMarks[i] = m[i];
    }
    int totalPracticalMarks() {
        return practicalMarks[0] + practicalMarks[1];
    }
};

// Derived Class: Result
class Result : public Theory, public Practical {
    int totalMarks;
    string grade;
public:
    Result(int r, string n, int t[], int p[]) : Student(r, n), Theory(r, n, t), Practical(r, n, p) {
        totalMarks = totalTheoryMarks() + totalPracticalMarks();
        grade = (totalMarks >= 400) ? "First Class" : (totalMarks >= 300) ? "Second Class" : "Pass";
    }
    void display() override {
        Student::display();
        cout << " | Total Marks: " << totalMarks << " | Grade: " << grade << endl;
    }
};

// Main Function
int main() {
    int n, theory[5], practical[2], roll;
    string name;
    
    cout << "Enter number of students: ";
    cin >> n;
    
    Result* students[n]; // Array of Result objects

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Roll No & Name: ";
        cin >> roll >> ws;
        getline(cin, name);
        
        cout << "Enter marks for 5 Theory subjects: ";
        for (int &m : theory) cin >> m;

        cout << "Enter marks for 2 Practical subjects: ";
        for (int &m : practical) cin >> m;

        students[i] = new Result(roll, name, theory, practical);
    }

    // Displaying student results
    cout << "\nStudent Results:\n";
    for (int i = 0; i < n; i++) {
        students[i]->display();
        delete students[i]; // Free memory
    }

    return 0;
}

