/*
    Problem   : Permutations
    Difficulty: Medium
    Topic     : Backtracking

    Given an array of distinct integers "nums", return all possible
    permutations.

    Example:
    Input : nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

    Approach:
    - Use a "used" boolean array to track which elements are placed.
    - At each recursion, try placing every unused element next,
      mark it used, recurse, then unmark (backtrack).
    - When current permutation size == n, add to result.

    Time Complexity : O(n * n!)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < (int)nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        current.push_back(nums[i]);
        backtrack(nums, current, used, result);
        current.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    backtrack(nums, current, used, result);
    return result;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = permute(nums);
    for (auto& p : res) {
        for (int x : p) cout << x << " ";
        cout << endl;
    }
    return 0;
}
