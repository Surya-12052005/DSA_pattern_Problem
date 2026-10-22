/*givn a 4*4 mattrix , print the elements in sprial form*/     
/*Example

Input:

1   2   3   4
5   6   7   8
9  10  11  12
13 14  15  16

Spiral output:

1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10       */                            

#include <iostream>
using namespace std;

class Matrix {                                           
public:

    int mat[4][4];                                              

    void input() {

        cout << "Enter 4x4 matrix:\n";

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {                                                              
                cin >> mat[i][j];
            }
        }
    }

    void spiral() {

        int top = 0;
        int bottom = 3;
        int left = 0;
        int right = 3;

        while (top <= bottom && left <= right) {

            // 1. Left to Right
            for (int j = left; j <= right; j++) {
                cout << mat[top][j] << " ";
            }
            top++;             // Ak step aage ka sochkar kro          

            // 2. Top to Bottom
            for (int i = top; i <= bottom; i++) {
                cout << mat[i][right] << " ";
            }
            right--;           // Ak step aage ka sochkar kro

            // 3. Right to Left
            for (int j = right; j >= left; j--) {
                cout << mat[bottom][j] << " ";
            }
            bottom--;           // Ak step aage ka sochkar kro

            // 4. Bottom to Top
            for (int i = bottom; i >= top; i--) {
                cout << mat[i][left] << " ";
            }
            left++;             // Ak step aage ka sochkar kro
        }
    }
};

int main() {

    // Create object
    Matrix obj;

    // Input matrix
    obj.input();

    cout << "\nSpiral form: ";

    // Call spiral function
    obj.spiral();

    return 0;
}