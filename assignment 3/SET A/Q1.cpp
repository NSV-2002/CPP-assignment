#include <iostream>
using namespace std;

class Number {
private:
    int num1;
    int num2;

public:
    // Default Constructor
    Number() : num1(0), num2(0) {}

    // Parameterized Constructor
    Number(int a, int b) : num1(a), num2(b) {}

    // Member Function to display the maximum of the two numbers
    void displayMax() const {
        cout << "The maximum of " << num1 << " and " << num2 << " is " 
             << (num1 > num2 ? num1 : num2) << "." << endl;
    }

    // Function to display the numbers
    void displayNumbers() const {
        cout << "Numbers: " << num1 << ", " << num2 << endl;Q2