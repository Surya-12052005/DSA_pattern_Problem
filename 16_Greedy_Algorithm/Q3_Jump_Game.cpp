/*
    Problem   : Jump Game
    Difficulty: Medium
    Topic     : Greedy Algorithm

    Given an array "nums" where nums[i] is the max jump length from
    index i, determine if you can reach the last index starting from index 0.

    Example:
    Input : nums = [2,3,1,1,4]
    Output: true

    Approach:
    - Keep track of the farthest index reachable so far.
    - Traverse the array; if current index > farthest reachable,
      it's impossible to proceed further.
    - Otherwise update farthest = max(farthest, i + nums[i]).

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int farthest = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (i > farthest) return false; // can't reach this index
        farthest = max(farthest, i + nums[i]);
    }
    return true;
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    cout << (canJump(nums) ? "true" : "false") << endl;
    return 0;
}
