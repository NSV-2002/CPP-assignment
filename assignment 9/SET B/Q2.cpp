#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Function to merge two files into a single file
void mergeFiles(const string &file1, const string &file2, const string &outputFile) {
    ifstream f1(file1), f2(file2);
    ofstream out(outputFile);

    if (!f1 || !f2 || !out) {
        cout << "Error opening files!" << endl;
        return;
    }

    string line;
    
    // Copy contents of first file
    while (getline(f1, line))
        out << line << endl;

    // Copy contents of second file
    while (getline(f2, line))
        out << line << endl;

    f1.close();
    f2.close();
    out.close();

    cout << "Files merged successfully into " << outputFile << endl;
}

// Function to extract words starting with lowercase vowels from FIRST.TXT to SECOND.TXT
void vowelWords(const string &sourceFile, const string &outputFile) {
    ifstream inFile(sourceFile);
    ofstream outFile(outputFile);

    if (!inFile || !outFile) {
        cout << "Error opening files!" << endl;
        return;
    }

    string word;
    while (inFile >> word) {  // Read word by word
        if (!word.empty() && (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u')) {
            outFile << word << " ";
        }
    }

    inFile.close();
    outFile.close();
    cout << "Vowel words extracted to " << outputFile << endl;
}

int main() {
    string file1 = "file1.txt"; 
    string file2 = "file2.txt"; 
    string mergedFile = "merged.txt";

    mergeFiles(file1, file2, mergedFile);  // Merging files

    string firstFile = "FIRST.TXT";
    string secondFile = "SECOND.TXT";

    vowelWords(firstFile, secondFile);  // Extracting vowel words

    return 0;
}
