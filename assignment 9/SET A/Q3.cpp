#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream file("text.txt"); // Open the file for reading
    if (!file) {
        cout << "Error opening file!\n";
        return 1;
    }

    string word, searchWord;
    int count = 0;

    cout << "Enter the word to search: ";
    cin >> searchWord; // Get the word to search

    while (file >> word) { // Read words one by one
        if (word == searchWord)
            count++;
    }

    file.close(); // Close the file

    cout << "The word '" << searchWord << "' appeared " << count << " times in the file.\n";
    return 0;
}
