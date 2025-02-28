#include <iostream>
#include <cstring>
using namespace std;

class MyString {
private:
    char* name;
    int length;

public:
    // Dynamic Constructor to allocate memory
    MyString(const char* str) {
        length = strlen(str);
        name = new char[length + 1];
        strcpy(name, str);
    }

    // Function to concatenate two strings
    MyString operator+(const MyString& other) {
        MyString temp("");
        temp.length = length + other.length;
        delete[] temp.name;
        temp.name = new char[temp.length + 1];
        strcpy(temp.name, name);
        strcat(temp.name, other.name);
        return temp;
    }

    // Function to display string
    void display() {
        cout << "String: " << name << endl;
    }

    // Destructor to deallocate memory
    ~MyString() {
        delete[] name;
        cout << "Memory deallocated successfully." << endl;
    }
};

int main() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    MyString s1(str1), s2(str2);
    MyString s3 = s1 + s2;

    cout << "Concatenated string: ";
    s3.display();
    
    return 0;
}
