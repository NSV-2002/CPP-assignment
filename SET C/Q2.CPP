#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
bool canBeExpressedAsSumOfTwoPrimes(int num) {
    for (int i = 2; i <= num / 2; i++) {
        if (isPrime(i) && isPrime(num - i)) {
            return true;
        }
    }
    return false;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (canBeExpressedAsSumOfTwoPrimes(num)) {
        cout << num << " can be expressed as the sum of two prime numbers." << endl;
    } else {
        cout << num << " cannot be expressed as the sum of two prime numbers." << endl;
    }

    return 0;
}
