#include <iostream>
#include <iomanip>  // For manipulators like setw, setprecision
using namespace std;

class District {
private:
    int district_code;
    string district_name;
    float area_sqft;
    long population;
    float literacy_rate;

public:
    // Function to accept district details
    void acceptDetails() {
        cout << "Enter District Code: ";
        cin >> district_code;
        cin.ignore();  // To clear the newline character from the input buffer
        cout << "Enter District Name: ";
        getline(cin, district_name);
        cout << "Enter Area (in sq. ft): ";
        cin >> area_sqft;
        cout << "Enter Population: ";
        cin >> population;
        cout << "Enter Literacy Rate (%): ";
        cin >> literacy_rate;
    }

    // Function to display district details
    void displayDetails() const {
        cout << setw(10) << district_code
             << setw(20) << district_name
             << setw(15) << area_sqft
             << setw(15) << population
             << setw(15) << fixed << setprecision(2) << literacy_rate << "%" << endl;
    }

    // Getters for literacy rate and population
    float getLiteracyRate() const {
        return literacy_rate;
    }

    long getPopulation() const {
        return population;
    }
};

int main() {
    int n, choice;
    cout << "Enter the number of districts: ";
    cin >> n;

    District* districts = new District[n];  // Dynamic array of District objects

    do {
        cout << "\n--- District Information Menu ---\n";
        cout << "1. Accept details of districts\n";
        cout << "2. Display details of all districts\n";
        cout << "3. Display district with highest literacy rate\n";
        cout << "4. Display district with least population\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter details for District " << i + 1 << ":\n";
                    districts[i].acceptDetails();
                }
                break;
            }

            case 2: {
                cout << "\n" << setw(10) << "Code"
                     << setw(20) << "Name"
                     << setw(15) << "Area (sqft)"
                     << setw(15) << "Population"
                     << setw(15) << "Literacy (%)" << endl;
                cout << "-------------------------------------------------------------------------------" << endl;
                for (int i = 0; i < n; i++) {
                    districts[i].displayDetails();
                }
                break;
            }

            case 3: {
                int index = 0;
                for (int i = 1; i < n; i++) {
                    if (districts[i].getLiteracyRate() > districts[index].getLiteracyRate()) {
                        index = i;
                    }
                }
                cout << "\nDistrict with the Highest Literacy Rate:\n";
                cout << setw(10) << "Code"
                     << setw(20) << "Name"
                     << setw(15) << "Area (sqft)"
                     << setw(15) << "Population"
                     << setw(15) << "Literacy (%)" << endl;
                cout << "-------------------------------------------------------------------------------" << endl;
                districts[index].displayDetails();
                break;
            }

            case 4: {
                int index = 0;
                for (int i = 1; i < n; i++) {
                    if (districts[i].getPopulation() < districts[index].getPopulation()) {
                        index = i;
                    }
                }
                cout << "\nDistrict with the Least Population:\n";
                cout << setw(10) << "Code"
                     << setw(20) << "Name"
                     << setw(15) << "Area (sqft)"
                     << setw(15) << "Population"
                     << setw(15) << "Literacy (%)" << endl;
                cout << "-------------------------------------------------------------------------------" << endl;
                districts[index].displayDetails();
                break;
            }

            case 5:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    delete[] districts;  // Free dynamically allocated memory
    return 0;
}
