/*
    Problem   : Counting Bits
    Difficulty: Easy
    Topic     : Bit Manipulation + DP

    Given an integer n, return an array ans of length n+1 such that
    ans[i] is the number of 1's (set bits) in the binary representation of i.

    Example:
    Input : n = 5
    Output: [0,1,1,2,1,2]

    Approach:
    - DP relation: ans[i] = ans[i >> 1] + (i & 1).
    - i >> 1 removes the last bit; (i & 1) checks if the removed
      bit was 1. This builds on previously computed results.

    Time Complexity : O(n)
    Space Complexity: O(n) for output
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;
}

int main() {
    int n = 5;
    vector<int> res = countBits(n);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
