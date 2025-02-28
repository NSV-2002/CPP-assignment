#include <iostream>
using namespace std;

class PrimeChecker {
private:
    int* number;

public:
    // Constructor to allocate memory and take input
    PrimeChecker(int n) {
        number = new int(n);
    }

    // Function to check if the number is prime
    bool isPrime() {
        if (*number < 2)
            return false;
        for (int i = 2; i * i <= *number; i++) {
            if (*number % i == 0)
                return false;
        }
        return true;
    }

    // Function to display result
    void display() {
        if (isPrime())
            cout << *number << " is a prime number." << endl;
        else
            cout << *number << " is not a prime number." << endl;
    }

    // Destructor to deallocate memory
    ~PrimeChecker() {
        delete number;
        cout << "Memory deallocated successfully." << endl;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    PrimeChecker obj(n);
    obj.display();
    return 0;
}