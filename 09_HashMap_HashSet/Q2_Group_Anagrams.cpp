/*
    Problem   : Group Anagrams
    Difficulty: Medium
    Topic     : HashMap

    Given an array of strings, group the anagrams together.

    Example:
    Input : strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["eat","tea","ate"],["tan","nat"],["bat"]]

    Approach:
    - For each string, sort its characters to get a canonical key.
    - Use a hashmap: key -> list of original strings.
    - All strings with the same canonical key are anagrams of each other.

    Time Complexity : O(n * k log k)  where k = max string length
    Space Complexity: O(n * k)
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> groups;
    for (string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& [k, v] : groups) result.push_back(v);
    return result;
}

int main() {
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for (auto& group : res) {
        for (auto& s : group) cout << s << " ";
        cout << endl;
    }
    return 0;
}
