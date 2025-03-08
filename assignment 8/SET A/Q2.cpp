#include <iostream>
using namespace std;

// Base Class: Media
class Media {
protected:
    int id;
    string title;
public:
    Media(int i, string t) : id(i), title(t) {}
    virtual void display() = 0; // Pure virtual function
    virtual ~Media() {} // Virtual destructor
};

// Derived Class: Book
class Book : public Media {
    string ISBN;
public:
    Book(int i, string t, string isbn) : Media(i, t), ISBN(isbn) {}
    void display() override {
        cout << "Book | ID: " << id << " | Title: " << title << " | ISBN: " << ISBN << endl;
    }
};

// Derived Class: CD
class CD : public Media {
    double capacity; // in GB
public:
    CD(int i, string t, double c) : Media(i, t), capacity(c) {}
    void display() override {
        cout << "CD | ID: " << id << " | Title: " << title << " | Capacity: " << capacity << " GB" << endl;
    }
};

// Main Function
int main() {
    Media* items[10]; // Array of pointers
    int choice, id;
    string title, isbn;
    double capacity;

    // Input for 10 items
    for (int i = 0; i < 10; i++) {
        cout << "\nEnter 1 for Book, 2 for CD: ";
        cin >> choice;
        cout << "Enter ID and Title: ";
        cin >> id >> ws;
        getline(cin, title);

        if (choice == 1) {
            cout << "Enter ISBN: ";
            cin >> isbn;
            items[i] = new Book(id, title, isbn);
        } else {
            cout << "Enter Data Capacity (GB): ";
            cin >> capacity;
            items[i] = new CD(id, title, capacity);
        }
    }

    // Display all items
    cout << "\nPurchased Media Items:\n";
    for (int i = 0; i < 10; i++) {
        items[i]->display();
        delete items[i]; // Free memory
    }

    return 0;
}
