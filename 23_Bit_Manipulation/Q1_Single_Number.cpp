/*
    Problem   : Single Number
    Difficulty: Easy
    Topic     : Bit Manipulation

    Given a non-empty array of integers where every element appears
    twice except for one, find that single one.

    Example:
    Input : nums = [4,1,2,1,2]
    Output: 4

    Approach:
    - Use XOR. XOR of a number with itself is 0, and XOR with 0 leaves
      the number unchanged.
    - XOR-ing all elements together cancels out pairs, leaving only
      the single unique number.

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int num : nums) result ^= num;
    return result;
}

int main() {
    vector<int> nums = {4,1,2,1,2};
    cout << "Single Number: " << singleNumber(nums) << endl;
    return 0;
}
