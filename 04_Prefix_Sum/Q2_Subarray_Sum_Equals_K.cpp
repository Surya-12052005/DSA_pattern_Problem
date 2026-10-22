/*
    Problem   : Subarray Sum Equals K
    Difficulty: Medium
    Topic     : Prefix Sum + HashMap

    Given an array of integers "nums" and an integer k, return the total
    number of contiguous subarrays whose sum equals k.

    Example:
    Input : nums = [1,1,1], k = 2
    Output: 2

    Approach:
    - Maintain running prefix sum and a hashmap of (prefixSum -> count).
    - For current prefix sum S, if (S - k) has appeared "cnt" times before,
      it means there are "cnt" subarrays ending here with sum k.
    - Add current prefix sum to the map.

    Time Complexity : O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCount;
    prefixCount[0] = 1; // empty prefix
    int sum = 0, count = 0;
    for (int num : nums) {
        sum += num;
        if (prefixCount.count(sum - k))
            count += prefixCount[sum - k];
        prefixCount[sum]++;
    }
    return count;
}

int main() {
    vector<int> nums = {1,1,1};
    int k = 2;
    cout << "Count: " << subarraySum(nums, k) << endl;
    return 0;
}
