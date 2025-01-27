#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int dd, mm, yyyy;

    // Array of month names
    string monthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                             "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

public:
    // Parameterized Constructor
    Date(int day, int month, int year) {
        if (month < 1 || month > 12) {
            throw invalid_argument("Invalid month. Month must be between 1 and 12.");
        }
        dd = day;
        mm = month;
        yyyy = year;
    }

    // Function to display the date
    void display() const {
        cout << (dd < 10 ? "0" : "") << dd << "-" << monthNames[mm - 1] << "-" << yyyy << endl;
    }
};

int main() {
    try {
        int day, month, year;

        // Input the date
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;

        // Create and initialize Date object
        Date date(day, month, year);

        // Display the date in dd-mon-yyyy format
        cout << "Formatted Date: ";
        date.display();
    } catch (const invalid_argument& e) {
        // Handle invalid month input
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
