/*
    Problem   : Corporate Flight Bookings
    Difficulty: Medium
    Topic     : Difference Array

    There are n flights numbered 1..n. bookings[i] = [first, last, seats]
    means "seats" seats were booked for flights first..last (inclusive).
    Return an array "answer" of length n showing total seats booked for
    each flight.

    Example:
    Input : bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
    Output: [10,55,45,25,25]

    Approach:
    - Classic difference array: diff[first-1] += seats, diff[last] -= seats.
    - Prefix sum gives the final booking count per flight.

    Time Complexity : O(n + bookings.size())
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> diff(n + 1, 0);
    for (auto& b : bookings) {
        int first = b[0], last = b[1], seats = b[2];
        diff[first - 1] += seats;
        diff[last] -= seats;
    }
    vector<int> answer(n);
    answer[0] = diff[0];
    for (int i = 1; i < n; i++) answer[i] = answer[i - 1] + diff[i];
    return answer;
}

int main() {
    vector<vector<int>> bookings = {{1,2,10},{2,3,20},{2,5,25}};
    int n = 5;
    vector<int> res = corpFlightBookings(bookings, n);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
