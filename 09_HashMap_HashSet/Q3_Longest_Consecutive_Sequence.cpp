/*
    Problem   : Longest Consecutive Sequence
    Difficulty: Medium
    Topic     : HashSet

    Given an unsorted array of integers, find the length of the
    longest consecutive elements sequence (need not be contiguous
    in the array, but consecutive in value).

    Example:
    Input : nums = [100,4,200,1,3,2]
    Output: 4   (1,2,3,4)

    Approach:
    - Insert all numbers into a hash set.
    - For each number, only start counting a sequence if (num - 1)
      is NOT in the set (i.e., num is the start of a sequence).
    - Count consecutive numbers from that start using the set.

    Time Complexity : O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    int best = 0;

    for (int num : numSet) {
        if (!numSet.count(num - 1)) { // start of a sequence
            int length = 1;
            int current = num;
            while (numSet.count(current + 1)) {
                current++;
                length++;
            }
            best = max(best, length);
        }
    }
    return best;
}

int main() {
    vector<int> nums = {100,4,200,1,3,2};
    cout << "Longest Consecutive: " << longestConsecutive(nums) << endl;
    return 0;
}
