#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;
public:
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}
    
    friend Complex add(Complex, Complex);
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

Complex add(Complex c1, Complex c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    float r1, i1, r2, i2;
    
    cout << "Enter real and imaginary part of first complex number: ";
    cin >> r1 >> i1;
    cout << "Enter real and imaginary part of second complex number: ";
    cin >> r2 >> i2;
    
    Complex c1(r1, i1), c2(r2, i2);
    Complex sum = add(c1, c2);
    
    cout << "Sum of complex numbers: ";
    sum.display();
    
    return 0;
}
