#include <iostream>
using namespace std;

int main() {
    int rows=4;
    int count=1;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            cout << " ";
        }
        for (int k = 1; k <= i; k++) {
            cout << count;
            count++;
        }
        cout << endl;
      
    }

    return 0;
}
