#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;

public:
    // Default Constructor
    Point() : x(0), y(0) {}

    // Parameterized Constructor
    Point(int xValue, int yValue) : x(xValue), y(yValue) {}

    // Copy Constructor
    Point(const Point& p) : x(p.x), y(p.y) {
        cout << "Copy constructor called." << endl;
    }

    // Function to display the point
    void display() const {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // Default constructor
    Point p1;
    cout << "Object p1 initialized using default constructor:\n";
    p1.display();

    // Parameterized constructor
    Point p2(10, 20);
    cout << "\nObject p2 initialized using parameterized constructor:\n";
    p2.display();

    // Copy constructor
    Point p3 = p2;
    cout << "\nObject p3 initialized using copy constructor (copy of p2):\n";
    p3.display();

    return 0;
}
