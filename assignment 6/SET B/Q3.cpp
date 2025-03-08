#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;
    int length;
public:
    String(const char* s = "") {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
    
    ~String() {
        delete[] str;
    }
    
    // Overload ! operator to reverse the case
    void operator!() {
        for (int i = 0; i < length; i++) {
            if (isupper(str[i]))
                str[i] = tolower(str[i]);
            else if (islower(str[i]))
                str[i] = toupper(str[i]);
        }
    }
    
    // Overload [] operator to access character at index
    char operator[](int index) {
        if (index >= 0 && index < length)
            return str[index];
        else {
            cout << "Index out of bounds!" << endl;
            return '\0';
        }
    }
    
    // Overload < operator to compare string lengths
    bool operator<(const String& s) {
        return length < s.length;
    }
    
    // Overload == operator to compare equality of strings
    bool operator==(const String& s) {
        return strcmp(str, s.str) == 0;
    }
    
    // Overload + operator to concatenate strings
    String operator+(const String& s) {
        char* newStr = new char[length + s.length + 1];
        strcpy(newStr, str);
        strcat(newStr, s.str);
        
        String temp(newStr);
        delete[] newStr;
        return temp;
    }
    
    void display() {
        cout << str << endl;
    }
};

int main() {
    String s1("Hello"), s2("World");
    
    cout << "Original strings:" << endl;
    s1.display();
    s2.display();
    
    // Case reversal
    !s1;
    cout << "After case reversal: ";
    s1.display();
    
    // Character access
    cout << "Character at index 1 in s1: " << s1[1] << endl;
    
    // Length comparison
    cout << "Is s1 shorter than s2? " << (s1 < s2 ? "Yes" : "No") << endl;
    
    // Equality check
    cout << "Are s1 and s2 equal? " << (s1 == s2 ? "Yes" : "No") << endl;
    
    // Concatenation
    String s3 = s1 + s2;
    cout << "Concatenated string: ";
    s3.display();
    
    return 0;
}
