#include <iostream>
using namespace std;

class SumCalculator {
private:
    int n;
    int sum;

public:
    // Parameterized Constructor
    SumCalculator(int num) : n(num), sum(0) {
        calculateSum();
    }

    // Function to calculate the sum
    void calculateSum() {
        for (int i = 1; i <= n; ++i) {
            sum += i;
        }
    }

    // Function to display the sum
    void display() const {
        cout << "The sum of numbers from 1 to " << n << " is: " << sum << endl;
    }
};

int main() {
    int n;

    // Input value of n
    cout << "Enter the value of n: ";
    cin >> n;

    // Create object and calculate sum
    SumCalculator calculator(n);

    // Display the result
    calculator.display();

    return 0;
}
