/*
Kadane's Algorithm:

Kadane's Algorithm is an efficient algorithm used to find the maximum sum of a contiguous subarray in an array.

At every element, we ask:
Should I continue the current subarray, or should I start a new one?

We maintain two variables:
currSum = current subarray sum
maxSum  = maximum sum found so far

If:

currSum < 0

we reset:

currSum = 0;*/


/*LeetCode 53 — Maximum Subarray
Problem Statement

Given an integer array nums, find the subarray with the largest sum, and return its sum.

A subarray is a contiguous part of the array.

Example 1
Input:
nums = [-2,1,-3,4,-1,2,1,-5,4]

Output:
6
Explanation

The subarray with the maximum sum is:

[4,-1,2,1]

Its sum is:

4 + (-1) + 2 + 1 = 6*/


#include<iostream>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Kadane's Algorithm
int maxSubArray(vector<int>& nums) {

    int maxSum = nums[0];
    int currSum = 0;

    for (int i = 0; i < nums.size(); i++) {

        currSum += nums[i];

        maxSum = max(maxSum, currSum);

        if (currSum < 0) {
            currSum = 0;
        }
    }

    return maxSum;
}

int main() {

    int n;

    // Input size
    cin >> n;

    vector<int> nums(n);

    // Input array
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Call function
    int ans = maxSubArray(nums);

    // Print answer
    cout << "Maximum Subarray Sum = " << ans << endl;

    return 0;
}