#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char str[100];

public:
    MyString() {
        strcpy(str, "");
    }
    MyString(const char* s) {
        strcpy(str, s);
    }
    void inputString() {
        cout << "Enter a string: ";
        cin.ignore();
        cin.getline(str, 100);
    }
    void displayString() const {
        cout << str << endl;
    }
    int findLength() const {
        return strlen(str);
    }
    MyString concatenate(const MyString& s) const {
        MyString result;
        strcpy(result.str, str);
        strcat(result.str, s.str);
        return result;
    }
    MyString reverseString() const {
        MyString result;
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            result.str[i] = str[len - i - 1];
        }
        result.str[len] = '\0';
        return result;
    }
    int compareStrings(const MyString& s) const {
        return strcmp(str, s.str);
    }
};
int main() {
    MyString s1, s2, result;
    int choice;
    do {
        cout << "\n--- String Operations Menu ---\n";
        cout << "1. Input Strings\n";
        cout << "2. Find Length of String\n";
        cout << "3. Concatenate Two Strings\n";
        cout << "4. Reverse String\n";
        cout << "5. Compare Two Strings\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Input first string:\n";
                s1.inputString();
                cout << "Input second string:\n";
                s2.inputString();
                break;

            case 2:
                cout << "Length of first string: " << s1.findLength() << endl;
                cout << "Length of second string: " << s2.findLength() << endl;
                break;

            case 3:
                result = s1.concatenate(s2);
                cout << "Concatenated String: ";
                result.displayString();
                break;

            case 4:
                result = s1.reverseString();
                cout << "Reversed first string: ";
                result.displayString();

                result = s2.reverseString();
                cout << "Reversed second string: ";
                result.displayString();
                break;

            case 5: {
                int comparison = s1.compareStrings(s2);
                if (comparison == 0) {
                    cout << "Both strings are equal." << endl;
                } else if (comparison > 0) {
                    cout << "First string is greater than the second string." << endl;
                } else {
                    cout << "First string is smaller than the second string." << endl;
                }
                break;
            }

            case 6:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    return 0;
}
