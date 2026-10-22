/*
    Problem   : Two Sum
    Difficulty: Easy (most asked interview question)
    Topic     : HashMap

    Given an array of integers "nums" and a target, return indices of
    the two numbers such that they add up to target.

    Example:
    Input : nums = [2,7,11,15], target = 9
    Output: [0,1]

    Approach:
    - Use a hashmap to store value -> index as we iterate.
    - For each element, check if (target - element) already exists in map.

    Time Complexity : O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen; // value -> index
    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.count(complement)) return {seen[complement], i};
        seen[nums[i]] = i;
    }
    return {-1, -1};
}

int main() {
    vector<int> nums = {2,7,11,15};
    vector<int> res = twoSum(nums, 9);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
