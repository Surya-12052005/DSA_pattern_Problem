/*
    Problem   : Power of Two
    Difficulty: Easy
    Topic     : Bit Manipulation

    Given an integer n, return true if it is a power of two.

    Example:
    Input : n = 16
    Output: true

    Approach:
    - A power of two has exactly one bit set in its binary
      representation (e.g., 16 = 10000).
    - n & (n-1) clears the lowest set bit. If n is a power of two,
      this operation results in 0.
    - Also need n > 0, since 0 and negative numbers can't be powers of two.

    Time Complexity : O(1)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n - 1)) == 0;
}

int main() {
    cout << (isPowerOfTwo(16) ? "true" : "false") << endl; // true
    cout << (isPowerOfTwo(18) ? "true" : "false") << endl; // false
    return 0;
}
