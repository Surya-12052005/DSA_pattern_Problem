/*
    Problem   : Activity Selection Problem
    Difficulty: Easy
    Topic     : Greedy Algorithm

    Given start and finish times of n activities, select the maximum
    number of activities that can be performed by a single person,
    assuming a person can only work on one activity at a time.

    Example:
    Input : start = [1,3,0,5,8,5], finish = [2,4,6,7,9,9]
    Output: 4

    Approach:
    - Sort activities by finish time.
    - Greedily pick the next activity whose start time is >= the
      finish time of the last picked activity.

    Time Complexity : O(n log n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int activitySelection(vector<int> start, vector<int> finish) {
    int n = start.size();
    vector<pair<int,int>> activities(n);
    for (int i = 0; i < n; i++) activities[i] = {finish[i], start[i]};
    sort(activities.begin(), activities.end()); // sort by finish time

    int count = 1;
    int lastFinish = activities[0].first;
    for (int i = 1; i < n; i++) {
        if (activities[i].second >= lastFinish) {
            count++;
            lastFinish = activities[i].first;
        }
    }
    return count;
}

int main() {
    vector<int> start = {1,3,0,5,8,5};
    vector<int> finish = {2,4,6,7,9,9};
    cout << "Max activities: " << activitySelection(start, finish) << endl;
    return 0;
}
