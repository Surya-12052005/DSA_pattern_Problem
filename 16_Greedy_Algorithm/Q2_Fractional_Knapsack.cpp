/*
    Problem   : Fractional Knapsack
    Difficulty: Medium
    Topic     : Greedy Algorithm

    Given weights and values of items and a knapsack capacity W,
    maximize total value in the knapsack. Unlike 0/1 knapsack, you
    can take fractions of an item.

    Example:
    Input : weights = [10,20,30], values = [60,100,120], W = 50
    Output: 240.0

    Approach:
    - Compute value/weight ratio for each item.
    - Sort items by this ratio in descending order.
    - Greedily take as much as possible of the highest ratio item
      first, then move to the next, until capacity is filled.

    Time Complexity : O(n log n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

double fractionalKnapsack(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<pair<double,int>> ratioIdx(n); // {ratio, index}
    for (int i = 0; i < n; i++)
        ratioIdx[i] = {(double)values[i] / weights[i], i};

    sort(ratioIdx.rbegin(), ratioIdx.rend()); // descending by ratio

    double totalValue = 0.0;
    int remaining = W;

    for (auto& [ratio, idx] : ratioIdx) {
        if (remaining <= 0) break;
        int takeWeight = min(remaining, weights[idx]);
        totalValue += takeWeight * ratio;
        remaining -= takeWeight;
    }
    return totalValue;
}

int main() {
    vector<int> weights = {10,20,30};
    vector<int> values = {60,100,120};
    int W = 50;
    cout << "Max value: " << fractionalKnapsack(weights, values, W) << endl;
    return 0;
}
