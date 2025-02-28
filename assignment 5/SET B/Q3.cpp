#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Telephone {
private:
    string name;
    string telephoneNumber;
    string city;

public:
    Telephone(string n, string t, string c) : name(n), telephoneNumber(t), city(c) {}
    
    string getName() { return name; }
    string getTelephoneNumber() { return telephoneNumber; }
    string getCity() { return city; }
    
    static void searchByName(vector<Telephone>& directory, string n) {
        for (auto& entry : directory) {
            if (entry.name == n) {
                cout << "Telephone Number: " << entry.telephoneNumber << endl;
                return;
            }
        }
        cout << "Name not found in directory." << endl;
    }
    
    static void searchByNumber(vector<Telephone>& directory, string t) {
        for (auto& entry : directory) {
            if (entry.telephoneNumber == t) {
                cout << "Name: " << entry.name << endl;
                return;
            }
        }
        cout << "Telephone number not found in directory." << endl;
    }
    
    static void searchByCity(vector<Telephone>& directory, string c) {
        bool found = false;
        for (auto& entry : directory) {
            if (entry.city == c) {
                cout << "Name: " << entry.name << " | Telephone Number: " << entry.telephoneNumber << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No customers found in the given city." << endl;
        }
    }
};

int main() {
    vector<Telephone> directory = {
        Telephone("Alice", "1234567890", "New York"),
        Telephone("Bob", "9876543210", "Los Angeles"),
        Telephone("Charlie", "5555555555", "New York"),
        Telephone("David", "4444444444", "Chicago")
    };
    
    int choice;
    string input;
    
    do {
        cout << "\nTelephone Directory Search:\n";
        cout << "1. Search by Name\n";
        cout << "2. Search by Telephone Number\n";
        cout << "3. Search by City\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, input);
                Telephone::searchByName(directory, input);
                break;
            case 2:
                cout << "Enter telephone number: ";
                getline(cin, input);
                Telephone::searchByNumber(directory, input);
                break;
            case 3:
                cout << "Enter city: ";
                getline(cin, input);
                Telephone::searchByCity(directory, input);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}