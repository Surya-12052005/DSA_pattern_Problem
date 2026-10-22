/*you are given two arr: 
s1=ABCDAB
s2=BACDB
FIND THE LENGTH OF longest common subsequence of two array and also print the longest common subsequence.*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s1 = "ABCDAB";
    string s2 = "BACDB";

    int n = s1.size();
    int m = s2.size();

    int dp[n + 1][m + 1];

    // Create DP table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Length of LCS
    cout << "Length of LCS = " << dp[n][m] << endl;

    // Print LCS
    string lcs = "";

    int i = n;
    int j = m;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs += s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    // We created LCS backwards
    reverse(lcs.begin(), lcs.end());

    cout << "LCS = " << lcs << endl;

    return 0;
}