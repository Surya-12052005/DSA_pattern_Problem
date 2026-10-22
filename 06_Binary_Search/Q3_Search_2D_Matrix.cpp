/*
    Problem   : Search a 2D Matrix
    Difficulty: Medium
    Topic     : Binary Search

    Given an m x n matrix where each row is sorted and the first
    element of each row is greater than the last element of the
    previous row, determine if a target value exists.

    Example:
    Input : matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

    Approach:
    - Treat the matrix as a single sorted array of size m*n.
    - Map mid index to (row, col) using division/modulo.
    - Standard binary search.

    Time Complexity : O(log(m*n))
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int lo = 0, hi = m * n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int val = matrix[mid / n][mid % n];
        if (val == target) return true;
        else if (val < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout << (searchMatrix(matrix, 3) ? "true" : "false") << endl;
    return 0;
}
