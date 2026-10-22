/*
    Problem   : Climbing Stairs
    Difficulty: Easy
    Topic     : Dynamic Programming

    You are climbing a staircase with n steps. Each time you can climb
    1 or 2 steps. In how many distinct ways can you climb to the top?

    Example:
    Input : n = 5
    Output: 8

    Approach:
    - This is Fibonacci in disguise: ways(n) = ways(n-1) + ways(n-2).
    - Use bottom-up DP with O(1) space (only need last two values).

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    if (n <= 2) return n;
    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    int n = 5;
    cout << "Ways: " << climbStairs(n) << endl;
    return 0;
}
