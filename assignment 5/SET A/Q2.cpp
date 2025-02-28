#include <iostream>
using namespace std;

class ClassB; // Forward declaration

class ClassA {
private:
    int numA;
public:
    ClassA(int a) : numA(a) {}
    friend int subtract(ClassA, ClassB);
};

class ClassB {
private:
    int numB;
public:
    ClassB(int b) : numB(b) {}
    friend int subtract(ClassA, ClassB);
};

int subtract(ClassA a, ClassB b) {
    return a.numA - b.numB;
}

int main() {
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    
    ClassA objA(a);
    ClassB objB(b);
    
    cout << "Subtraction result: " << subtract(objA, objB) << endl;
    
    return 0;
}