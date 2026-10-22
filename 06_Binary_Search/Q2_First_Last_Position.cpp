/*
    Problem   : Find First and Last Position of Element in Sorted Array
    Difficulty: Medium
    Topic     : Binary Search

    Given a sorted array "nums" and a target, find the starting and
    ending position of the target. Return [-1,-1] if not found.

    Example:
    Input : nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

    Approach:
    - Use binary search twice: once to find the leftmost occurrence,
      once to find the rightmost occurrence.
    - lowerBound finds first index >= target.
    - upperBound finds first index > target, subtract 1 for last occurrence.

    Time Complexity : O(log n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int first = lowerBound(nums, target);
    if (first == (int)nums.size() || nums[first] != target) return {-1, -1};
    int last = lowerBound(nums, target + 1) - 1;
    return {first, last};
}

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> res = searchRange(nums, 8);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
