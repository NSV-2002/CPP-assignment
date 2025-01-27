#include <iostream>
#include <string>
using namespace std;

class Worker {
private:
    string Worker_Name;
    int No_of_Days_Worked;
    double Pay_Rate;

public:
    // Default Constructor
    Worker() : Worker_Name("Unknown"), No_of_Days_Worked(0), Pay_Rate(0.0) {}

    // Parameterized Constructor
    Worker(string name, int days, double rate) : Worker_Name(name), No_of_Days_Worked(days), Pay_Rate(rate) {}

    // Copy Constructor
    Worker(const Worker& w) : Worker_Name(w.Worker_Name), No_of_Days_Worked(w.No_of_Days_Worked), Pay_Rate(w.Pay_Rate) {
        cout << "Copy constructor called." << endl;
    }

    // Function to calculate salary
    double calculateSalary() const {
        return No_of_Days_Worked * Pay_Rate;
    }

    // Function to display worker details
    void display() const {
        cout << "Worker Name: " << Worker_Name << endl;
        cout << "Number of Days Worked: " << No_of_Days_Worked << endl;
        cout << "Pay Rate: " << Pay_Rate << endl;
        cout << "Salary: " << calculateSalary() << endl;
    }
};

int main() {
    // Default constructor
    Worker worker1;
    cout << "Worker 1 (default constructor):" << endl;
    worker1.display();

    cout << endl;

    // Parameterized constructor
    Worker worker2("John Doe", 25, 150.50);
    cout << "Worker 2 (parameterized constructor):" << endl;
    worker2.display();

    cout << endl;

    // Copy constructor
    Worker worker3 = worker2;
    cout << "Worker 3 (copy constructor):" << endl;
    worker3.display();

    return 0;
}
