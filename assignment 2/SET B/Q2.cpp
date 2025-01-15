#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Bus {
private:
    int busNo;
    string busName;
    int noOfSeats;
    string startingPoint;
    string destination;

public:
    void acceptDetails() {
        cout << "Enter Bus Number: ";
        cin >> busNo;
        cin.ignore();
        cout << "Enter Bus Name: ";
        getline(cin, busName);
        cout << "Enter Number of Seats: ";
        cin >> noOfSeats;
        cin.ignore();
        cout << "Enter Starting Point: ";
        getline(cin, startingPoint);
        cout << "Enter Destination: ";
        getline(cin, destination);
    }

    void displayDetails() const {
        cout << left << setw(10) << busNo
             << setw(20) << busName
             << setw(15) << noOfSeats
             << setw(20) << startingPoint
             << setw(20) << destination << endl;
    }

    string getStartingPoint() const {
        return startingPoint;
    }

    string getDestination() const {
        return destination;
    }
};

int main() {
    int n, choice;
    cout << "Enter the number of buses: ";
    cin >> n;
    Bus* buses = new Bus[n];

    do {
        cout << "\n--- Bus Management Menu ---\n";
        cout << "1. Accept Bus Details\n";
        cout << "2. Display All Bus Details\n";
        cout << "3. Display Buses by Starting and Ending Point\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter details for Bus " << i + 1 << ":\n";
                    buses[i].acceptDetails();
                }
                break;

            case 2:
                cout << left << setw(10) << "Bus No"
                     << setw(20) << "Bus Name"
                     << setw(15) << "Seats"
                     << setw(20) << "Starting Point"
                     << setw(20) << "Destination" << endl;
                cout << string(85, '-') << endl;
                for (int i = 0; i < n; i++) {
                    buses[i].displayDetails();
                }
                break;

            case 3: {
                string start, end;
                cin.ignore();
                cout << "Enter Starting Point: ";
                getline(cin, start);
                cout << "Enter Destination: ";
                getline(cin, end);

                cout << left << setw(10) << "Bus No"
                     << setw(20) << "Bus Name"
                     << setw(15) << "Seats"
                     << setw(20) << "Starting Point"
                     << setw(20) << "Destination" << endl;
                cout << string(85, '-') << endl;
                for (int i = 0; i < n; i++) {
                    if (buses[i].getStartingPoint() == start && buses[i].getDestination() == end) {
                        buses[i].displayDetails();
                    }
                }
                break;
            }

            case 4:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    delete[] buses;
    return 0;
}
