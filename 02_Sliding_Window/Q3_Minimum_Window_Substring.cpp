/*
    Problem   : Minimum Window Substring
    Difficulty: Hard (very common in campus placements)
    Topic     : Sliding Window

    Given strings s and t, return the smallest substring of s that
    contains all characters of t (including duplicates). If no such
    substring exists, return "".

    Example:
    Input : s = "ADOBECODEBANC", t = "ABC"
    Output: "BANC"

    Approach:
    - Store frequency of characters needed from t in a map.
    - Expand right pointer, decreasing the "need" count.
    - When all characters are satisfied (formed == required),
      try shrinking from left to minimize window, updating best answer.

    Time Complexity : O(|s| + |t|)
    Space Complexity: O(|t|)
*/

#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";
    unordered_map<char, int> need;
    for (char c : t) need[c]++;

    int required = need.size();
    int formed = 0;
    unordered_map<char, int> windowCounts;

    int left = 0, bestLen = INT_MAX, bestLeft = 0;
    for (int right = 0; right < (int)s.size(); right++) {
        char c = s[right];
        windowCounts[c]++;
        if (need.count(c) && windowCounts[c] == need[c]) formed++;

        while (formed == required) {
            if (right - left + 1 < bestLen) {
                bestLen = right - left + 1;
                bestLeft = left;
            }
            char lc = s[left];
            windowCounts[lc]--;
            if (need.count(lc) && windowCounts[lc] < need[lc]) formed--;
            left++;
        }
    }
    return bestLen == INT_MAX ? "" : s.substr(bestLeft, bestLen);
}

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << "Min window: " << minWindow(s, t) << endl;
    return 0;
}
