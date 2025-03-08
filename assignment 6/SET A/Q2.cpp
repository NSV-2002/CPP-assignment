#include <iostream>
using namespace std;

class Employee {
private:
    int salary;
public:
    Employee(int s) : salary(s) {}
    
    // Pre-decrement operator overload
    Employee& operator--() {
        --salary;
        return *this;
    }
    
    // Post-decrement operator overload
    Employee operator--(int) {
        Employee temp = *this;
        salary--;
        return temp;
    }
    
    void display() {
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Employee emp(5000);
    
    cout << "Original salary:" << endl;
    emp.display();
    
    cout << "After pre-decrement:" << endl;
    --emp;
    emp.display();
    
    cout << "After post-decrement:" << endl;
    emp--;
    emp.display();
    
    return 0;
}