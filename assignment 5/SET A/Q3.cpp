#include <iostream>
using namespace std;

class VolumeCalculator {
public:
    // Volume of Cube
    double volume(double side) {
        return side * side * side;
    }
    
    // Volume of Cylinder
    double volume(double radius, double height) {
        return 3.14159 * radius * radius * height;
    }
    
    // Volume of Sphere
    double volume(double radius, bool isSphere) {
        return (4.0 / 3.0) * 3.14159 * radius * radius * radius;
    }
};

int main() {
    VolumeCalculator vc;
    double side, radius, height;
    
    cout << "Enter side of cube: ";
    cin >> side;
    cout << "Volume of Cube: " << vc.volume(side) << endl;
    
    cout << "Enter radius and height of cylinder: ";
    cin >> radius >> height;
    cout << "Volume of Cylinder: " << vc.volume(radius, height) << endl;
    
    cout << "Enter radius of sphere: ";
    cin >> radius;
    cout << "Volume of Sphere: " << vc.volume(radius, true) << endl;
    
    return 0;
}