#include <iostream>
using namespace std;

class Number {
private:
    int value;
public:
    Number(int v) : value(v) {}
    
    // Pre-increment operator overload
    Number& operator++() {
        ++value;
        return *this;
    }
    
    // Post-increment operator overload
    Number operator++(int) {
        Number temp = *this;
        value++;
        return temp;
    }
    
    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num(10);
    
    cout << "Original value:" << endl;
    num.display();
    
    cout << "After pre-increment:" << endl;
    ++num;
    num.display();
    
    cout << "After post-increment:" << endl;
    num++;
    num.display();
    
    return 0;
}
