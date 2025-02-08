#include <iostream>

using namespace std;

int main() {
    int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    
    cout << "Original Array" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Rotate Matrix by 90 degrees" << endl;
    for (int i = 0; i < 3; i++) {
         for (int j = 2; j >= 0; j--) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
