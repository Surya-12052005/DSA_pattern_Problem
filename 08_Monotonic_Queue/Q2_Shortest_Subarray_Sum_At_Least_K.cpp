/*
    Problem   : Shortest Subarray with Sum at Least K
    Difficulty: Hard
    Topic     : Monotonic Queue + Prefix Sum

    Given an array "nums" (can contain negatives) and integer k,
    return the length of the shortest subarray with sum >= k.
    Return -1 if no such subarray exists.

    Example:
    Input : nums = [2,-1,2], k = 3
    Output: 3

    Approach:
    - Compute prefix sums.
    - Use a monotonic increasing deque of indices (by prefix value).
    - For each prefix[i], while prefix[i] - prefix[front] >= k, update
      answer and pop from front (since a shorter subarray won't beat this).
    - While prefix[i] <= prefix[back], pop from back (keeps deque increasing;
      a later smaller prefix is always more useful).

    Time Complexity : O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

    deque<int> dq; // indices into prefix[], increasing prefix value
    int best = INT_MAX;

    for (int i = 0; i <= n; i++) {
        while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
            best = min(best, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && prefix[i] <= prefix[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    return best == INT_MAX ? -1 : best;
}

int main() {
    vector<int> nums = {2,-1,2};
    int k = 3;
    cout << "Shortest length: " << shortestSubarray(nums, k) << endl;
    return 0;
}
