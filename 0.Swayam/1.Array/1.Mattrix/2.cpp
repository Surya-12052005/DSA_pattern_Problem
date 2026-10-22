/* Print all the diagonal elements of a 4*4 Mattrix. */

#include <iostream>
using namespace std;

int main() {
    int mat[4][4];

    // Input the matrix
    cout << "Enter elements of 4x4 matrix:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> mat[i][j];
        }
    }

    // Print the matrix (optional, for reference)
    cout << "\nMatrix:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    // Main diagonal (top-left to bottom-right): row index == col index
    cout << "\nMain Diagonal elements: ";
    for (int i = 0; i < 4; i++) {
        cout << mat[i][i] << " ";
    }
    cout << endl;

    // Anti-diagonal (top-right to bottom-left): col index = n - 1 - row index
    cout << "Anti-Diagonal elements: ";
    for (int i = 0; i < 4; i++) {
        cout << mat[i][3 - i] << " ";
    }
    cout << endl;

    return 0;
}