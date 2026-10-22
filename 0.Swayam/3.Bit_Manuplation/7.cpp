/*
1. Problem statement
Question: Single Number
Given a non-empty integer array nums, every element appears twice except for one element, which appears exactly once. Find and return that single element.
Your solution must have:
- Time complexity: \(O(n)\)
- Extra space complexity: \(O(1)\)
Examples
Example 1
Input:  nums = [2, 2, 1]
Output: 1
*/

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;

    for (int num : nums) {
        result =result^num;
    }

    return result;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};

    cout << "Single number: "
         << singleNumber(nums) << endl;

    return 0;
}
/*
2. Understand the XOR trick
XOR has three important properties:
Operation	Result
a ^ a	0
a ^ 0	a
a ^ b ^ a	b
The key idea: Every number that appears twice cancels itself out because a ^ a = 0. The number that appears once remains.
3. Dry run: nums = [4, 1, 2, 1, 2]
Initially, result = 0.

Step	Current number	XOR operation	Result
1	4	0 ^ 4	4
2	1	4 ^ 1	5
3	2	5 ^ 2	7
4	1	7 ^ 1	6
5	2	6 ^ 2	4
Final answer: 4
Notice that the two 1s and the two 2s cancel each other, leaving 4.*/