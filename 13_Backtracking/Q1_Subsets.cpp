/*
    Problem   : Subsets (Power Set)
    Difficulty: Medium
    Topic     : Backtracking

    Given an array of unique integers "nums", return all possible
    subsets (the power set).

    Example:
    Input : nums = [1,2,3]
    Output: [[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]]

    Approach:
    - Backtracking: at each index, we have 2 choices - include the
      element or exclude it.
    - Add the current subset to result at every recursive call,
      then try including next elements one by one.

    Time Complexity : O(2^n)
    Space Complexity: O(n) recursion stack (excluding output)
*/

#include <bits/stdc++.h>
using namespace std;

void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);
    for (int i = start; i < (int)nums.size(); i++) {
        current.push_back(nums[i]);
        backtrack(i + 1, nums, current, result);
        current.pop_back(); // undo choice
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(0, nums, current, result);
    return result;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = subsets(nums);
    for (auto& s : res) {
        cout << "[ ";
        for (int x : s) cout << x << " ";
        cout << "]" << endl;
    }
    return 0;
}
