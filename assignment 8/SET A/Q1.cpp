#include <iostream>
#include <cmath>
using namespace std;

// Base Class: Shape
class Shape {
public:
    virtual double area() = 0;  // Pure virtual function
    virtual void display() = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor
};

// Derived Class: Circle
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() override { return M_PI * radius * radius; }
    void display() override {
        cout << "Shape: Circle | Radius: " << radius << " | Area: " << area() << endl;
    }
};

// Derived Class: Rectangle
class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() override { return length * width; }
    void display() override {
        cout << "Shape: Rectangle | Length: " << length << ", Width: " << width << " | Area: " << area() << endl;
    }
};

// Derived Class: Trapezoid
class Trapezoid : public Shape {
    double base1, base2, height;
public:
    Trapezoid(double a, double b, double h) : base1(a), base2(b), height(h) {}
    double area() override { return 0.5 * (base1 + base2) * height; }
    void display() override {
        cout << "Shape: Trapezoid | Bases: " << base1 << ", " << base2 << ", Height: " << height << " | Area: " << area() << endl;
    }
};

// Main Function
int main() {
    Shape* shapes[] = { new Circle(5), new Rectangle(4, 6), new Trapezoid(3, 5, 4) };

    cout << "\nDisplaying Shapes and Their Areas:\n";
    for (auto shape : shapes) {
        shape->display();
        delete shape;
    }

    return 0;
}
