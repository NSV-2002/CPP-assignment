#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** mat;
public:
    Matrix(int r, int c) : rows(r), cols(c) {
        mat = new int*[rows];
        for (int i = 0; i < rows; i++) {
            mat[i] = new int[cols];
        }
    }
    
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }
    
    void input() {
        cout << "Enter elements of " << rows << "x" << cols << " matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }
    
    void display() const {
        cout << "Matrix:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    Matrix operator+(const Matrix& m) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return result;
    }
    
    Matrix operator*(const Matrix& m) {
        Matrix result(rows, m.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                result.mat[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return result;
    }
    
    bool operator==(const Matrix& m) {
        if (rows != m.rows || cols != m.cols) return false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] != m.mat[i][j]) return false;
            }
        }
        return true;
    }
};

int main() {
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    
    Matrix mat1(r, c), mat2(r, c);
    mat1.input();
    mat2.input();
    
    Matrix sum = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    sum.display();
    
    if (r == c) {
        Matrix product = mat1 * mat2;
        cout << "Product of matrices:" << endl;
        product.display();
    } else {
        cout << "Matrix multiplication not possible due to dimension mismatch." << endl;
    }
    
    if (mat1 == mat2) {
        cout << "Both matrices are equal." << endl;
    } else {
        cout << "Matrices are not equal." << endl;
    }
    
    return 0;
}