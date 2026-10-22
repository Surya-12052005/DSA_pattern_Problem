/*
    Problem   : Search in Rotated Sorted Array
    Difficulty: Medium
    Topic     : Binary Search

    Given a rotated sorted array "nums" with distinct values and a
    target, return the index of target, or -1 if not found.

    Example:
    Input : nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

    Approach:
    - Standard binary search, but at each step determine which half
      (left or right of mid) is sorted.
    - Check if target lies within the sorted half's range;
      if yes, search that half, otherwise search the other half.

    Time Complexity : O(log n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;

        if (nums[lo] <= nums[mid]) { // left half sorted
            if (nums[lo] <= target && target < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else { // right half sorted
            if (nums[mid] < target && target <= nums[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << "Index: " << search(nums, 0) << endl;
    return 0;
}
