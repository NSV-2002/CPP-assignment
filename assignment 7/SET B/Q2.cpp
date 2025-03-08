#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Base Class: Train
class Train {
protected:
    int Train_no;
    string Train_Name;
public:
    Train(int no, string name) : Train_no(no), Train_Name(name) {}
};

// Derived Class: Route (Inherits from Train)
class Route : public Train {
protected:
    int Route_id;
    string Source, Destination;
public:
    Route(int no, string name, int rid, string src, string dest)
        : Train(no, name), Route_id(rid), Source(src), Destination(dest) {}
};

// Derived Class: Reservation (Inherits from Route)
class Reservation : public Route {
public:
    int Number_of_Seats;
    string Train_Class, Travel_Date;
    double Fare;

    Reservation(int no, string name, int rid, string src, string dest, int seats, string cls, double fare, string date)
        : Route(no, name, rid, src, dest), Number_of_Seats(seats), Train_Class(cls), Fare(fare), Travel_Date(date) {}

    void display() const {
        cout << left << setw(8) << Train_no << setw(15) << Train_Name
             << setw(8) << Route_id << setw(12) << Source << setw(12) << Destination
             << setw(8) << Number_of_Seats << setw(12) << Train_Class
             << setw(10) << Fare << setw(12) << Travel_Date << endl;
    }
};

// Function to display reservations
void displayReservations(const vector<Reservation>& reservations, const string& filterClass = "") {
    if (reservations.empty()) {
        cout << "No reservations available.\n"; return;
    }

    cout << left << setw(8) << "TrainNo" << setw(15) << "Train Name"
         << setw(8) << "RouteID" << setw(12) << "Source" << setw(12) << "Destination"
         << setw(8) << "Seats" << setw(12) << "Class"
         << setw(10) << "Fare" << setw(12) << "Travel Date" << "\n";
    cout << string(90, '-') << endl;

    for (const auto& res : reservations) {
        if (filterClass.empty() || res.Train_Class == filterClass)
            res.display();
    }
}

int main() {
    vector<Reservation> reservations;
    int choice;

    do {
        cout << "\n1. Enter Reservation\n2. Display All Reservations\n3. Display Reservations by Class\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int trainNo, routeId, seats;
            string trainName, source, destination, trainClass, travelDate;
            double fare;

            cout << "Enter Train No, Train Name, Route ID, Source, Destination, No. of Seats, Class (Sleeper/AC/General), Fare, Travel Date: ";
            cin >> trainNo;
            cin.ignore();
            getline(cin, trainName);
            cin >> routeId >> source >> destination >> seats;
            cin.ignore();
            getline(cin, trainClass);
            cin >> fare >> travelDate;

            reservations.emplace_back(trainNo, trainName, routeId, source, destination, seats, trainClass, fare, travelDate);
            cout << "Reservation added!\n";
        } 
        else if (choice == 2) displayReservations(reservations);
        else if (choice == 3) {
            string filterClass;
            cout << "Enter Train Class to filter (Sleeper/AC/General): ";
            cin.ignore();
            getline(cin, filterClass);
            displayReservations(reservations, filterClass);
        }
        else if (choice != 4) cout << "Invalid choice! Try again.\n";

    } while (choice != 4);

    return 0;
}
