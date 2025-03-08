#include <iostream>
using namespace std;

class Vector {
private:
    int x, y, z;
public:
    Vector(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {}
    
    // Overload * operator for dot product
    friend int operator*(const Vector& v1, const Vector& v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }
    
    // Overload >> operator for input
    friend istream& operator>>(istream& in, Vector& v) {
        cout << "Enter vector components (x, y, z): ";
        in >> v.x >> v.y >> v.z;
        return in;
    }
    
    // Overload << operator for output
    friend ostream& operator<<(ostream& out, const Vector& v) {
        out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return out;
    }
};

int main() {
    Vector v1, v2;
    
    cin >> v1;
    cin >> v2;
    
    cout << "Vector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;
    
    int dotProduct = v1 * v2;
    cout << "Dot Product: " << dotProduct << endl;
    
    return 0;
}