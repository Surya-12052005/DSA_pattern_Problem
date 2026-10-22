/*
    Problem   : Range Sum Query - Immutable
    Difficulty: Easy
    Topic     : Prefix Sum

    Given an array "nums", answer multiple queries of the form:
    sum of elements between indices left and right (inclusive).

    Example:
    Input : nums = [-2,0,3,-5,2,-1], query(0,2), query(2,5)
    Output: 1, -1

    Approach:
    - Precompute prefix[i] = sum of nums[0..i-1].
    - Answer for range [l, r] = prefix[r+1] - prefix[l].

    Time Complexity : O(n) build, O(1) per query
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);
        for (int i = 0; i < (int)nums.size(); i++)
            prefix[i + 1] = prefix[i] + nums[i];
    }
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};

int main() {
    vector<int> nums = {-2,0,3,-5,2,-1};
    NumArray obj(nums);
    cout << obj.sumRange(0, 2) << endl; // 1
    cout << obj.sumRange(2, 5) << endl; // -1
    return 0;
}
