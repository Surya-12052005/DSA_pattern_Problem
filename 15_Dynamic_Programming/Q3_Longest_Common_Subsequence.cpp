/*
    Problem   : Longest Common Subsequence (LCS)
    Difficulty: Medium
    Topic     : Dynamic Programming

    Given two strings text1 and text2, return the length of their
    longest common subsequence. If none exists, return 0.

    Example:
    Input : text1 = "abcde", text2 = "ace"
    Output: 3   ("ace")

    Approach:
    - dp[i][j] = LCS length of text1[0..i-1] and text2[0..j-1].
    - If characters match: dp[i][j] = 1 + dp[i-1][j-1].
    - Else: dp[i][j] = max(dp[i-1][j], dp[i][j-1]).

    Time Complexity : O(m * n)
    Space Complexity: O(m * n)
*/

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main() {
    string text1 = "abcde", text2 = "ace";
    cout << "LCS Length: " << longestCommonSubsequence(text1, text2) << endl;
    return 0;
}
