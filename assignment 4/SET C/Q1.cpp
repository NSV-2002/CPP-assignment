#include <iostream>
#include <cstring>
using namespace std;

class Bookshop {
private:
    char* author;
    char* title;
    char* publisher;
    float price;
    int stock;

public:
    // Dynamic Constructor
    Bookshop(const char* auth, const char* t, const char* pub, float p, int s) {
        author = new char[strlen(auth) + 1];
        strcpy(author, auth);
        
        title = new char[strlen(t) + 1];
        strcpy(title, t);
        
        publisher = new char[strlen(pub) + 1];
        strcpy(publisher, pub);
        
        price = p;
        stock = s;
    }

    // Function to check and sell books
    void sellBook(const char* t, int copies) {
        if (strcmp(title, t) == 0) {
            if (copies <= stock) {
                float totalCost = price * copies;
                stock -= copies;
                cout << "Total cost: " << totalCost << endl;
            } else {
                cout << "Required copies not in stock" << endl;
            }
        } else {
            cout << "Book not found" << endl;
        }
    }

    // Function to display book details
    void display() {
        cout << "Author: " << author << "\nTitle: " << title << "\nPublisher: " << publisher << "\nPrice: " << price << "\nStock: " << stock << endl;
    }

    // Destructor to free memory
    ~Bookshop() {
        delete[] author;
        delete[] title;
        delete[] publisher;
        cout << "Memory deallocated successfully." << endl;
    }
};

int main() {
    Bookshop book("J.K. Rowling", "Harry Potter", "Bloomsbury", 39.99, 10);
    book.display();
    
    char title[100];
    int copies;
    cout << "\nEnter title to purchase: ";
    cin >> title;
    cout << "Enter number of copies: ";
    cin >> copies;
    
    book.sellBook(title, copies);
    return 0;
}