#include <iostream>
using namespace std;

class Array {
private:
    float* arr;
    int size;
public:
    Array(int s) : size(s) {
        arr = new float[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
    
    ~Array() {
        delete[] arr;
    }
    
    void input() {
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }
    
    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    friend Array operator++(Array&);
    friend Array operator--(Array&);
};

// Overloading pre-increment operator
Array operator++(Array& obj) {
    for (int i = 0; i < obj.size; i++) {
        obj.arr[i]++;
    }
    return obj;
}

// Overloading pre-decrement operator
Array operator--(Array& obj) {
    for (int i = 0; i < obj.size; i++) {
        obj.arr[i]--;
    }
    return obj;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    
    Array arr(size);
    arr.input();
    
    cout << "Original array: ";
    arr.display();
    
    ++arr;
    cout << "After incrementing: ";
    arr.display();
    
    --arr;
    cout << "After decrementing: ";
    arr.display();
    
    return 0;
}