
/*
===========================================================
Q2. PRINT THE PATH THAT GIVES MAXIMUM GOLD
===========================================================

Given a 2D array where each cell contains some amount
of gold.

A person can start from ANY ROW of the FIRST COLUMN.

The person can move only in 3 directions:

    1. Right
    2. Diagonal Up-Right
    3. Diagonal Down-Right

Using Dynamic Programming, find and print the path
that collects the maximum amount of gold.

Also print the maximum gold collected.

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

Start from any row of column 0
              ↓
Move towards column 5
              ↓
Print the path with maximum gold
===========================================================
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Function to find and print maximum gold path
int maxGoldPath(int gold[5][6], int m, int n)
{
    int dp[5][6];

    // Store the row from which we came
    int path[5][6];

    // Last column
    for (int i = 0; i < m; i++)
    {
        dp[i][n - 1] = gold[i][n - 1];
        path[i][n - 1] = -1;
    }

    // Move from last column to first column
    for (int j = n - 2; j >= 0; j--)
    {
        for (int i = 0; i < m; i++)
        {
            int best = dp[i][j + 1];
            int bestRow = i;

            // Diagonal Up-Right
            if (i > 0 && dp[i - 1][j + 1] > best)
            {
                best = dp[i - 1][j + 1];
                bestRow = i - 1;
            }

            // Diagonal Down-Right
            if (i < m - 1 && dp[i + 1][j + 1] > best)
            {
                best = dp[i + 1][j + 1];
                bestRow = i + 1;
            }

            dp[i][j] = gold[i][j] + best;

            // Store the next row
            path[i][j] = bestRow;
        }
    }

    // Find the best starting row
    int startRow = 0;

    for (int i = 1; i < m; i++)
    {
        if (dp[i][0] > dp[startRow][0])
        {
            startRow = i;
        }
    }

    cout << "Maximum Gold = " << dp[startRow][0] << endl;

    cout << "\nPath:\n";

    int row = startRow;

    for (int j = 0; j < n; j++)
    {
        cout << "(" << row << "," << j << ")";

        if (j != n - 1)
        {
            cout << " -> ";
        }

        row = path[row][j];
    }

    cout << endl;

    return dp[startRow][0];
}

int main()
{
    int gold[5][6] =
    {
        {2, 3, 1, 2, 5, 4},
        {1, 1, 3, 4, 1, 2},
        {3, 1, 2, 3, 3, 1},
        {1, 2, 1, 2, 2, 3},
        {1, 4, 4, 1, 1, 5}
    };

    int m = 5;
    int n = 6;

    maxGoldPath(gold, m, n);

    return 0;
}