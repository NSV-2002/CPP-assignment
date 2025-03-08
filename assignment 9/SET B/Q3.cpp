#include <iostream>
#include <fstream>
using namespace std;

// Structure to store student details
struct Student {
    int rollNo;
    string name;
    float percentage;
};

// Function to write student details to a file
void writeStudentInfo(const string &filename, int n) {
    ofstream outFile(filename, ios::app); // Open file in append mode

    if (!outFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;
    for (int i = 0; i < n; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> student.rollNo;
        cin.ignore(); // Ignore newline left in the buffer
        cout << "Name: ";
        getline(cin, student.name);
        cout << "Percentage: ";
        cin >> student.percentage;

        // Write data to file
        outFile << student.rollNo << " " << student.name << " " << student.percentage << endl;
    }

    outFile.close();
    cout << "Student information written to file successfully!\n";
}

// Function to read and display student details from the file
void readStudentInfo(const string &filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    Student student;
    cout << "\nStudent Information:\n";
    cout << "--------------------------------------\n";
    while (inFile >> student.rollNo) {
        inFile.ignore(); // Ignore space
        getline(inFile, student.name, ' ');
        inFile >> student.percentage;
        cout << "Roll No: " << student.rollNo << ", Name: " << student.name << ", Percentage: " << student.percentage << "%\n";
    }

    inFile.close();
}

int main() {
    string filename = "students.txt";
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    writeStudentInfo(filename, n);  // Writing student info to file
    readStudentInfo(filename);      // Reading and displaying student info

    return 0;
}
