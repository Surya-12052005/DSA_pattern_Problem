/*
    Problem   : Range Update Queries (Add value to a range)
    Difficulty: Easy
    Topic     : Difference Array

    Given an array of size n (initially zero) and a list of updates
    [l, r, val], add "val" to every element from index l to r for
    each update. Return the final array.

    Example:
    Input : n = 5, updates = [[1,3,2],[2,4,3]]
    Output: [0,2,5,5,3]

    Approach:
    - Create a difference array diff[] of size n+1, initialized to 0.
    - For update (l, r, val): diff[l] += val, diff[r+1] -= val.
    - Take prefix sum of diff[] to get the final array.

    Time Complexity : O(n + q)  where q = number of updates
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> rangeUpdates(int n, vector<vector<int>>& updates) {
    vector<int> diff(n + 1, 0);
    for (auto& u : updates) {
        int l = u[0], r = u[1], val = u[2];
        diff[l] += val;
        if (r + 1 < n) diff[r + 1] -= val;
    }
    vector<int> result(n);
    result[0] = diff[0];
    for (int i = 1; i < n; i++) result[i] = result[i - 1] + diff[i];
    return result;
}

int main() {
    int n = 5;
    vector<vector<int>> updates = {{1,3,2},{2,4,3}};
    vector<int> res = rangeUpdates(n, updates);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
