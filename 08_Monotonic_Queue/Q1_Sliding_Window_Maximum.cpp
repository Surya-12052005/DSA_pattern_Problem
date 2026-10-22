/*
    Problem   : Sliding Window Maximum
    Difficulty: Hard (very common in interviews)
    Topic     : Monotonic Queue

    Given an array "nums" and a window size k, return the maximum
    value in each window as it slides from left to right.

    Example:
    Input : nums = [1,3,-1,-3,5,3,6,7], k = 3
    Output: [3,3,5,5,6,7]

    Approach:
    - Use a deque storing indices, keeping values in decreasing order.
    - Remove indices from back while their value < current value.
    - Remove front index if it's out of the current window.
    - Front of deque is always the max of the current window.

    Time Complexity : O(n)
    Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // stores indices
    vector<int> result;

    for (int i = 0; i < (int)nums.size(); i++) {
        // remove indices out of window
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();

        // maintain decreasing order
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
