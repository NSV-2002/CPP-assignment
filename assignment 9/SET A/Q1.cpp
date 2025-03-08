#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("input.txt");  // Open the file
    if (!file) {
        cout << "Error opening file!\n";
        return 1;
    }

    int upperCount = 0, lowerCount = 0, digitCount = 0, spaceCount = 0;
    char ch;

    while (file.get(ch)) {  // Read character by character
        if (isupper(ch)) upperCount++;
        else if (islower(ch)) lowerCount++;
        else if (isdigit(ch)) digitCount++;
        else if (isspace(ch)) spaceCount++;
    }

    file.close();  // Close the file

    cout << "Uppercase Letters: " << upperCount << endl;
    cout << "Lowercase Letters: " << lowerCount << endl;
    cout << "Digits: " << digitCount << endl;
    cout << "Spaces: " << spaceCount << endl;

    return 0;
}
