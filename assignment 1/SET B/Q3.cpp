#include<iostream>
using namespace std;

int main() {
    int decimal;
    char hex[20]; 
    int i = 0; 

    cout << "Enter a decimal number: ";
    cin >> decimal;

    int original = decimal; 
    while (decimal > 0) {
        int remainder = decimal % 16;

        if (remainder < 10)
            hex[i] = '0' + remainder;
        else
            hex[i] = 'A' + (remainder - 10);

        i++;
        decimal /= 16; 
    }

    cout << "The hexadecimal equivalent of " << original << " is: ";
    for (int j = i - 1; j >= 0; j--) {
        cout << hex[j];
    }
    cout << endl;

    return 0;
}
