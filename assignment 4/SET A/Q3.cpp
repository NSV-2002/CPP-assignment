#include <iostream>
using namespace std;

class GPARecords {
private:
    float* gpa;
    int numStudents;

public:
    // Constructor to allocate memory
    GPARecords(int n) {
        numStudents = n;
        gpa = new float[numStudents];
        cout << "Enter GPA for " << numStudents << " students: " << endl;
        for (int i = 0; i < numStudents; i++) {
            cout << "Student " << i + 1 << ": ";
            cin >> gpa[i];
        }
    }

    // Function to display GPAs
    void display() {
        cout << "GPA of students: " << endl;
        for (int i = 0; i < numStudents; i++) {
            cout << "Student " << i + 1 << ": " << gpa[i] << endl;
        }
    }

    // Destructor to deallocate memory
    ~GPARecords() {
        delete[] gpa;
        cout << "Memory deallocated successfully." << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    GPARecords obj(n);
    obj.display();
    return 0;
}