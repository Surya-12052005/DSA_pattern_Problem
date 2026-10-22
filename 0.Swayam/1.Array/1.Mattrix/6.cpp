/*1. Problem Statement :leetcode problem 48:

You are given an n×n 2D matrix representing an image. Rotate the image 90 degrees clockwise.
You must rotate the image in place, which means you must modify the original matrix directly instead of creating another 2D matrix for the result.

Conditions:

1.The matrix has the same number of rows and columns.
2.Rotate the matrix by 90 degrees clockwise.
3.Modify the original matrix without using another n×n matrix.

2. Example

Input

3
1 2 3
4 5 6
7 8 9

Output

7 4 1
8 5 2
9 6 3*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);     
        }
    }

    // Step 2: Reverse every row
    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    rotate(matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}