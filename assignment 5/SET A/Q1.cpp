#include <iostream>
using namespace std;

class Shape {
public:
    inline float areaCircle(float radius) {
        return 3.14159 * radius * radius;
    }
    
    inline float areaSquare(float side) {
        return side * side;
    }
    
    inline float areaRectangle(float length, float width) {
        return length * width;
    }
};

int main() {
    Shape shape;
    float radius, side, length, width;
    
    cout << "Enter radius of circle: ";
    cin >> radius;
    cout << "Area of Circle: " << shape.areaCircle(radius) << endl;
    
    cout << "Enter side of square: ";
    cin >> side;
    cout << "Area of Square: " << shape.areaSquare(side) << endl;
    
    cout << "Enter length and width of rectangle: ";
    cin >> length >> width;
    cout << "Area of Rectangle: " << shape.areaRectangle(length, width) << endl;
    
    return 0;
}
