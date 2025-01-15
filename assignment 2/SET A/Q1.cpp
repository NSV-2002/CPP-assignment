#include <iostream>
#include <cmath>  // For M_PI
using namespace std;

class Cylinder {
private:
    float radius;
    float height;

public:
    Cylinder() {
        radius = 0;
        height = 0;
    }

    void setradius(float r) {
        radius = r;
    }

    void setheight(float h) {
        height = h;
    }
   
    float volume() {
        return M_PI * radius * radius * height;  // π * r^2 * h
    }

    float area() {
        return 2 * M_PI * radius * (radius + height);  // 2πr(r + h)
    }

    void display() {
        cout << "Radius: " << radius << ", Height: " << height << endl;
        cout << "Surface Area: " << area() << endl;
        cout << "Volume: " << volume() << endl;
    }
};

int main() {
    Cylinder cyl1, cyl2;

    cyl1.setradius(3.0);
    cyl1.setheight(5.0);

    cyl2.setradius(4.5);
    cyl2.setheight(7.2);

    cout << "Cylinder 1 Details:" << endl;
    cyl1.display();

    cout << "\nCylinder 2 Details:" << endl;
    cyl2.display();

    return 0;
}
