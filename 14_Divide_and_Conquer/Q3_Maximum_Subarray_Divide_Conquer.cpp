/*
    Problem   : Maximum Subarray Sum (Divide and Conquer approach)
    Difficulty: Medium
    Topic     : Divide and Conquer

    Given an integer array "nums", find the contiguous subarray with
    the largest sum, and return that sum. (Note: Kadane's algorithm,
    an O(n) DP/Greedy solution, also exists - this file demonstrates
    the classic D&C approach.)

    Example:
    Input : nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6   (subarray [4,-1,2,1])

    Approach:
    - Divide the array into left half and right half.
    - The max subarray is either:
        1. entirely in the left half,
        2. entirely in the right half, or
        3. crossing the middle.
    - Recursively solve left and right; compute crossing sum by
      expanding outward from mid.

    Time Complexity : O(n log n)
    Space Complexity: O(log n) recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(vector<int>& nums, int left, int mid, int right) {
    int leftSum = INT_MIN, sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += nums[i];
        leftSum = max(leftSum, sum);
    }
    int rightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += nums[i];
        rightSum = max(rightSum, sum);
    }
    return leftSum + rightSum;
}

int maxSubArrayDC(vector<int>& nums, int left, int right) {
    if (left == right) return nums[left];
    int mid = left + (right - left) / 2;
    int leftMax = maxSubArrayDC(nums, left, mid);
    int rightMax = maxSubArrayDC(nums, mid + 1, right);
    int crossMax = maxCrossingSum(nums, left, mid, right);
    return max({leftMax, rightMax, crossMax});
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Max Subarray Sum: " << maxSubArrayDC(nums, 0, nums.size() - 1) << endl;
    return 0;
}
