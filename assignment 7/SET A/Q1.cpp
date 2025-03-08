#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Base class
class Product {
protected:
    int Product_Id;
    string Product_Name;
    double Price;

public:
    Product(int id, string name, double price) 
        : Product_Id(id), Product_Name(name), Price(price) {}

    virtual void display() const {
        cout << left << setw(10) << Product_Id
             << setw(15) << Product_Name
             << setw(10) << fixed << setprecision(2) << Price;
    }

    double getPrice() const { return Price; }
};

// Derived class
class Discount : public Product {
private:
    double Discount_In_Percentage;

public:
    Discount(int id, string name, double price, double discount)
        : Product(id, name, price), Discount_In_Percentage(discount) {}

    double getDiscountAmount() const {
        return (Price * Discount_In_Percentage) / 100;
    }

    double getFinalPrice() const {
        return Price - getDiscountAmount();
    }

    void display() const override {
        Product::display();
        cout << setw(10) << Discount_In_Percentage << "%" 
             << setw(10) << fixed << setprecision(2) << getFinalPrice() << endl;
    }
};

// Function to calculate and display bill
void displayBill(const vector<Discount>& products) {
    double totalPrice = 0, totalDiscount = 0;
    
    cout << "\nBILL SUMMARY:\n";
    cout << left << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Discount"
         << setw(10) << "Final Price" << endl;
    cout << string(55, '-') << endl;

    for (const auto& product : products) {
        product.display();
        totalPrice += product.getFinalPrice();
        totalDiscount += product.getDiscountAmount();
    }

    cout << string(55, '-') << endl;
    cout << left << setw(25) << "Total Discount:" << setw(10) << fixed << setprecision(2) << totalDiscount << endl;
    cout << left << setw(25) << "Total Price after Discount:" << setw(10) << fixed << setprecision(2) << totalPrice << endl;
}

int main() {
    vector<Discount> products;
    int n, id;
    string name;
    double price, discount;

    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for product " << i + 1 << ":\n";
        cout << "Product ID: ";
        cin >> id;
        cout << "Product Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Price: ";
        cin >> price;
        cout << "Discount (%): ";
        cin >> discount;

        products.emplace_back(id, name, price, discount);
    }

    displayBill(products);
    return 0;
}
