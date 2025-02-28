#include <iostream>
using namespace std;

class Rectangle2; // Forward declaration

class Rectangle1 {
private:
    int length, width;
public:
    Rectangle1(int l, int w) : length(l), width(w) {}
    friend void compareArea(Rectangle1, Rectangle2);
};

class Rectangle2 {
private:
    int length, width;
public:
    Rectangle2(int l, int w) : length(l), width(w) {}
    friend void compareArea(Rectangle1, Rectangle2);
};

void compareArea(Rectangle1 r1, Rectangle2 r2) {
    int area1 = r1.length * r1.width;
    int area2 = r2.length * r2.width;
    
    cout << "Area of Rectangle1: " << area1 << endl;
    cout << "Area of Rectangle2: " << area2 << endl;
    
    if (area1 > area2) {
        cout << "Rectangle1 has a larger area." << endl;
    } else if (area1 < area2) {
        cout << "Rectangle2 has a larger area." << endl;
    } else {
        cout << "Both rectangles have the same area." << endl;
    }
}

int main() {
    int l1, w1, l2, w2;
    
    cout << "Enter length and width of Rectangle1: ";
    cin >> l1 >> w1;
    cout << "Enter length and width of Rectangle2: ";
    cin >> l2 >> w2;
    
    Rectangle1 r1(l1, w1);
    Rectangle2 r2(l2, w2);
    
    compareArea(r1, r2);
    
    return 0;
}