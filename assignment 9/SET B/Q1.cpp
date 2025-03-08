#include <iostream>
#include <fstream>
using namespace std;

void copyFile(const string &sourceFile, const string &destinationFile) {
    ifstream source(sourceFile);  // Open source file for reading
    ofstream destination(destinationFile);  // Open destination file for writing

    if (!source || !destination) {
        cout << "Error opening file!\n";
        return;
    }

    string line;
    while (getline(source, line)) {  // Read line by line
        destination << line << endl; // Write to destination file
    }

    source.close();
    destination.close();
    cout << "File copied successfully!\n";
}

int main() {
    string sourceFile = "source.txt";  // Source file name
    string destinationFile = "destination.txt";  // Destination file name

    copyFile(sourceFile, destinationFile);  // Copy file contents

    return 0;
}
