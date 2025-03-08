#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("numbers.txt"); // Open file for reading
    if (!file) {
        cout << "Error opening file!\n";
        return 1;
    }

    int num, sum = 0;

    while (file >> num) { // Read integers from file
        sum += num;
    }

    file.close(); // Close the file

    cout << "Sum of all integers: " << sum << endl;
    return 0;
}
