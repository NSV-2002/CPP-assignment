#include <iostream>
using namespace std;

// Function to calculate Simple Interest with default arguments
int calculate(int p, int n = 10, int r = 7) {
    return (p * n * r) / 100;
}

int main() {
    int principal, years, rate;
    
    cout << "Enter principal amount: ";
    cin >> principal;
    
    cout << "Simple Interest with default years (10) and rate (7%): " << calculate(principal) << endl;
    
    cout << "Enter number of years: ";
    cin >> years;
    cout << "Enter rate of interest: ";
    cin >> rate;
    
    cout << "Simple Interest with given years and rate: " << calculate(principal, years, rate) << endl;
    
    return 0;
}