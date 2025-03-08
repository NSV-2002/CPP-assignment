#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Base Class: Flight
class Flight {
protected:
    int Flight_no;
    string Flight_Name;
public:
    Flight(int no, string name) : Flight_no(no), Flight_Name(name) {}
};

// Derived Class: Route (Inherits from Flight)
class Route : public Flight {
protected:
    string Source, Destination;
public:
    Route(int no, string name, string src, string dest)
        : Flight(no, name), Source(src), Destination(dest) {}
};

// Derived Class: Reservation (Inherits from Route)
class Reservation : public Route {
public:
    int Number_Of_Seats;
    string Class_Type, Travel_Date;
    double Fare;

    Reservation(int no, string name, string src, string dest, int seats, string cls, double fare, string date)
        : Route(no, name, src, dest), Number_Of_Seats(seats), Class_Type(cls), Fare(fare), Travel_Date(date) {}

    void display() const {
        cout << left << setw(10) << Flight_no << setw(15) << Flight_Name
             << setw(12) << Source << setw(12) << Destination
             << setw(8) << Number_Of_Seats << setw(12) << Class_Type
             << setw(10) << Fare << setw(12) << Travel_Date << endl;
    }
};

// Function to display all reservations
void displayReservations(const vector<Reservation>& reservations, bool businessOnly = false) {
    if (reservations.empty()) {
        cout << "No reservations available.\n"; return;
    }
    
    cout << left << setw(10) << "Flight No" << setw(15) << "Flight Name"
         << setw(12) << "Source" << setw(12) << "Destination"
         << setw(8) << "Seats" << setw(12) << "Class"
         << setw(10) << "Fare" << setw(12) << "Travel Date" << "\n";
    cout << string(85, '-') << endl;

    for (const auto& res : reservations) {
        if (!businessOnly || res.Class_Type == "Business")
            res.display();
    }
}

int main() {
    vector<Reservation> reservations;
    int choice;

    do {
        cout << "\n1. Enter Reservation\n2. Display All Reservations\n3. Display Business Class Reservations\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int flightNo, seats;
            string flightName, source, destination, classType, travelDate;
            double fare;

            cout << "Enter Flight No, Flight Name, Source, Destination, No. of Seats, Class (Economy/Business), Fare, Travel Date: ";
            cin >> flightNo;
            cin.ignore();
            getline(cin, flightName);
            cin >> source >> destination >> seats;
            cin.ignore();
            getline(cin, classType);
            cin >> fare >> travelDate;

            reservations.emplace_back(flightNo, flightName, source, destination, seats, classType, fare, travelDate);
            cout << "Reservation added!\n";
        } 
        else if (choice == 2) displayReservations(reservations);
        else if (choice == 3) displayReservations(reservations, true);
        else if (choice != 4) cout << "Invalid choice! Try again.\n";

    } while (choice != 4);

    return 0;
}
