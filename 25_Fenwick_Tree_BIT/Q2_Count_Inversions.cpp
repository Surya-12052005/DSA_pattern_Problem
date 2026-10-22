/*
    Problem   : Count Inversions in an Array
    Difficulty: Medium
    Topic     : Fenwick Tree (BIT)

    Given an array, count the number of inversions: pairs (i, j)
    such that i < j and arr[i] > arr[j].

    Example:
    Input : arr = [8,4,2,1]
    Output: 6   (every pair is an inversion)

    Approach:
    - Coordinate-compress the array values to range [1, n].
    - Traverse from right to left; for each element, query the BIT
      for the count of numbers smaller than it seen so far (to its right),
      then update the BIT to include the current element.
    - Sum all such counts to get the total inversions.

    Time Complexity : O(n log n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
public:
    vector<int> bit;
    int n;
    FenwickTree(int size) { n = size; bit.assign(n + 1, 0); }

    void update(int i, int delta) {
        for (++i; i <= n; i += i & (-i)) bit[i] += delta;
    }
    int prefixSum(int i) {
        int sum = 0;
        for (; i > 0; i -= i & (-i)) sum += bit[i];
        return sum;
    }
};

long long countInversions(vector<int>& arr) {
    int n = arr.size();
    vector<int> sorted_vals(arr.begin(), arr.end());
    sort(sorted_vals.begin(), sorted_vals.end());
    sorted_vals.erase(unique(sorted_vals.begin(), sorted_vals.end()), sorted_vals.end());

    auto getRank = [&](int val) {
        return lower_bound(sorted_vals.begin(), sorted_vals.end(), val) - sorted_vals.begin();
    };

    FenwickTree ft(sorted_vals.size());
    long long inversions = 0;

    for (int i = n - 1; i >= 0; i--) {
        int rank = getRank(arr[i]);
        inversions += ft.prefixSum(rank); // count of smaller elements to the right
        ft.update(rank, 1);
    }
    return inversions;
}

int main() {
    vector<int> arr = {8,4,2,1};
    cout << "Inversions: " << countInversions(arr) << endl; // 6
    return 0;
}
