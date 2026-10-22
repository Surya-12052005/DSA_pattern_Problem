/*
    Problem   : Car Pooling
    Difficulty: Medium
    Topic     : Difference Array

    A car has "capacity" seats. Given trips[i] = [numPassengers, from, to],
    determine if it is possible to pick up and drop off all passengers
    without exceeding capacity at any point.

    Example:
    Input : trips = [[2,1,5],[3,3,7]], capacity = 4
    Output: false

    Approach:
    - Use a difference array over the road (max location ~1000).
    - For each trip, add numPassengers at "from" and subtract at "to".
    - Take prefix sum; if at any point it exceeds capacity, return false.

    Time Complexity : O(n + maxLocation)
    Space Complexity: O(maxLocation)
*/

#include <bits/stdc++.h>
using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> diff(1001, 0);
    for (auto& t : trips) {
        int passengers = t[0], from = t[1], to = t[2];
        diff[from] += passengers;
        diff[to] -= passengers;
    }
    int current = 0;
    for (int i = 0; i <= 1000; i++) {
        current += diff[i];
        if (current > capacity) return false;
    }
    return true;
}

int main() {
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    int capacity = 4;
    cout << (carPooling(trips, capacity) ? "true" : "false") << endl;
    return 0;
}
