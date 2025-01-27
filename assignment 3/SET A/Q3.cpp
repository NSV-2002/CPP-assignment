#include <iostream>
#include <iomanip> // For formatting output
#include <string>
using namespace std;

class Mobile {
private:
    int mobileId;
    string mobileName;
    double mobilePrice;

public:
    // Parameterized Constructor
    Mobile(int id, string name, double price) : mobileId(id), mobileName(name), mobilePrice(price) {}

    // Function to display mobile details
    void display() const {
        cout << left << setw(15) << "Mobile ID:" << mobileId << endl;
        cout << left << setw(15) << "Mobile Name:" << mobileName << endl;
        cout << left << setw(15) << "Mobile Price:" 
             << right << setw(10) << fixed << setprecision(2) << mobilePrice << endl;
    }
};

int main() {
    int id;
    string name;
    double price;

    // Input details for the mobile object
    cout << "Enter Mobile ID: ";
    cin >> id;
    cin.ignore(); // Clear input buffer
    cout << "Enter Mobile Name: ";
    getline(cin, name);
    cout << "Enter Mobile Price: ";
    cin >> price;

    // Create and initialize the Mobile object
    Mobile mobile(id, name, price);

    // Display the mobile details
    cout << "\nMobile Details:\n";
    mobile.display();

    return 0;
}
