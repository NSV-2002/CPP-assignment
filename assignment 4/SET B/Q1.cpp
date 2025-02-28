#include <iostream>
using namespace std;

class Matrix {
private:
    int** mat;
    int rows, cols;

public:
    // Dynamic Constructor to allocate memory
    Matrix(int m, int n) {
        rows = m;
        cols = n;
        mat = new int*[rows];
        for (int i = 0; i < rows; i++) {
            mat[i] = new int[cols];
        }

        cout << "Enter elements of the matrix: " << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }

    // Function to display the transpose of the matrix
    void displayTranspose() {
        cout << "Transpose of the matrix: " << endl;
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor to deallocate memory
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] mat[i];
        }
        delete[] mat;
        cout << "Memory deallocated successfully." << endl;
    }
};

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    Matrix obj(m, n);
    obj.displayTranspose();
    
    return 0;
}