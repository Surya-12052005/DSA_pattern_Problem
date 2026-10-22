/*
    Problem   : 0/1 Knapsack
    Difficulty: Medium
    Topic     : Dynamic Programming

    Given weights and values of n items and a knapsack of capacity W,
    find the maximum value that can be put in the knapsack such that
    the total weight is <= W (each item can be used at most once).

    Example:
    Input : weights = [1,3,4,5], values = [1,4,5,7], W = 7
    Output: 9

    Approach:
    - dp[i][w] = max value using first i items with capacity w.
    - For each item, choice: skip it (dp[i-1][w]) or take it
      (values[i-1] + dp[i-1][w-weights[i-1]]) if it fits.
    - Take the max of both choices.

    Time Complexity : O(n * W)
    Space Complexity: O(n * W)  -- can be optimized to O(W)
*/

#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w]; // don't take item i
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> weights = {1,3,4,5};
    vector<int> values = {1,4,5,7};
    int W = 7;
    cout << "Max value: " << knapsack(weights, values, W) << endl;
    return 0;
}
