#include <iostream>
using namespace std;

class SimpleInterest {
private:
    double principal;
    double rate;
    int time;

public:
    // Parameterized Constructor with default value for rate
    SimpleInterest(double p, int t, double r = 5.0) : principal(p), time(t), rate(r) {}

    // Function to calculate and return the simple interest
    double calculate() const {
        return (principal * rate * time) / 100.0;
    }

    // Function to display the details
    void display() const {
        cout << "Principal: " << principal << endl;
        cout << "Time (years): " << time << endl;
        cout << "Rate of Interest: " << rate << "%" << endl;
        cout << "Simple Interest: " << calculate() << endl;
    }
};

int main() {
    // Using parameterized constructor with a custom rate
    cout << "Enter Principal, Time (in years), and Rate of Interest: ";
    double principal, rate;
    int time;
    cin >> principal >> time >> rate;

    SimpleInterest si1(principal, time, rate);
    cout << "\nDetails with custom rate:" << endl;
    si1.display();

    // Using parameterized constructor with the default rate
    cout << "\nEnter Principal and Time (in years) for default rate (5%): ";
    cin >> principal >> time;

    SimpleInterest si2(principal, time); // Default rate of 5% will be used
    cout << "\nDetails with default rate:" << endl;
    si2.display();

    return 0;
}
