#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to count lines not starting with 'A'
int countLinesNotStartingWithA(const string &filename) {
    ifstream file(filename); // Open file for reading
    if (!file) {
        cout << "Error opening file!\n";
        return -1;
    }

    string line;
    int count = 0;

    while (getline(file, line)) { // Read line by line
        if (line.empty() || line[0] != 'A') // Check if first character is not 'A'
            count++;
    }

    file.close(); // Close the file
    return count;
}

int main() {
    string filename = "text.txt"; // File name
    int result = countLinesNotStartingWithA(filename);

    if (result != -1)
        cout << "Number of lines not starting with 'A': " << result << endl;

    return 0;
}
