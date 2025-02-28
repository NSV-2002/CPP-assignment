#include <iostream>
#include <algorithm>
using namespace std;

class Array {
private:
    int* arr;
    int size;

public:
    // Dynamic Constructor
    Array(int n) {
        size = n;
        arr = new int[size];
        cout << "Enter " << size << " elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    // Member function to display median
    void displayMedian() {
        sort(arr, arr + size);
        double median;
        if (size % 2 == 0)
            median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
        else
            median = arr[size / 2];
        
        cout << "Median of the array is: " << median << endl;
    }

    // Destructor to free allocated memory
    ~Array() {
        delete[] arr;
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    Array obj(n);
    obj.displayMedian();

    return 0;
}
