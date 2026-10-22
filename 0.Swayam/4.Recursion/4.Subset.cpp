
/*
Problem: Subsets (LeetCode 78)

Approach: Recursion + Backtracking

Given an array of distinct integers, print all possible subsets.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& temp, vector<vector<int>>& ans) {

        // Base case
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Include current element
        temp.push_back(nums[index]);
        solve(nums, index + 1, temp, ans);

        // Backtrack: remove current element
        temp.pop_back();

        // Exclude current element
        solve(nums, index + 1, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {vector<vector<int>> ans;vector<int> temp;

        solve(nums, 0, temp, ans);

        return ans;
    }
};

int main() {
    int n;

    // Take input from user
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Create object
    Solution obj;

    // Find all subsets
    vector<vector<int>> ans = obj.subsets(nums);

    // Print all subsets
    cout << "\nAll possible subsets:\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << "{ ";

        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }

        cout << "}" << endl;
    }

    return 0;
}

