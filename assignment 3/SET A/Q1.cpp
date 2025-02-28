#include <iostream>
using namespace std;

class Number {
private:
    int num1, num2;

public:
    // Default constructor
    Number() {
        num1 = 0;
        num2 = 0;
    }

    // Parameterized constructor
    Number(int a, int b) {
        num1 = a;
        num2 = b;
    }

    // Member function to display maximum number
    void displayMax() {
        cout << "Maximum of (" << num1 << ", " << num2 << ") is: " << (num1 > num2 ? num1 : num2) << endl;
    }
};

int main() {
    // Creating object using default constructor
    Number obj1;
    cout << "Default Constructor: ";
    obj1.displayMax();

    // Creating object using parameterized constructor
    Number obj2(10, 20);
    cout << "Parameterized Constructor: ";
    obj2.displayMax();

    return 0;
}
