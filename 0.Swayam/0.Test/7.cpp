/*you are given two arr: 
s1=ABCDAB
s2=BACDB
FIND THE LENGTH OF longest common subsequence of two array*/

/*
Given two strings:
s1 = ABCDAB
s2 = BACDB

Find the length of the Longest Common Subsequence (LCS)
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to find LCS
int findLCS(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    int dp[n + 1][m + 1];

    // Initialize first row and column
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

int main() {

    string s1 = "ABCDAB";
    string s2 = "BACDB";

    cout << "Length of LCS = " << findLCS(s1, s2);

    return 0;
}