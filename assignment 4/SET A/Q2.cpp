#include <iostream>
using namespace std;

class DynamicMemory {
private:
    int* ptr;

public:
    // Constructor to allocate memory
    DynamicMemory() {
        ptr = new int;
        cout << "Enter an integer value: ";
        cin >> *ptr;
    }

    // Function to display value
    void display() {
        cout << "You entered: " << *ptr << endl;
    }

    // Destructor to deallocate memory
    ~DynamicMemory() {
        delete ptr;
        cout << "Memory deallocated successfully." << endl;
    }
};

int main() {
    DynamicMemory obj;
    obj.display();
    return 0;
}