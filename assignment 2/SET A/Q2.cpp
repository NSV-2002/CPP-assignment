#include <iostream>
using namespace std;

class DISTANCE {
private:
    int feet;
    float inches;

public:
    DISTANCE() {
        feet = 0;
        inches = 0.0;
    }

    void inputDistance() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
        normalize();
    }

    void outputDistance() const {
        cout << feet << " feet " << inches << " inches" << endl;
    }

    DISTANCE addDistance(const DISTANCE &d) const {
        DISTANCE result;
        result.feet = feet + d.feet;
        result.inches = inches + d.inches;
        result.normalize();
        return result;
    }

private:
    void normalize() {
        if (inches >= 12.0) {
            feet += static_cast<int>(inches) / 12;
            inches = fmod(inches, 12.0);  
        }
    }
};

int main() {
    DISTANCE d1, d2, sum;

    cout << "Enter first distance:\n";
    d1.inputDistance();

    cout << "\nEnter second distance:\n";
    d2.inputDistance();

    sum = d1.addDistance(d2);

    cout << "\nFirst Distance: ";
    d1.outputDistance();

    cout << "Second Distance: ";
    d2.outputDistance();

    cout << "Sum of Distances: ";
    sum.outputDistance();

    return 0;
}
