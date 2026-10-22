/*
    Print all the diagonal elements of a 4*4 Matrix
*/

#include <iostream>
using namespace std;

class Matrix {
public:

    int mat[4][4];

    // Function to input matrix
    void input() {

        cout << "Enter elements of 4x4 matrix:\n";

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {  
                cin >> mat[i][j];
            }
        }
    }

    // Function to print matrix
    void display() {

        cout << "\nMatrix:\n";

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << mat[i][j] << " ";
            }

            cout << endl;
        }
    }
    // Main diagonal (top-left to bottom-right): row index == col index
    // Function to print main diagonal
    void mainDiagonal() {

        cout << "\nMain Diagonal elements: ";

        for (int i = 0; i < 4; i++) {
            cout << mat[i][i] << " ";
        }

        cout << endl;
    }
    //Anti-diagonal (top-right to bottom-left): col index = n - 1 - row index
    // Function to print anti-diagonal
    void antiDiagonal() {

        cout << "Anti-Diagonal elements: ";

        for (int i = 0; i < 4; i++) {
            cout << mat[i][3 - i] << " ";
        }

        cout << endl;
    }
};

int main() {

    // Create object
    Matrix obj;

    // Call functions using object
    obj.input();

    obj.display();

    obj.mainDiagonal();

    obj.antiDiagonal();

    return 0;
}