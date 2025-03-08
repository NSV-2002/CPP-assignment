#include <iostream>
using namespace std;

// Base class
class Car {
public:
    void displayCar() {
        cout << "This is a Car." << endl;
    }
};

// Derived class from Car
class Maruti : public Car {
public:
    void displayMaruti() {
        cout << "This is a Maruti Car." << endl;
    }
};

// Derived class from Maruti (Multilevel Inheritance)
class Maruti800 : public Maruti {
public:
    void displayMaruti800() {
        cout << "This is a Maruti 800 Model." << endl;
    }
};

int main() {
    Maruti800 myCar;

    // Calling methods from all three classes
    myCar.displayCar();        // From Car class
    myCar.displayMaruti();     // From Maruti class
    myCar.displayMaruti800();  // From Maruti800 class

    return 0;
}
