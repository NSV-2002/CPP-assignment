#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;
public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}
    
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
    
    // Overload + operator for addition
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }
    
    // Overload * operator for multiplication
    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }
};

int main() {
    float r1, i1, r2, i2;
    
    cout << "Enter real and imaginary part of first complex number: ";
    cin >> r1 >> i1;
    cout << "Enter real and imaginary part of second complex number: ";
    cin >> r2 >> i2;
    
    Complex c1(r1, i1), c2(r2, i2);
    
    Complex sum = c1 + c2;
    Complex product = c1 * c2;
    
    cout << "Sum of complex numbers: ";
    sum.display();
    cout << "Product of complex numbers: ";
    product.display();
    
    return 0;
}
