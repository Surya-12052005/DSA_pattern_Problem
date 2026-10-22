#include <iostream>
using namespace std;
#include <vector>


// 1.TWO POINTER:
// LeetCode 11 — Container With Most Water
/*/*LeetCode 11 — Container With Most Water
Problem Statement

You are given an integer array height of length n.

There are n vertical lines such that the two endpoints of the i-th line are at:

(i, 0) and (i, height[i])

Choose two lines that, together with the x-axis, form a container that holds the most water.

Return the maximum amount of water that the container can store.

Important

You cannot slant the container.

Example 1

Input:

height = [1,8,6,2,5,4,8,3,7]

Output:

49*/

int maxArea(vector<int> &height)
{
    int L = 0;
    int R = height.size() - 1;
    int maxArea = 0;
    int currArea = 0;

    while (L < R)
    {
        currArea = (R - L) * min(height[L], height[R]);
        maxArea = max(maxArea, currArea);
        if (height[L] < height[R])
            L++;
        else
            R--;
    }
    return maxArea;
}


// 2. SLIDING WINDOW:
// leetcode : 713. Subarray Product Less Than K.

/*/*
SLIDING WINDOW:

leetcode : 713. Subarray Product Less Than K.
You are given an array of integers nums and an integer k.
Return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.*/

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int n = nums.size(), count = 0;
    for (int i = 0; i < n; i++)
    {
        int prod = 1; // reset for each start index
        for (int j = i; j < n; j++)
        {
            prod *= nums[j];
            if (prod >= k)
                break; // check BEFORE counting
            count++;
        }
    }
    return count;
}



/* 3.Kadane's Algorithm — Quick Revision

Remember:

1. Add current element
2. Update maximum
3. If current sum < 0 → reset

In code:

currSum += nums[i];

maxSum = max(maxSum, currSum);

if (currSum < 0)
    currSum = 0;
Pattern

Maximum Sum + Contiguous Subarray → Think Kadane's Algorithm*/

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

int main()
{
}