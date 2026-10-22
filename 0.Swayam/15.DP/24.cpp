/*
===========================================================
Q. MAXIMUM GOLD PATH USING DYNAMIC PROGRAMMING
===========================================================

Given a 2D array, each cell contains some amount of gold.

A person can start from ANY ROW of the FIRST COLUMN.

He can move only in 3 directions:

    1. Right
    2. Diagonal Up-Right
    3. Diagonal Down-Right

Find the maximum gold that can be collected.

===========================================================
                    5 x 6 ARRAY
===========================================================

             Column
          0   1   2   3   4   5
       +---+---+---+---+---+---+
Row 0  | 2 | 3 | 1 | 2 | 5 | 4 |
       +---+---+---+---+---+---+
Row 1  | 1 | 1 | 3 | 4 | 1 | 2 |
       +---+---+---+---+---+---+
Row 2  | 3 | 1 | 2 | 3 | 3 | 1 |
       +---+---+---+---+---+---+
Row 3  | 1 | 2 | 1 | 2 | 2 | 3 |
       +---+---+---+---+---+---+
Row 4  | 1 | 4 | 4 | 1 | 1 | 5 |
       +---+---+---+---+---+---+

DP:
Start from the LAST COLUMN and move towards the FIRST COLUMN.

dp[i][j] = gold[i][j] +
           max(upRight, right, downRight)

Finally, check all rows of the first column.
===========================================================
*/

#include <iostream>
#include <algorithm>
using namespace std;

// DP function
int maxGold(int gold[5][6], int m, int n)
{
    int dp[5][6];

    // Copy the last column
    for (int i = 0; i < m; i++)
    {
        dp[i][n - 1] = gold[i][n - 1];
    }

    // Start from second-last column
    // and move towards the first column
    for (int j = n - 2; j >= 0; j--)
    {
        for (int i = 0; i < m; i++)
        {
            int upRight = 0;
            int right = dp[i][j + 1];
            int downRight = 0;

            if (i > 0)
            {
                upRight = dp[i - 1][j + 1];
            }

            if (i < m - 1)
            {
                downRight = dp[i + 1][j + 1];
            }

            dp[i][j] = gold[i][j] +
                       max({upRight, right, downRight});
        }
    }

    // Find maximum from first column
    int answer = 0;

    for (int i = 0; i < m; i++)
    {
        answer = max(answer, dp[i][0]);
    }

    return answer;
}

int main()
{
    int gold[5][6] = {
        {2, 3, 1, 2, 5, 4},
        {1, 1, 3, 4, 1, 2},
        {3, 1, 2, 3, 3, 1},
        {1, 2, 1, 2, 2, 3},
        {1, 4, 4, 1, 1, 5}
    };

    int m = 5;
    int n = 6;

    int answer = maxGold(gold, m, n);

    cout << "Maximum Gold = " << answer << endl;

    return 0;
}