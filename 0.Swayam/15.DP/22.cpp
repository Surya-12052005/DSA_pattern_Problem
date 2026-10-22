/*
===========================================================
Q. MAXIMUM GOLD PATH USING DYNAMIC PROGRAMMING
===========================================================

Given a 2D matrix, each cell contains some amount of gold.

A person can enter the matrix from ANY ROW of the FIRST
COLUMN and can move only in the following three directions:

    1. Right
    2. Diagonal Up-Right
    3. Diagonal Down-Right

The person wants to reach the LAST COLUMN while collecting
the maximum possible amount of gold.

Find the maximum amount of gold the person can collect.

===========================================================
        2D ARRAY : 5 x 6
===========================================================

              Columns
           0   1   2   3   4   5
        +---+---+---+---+---+---+
   0    | 2 | 3 | 1 | 2 | 5 | 4 |
        +---+---+---+---+---+---+
   1    | 1 | 1 | 3 | 4 | 1 | 2 |
        +---+---+---+---+---+---+
   2    | 3 | 1 | 2 | 3 | 3 | 1 |
Rows    +---+---+---+---+---+---+
   3    | 1 | 2 | 1 | 2 | 2 | 3 |
        +---+---+---+---+---+---+
   4    | 1 | 4 | 4 | 1 | 1 | 5 |
        +---+---+---+---+---+---+

===========================================================

Possible movements from any cell:

             UP-RIGHT
                ↗
                |
       CURRENT  →  RIGHT
                |
                ↘
             DOWN-RIGHT

===========================================================
DP IDEA:
===========================================================

Let dp[i][j] = maximum gold that can be collected starting
               from cell (i, j) and reaching the last column.

For every cell:

    dp[i][j] = gold[i][j] +
               max(
                   dp[i-1][j+1],   // diagonal up-right
                   dp[i][j+1],     // right
                   dp[i+1][j+1]    // diagonal down-right
               )

Boundary conditions:

    If i < 0 or i >= m or j >= n
        return 0

Base case:

    If j == n-1
        return gold[i][j]

Since the person can start from ANY row in column 0,
we calculate the answer for every row of column 0 and
take the maximum.

===========================================================
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Number of rows and columns
int m = 5;
int n = 6;

// Gold matrix
int gold[5][6] = {
    {2, 3, 1, 2, 5, 4},
    {1, 1, 3, 4, 1, 2},
    {3, 1, 2, 3, 3, 1},
    {1, 2, 1, 2, 2, 3},
    {1, 4, 4, 1, 1, 5}
};

// DP array
int dp[5][6];

// Function to find maximum gold
int maxGold(int i, int j)
{
    // Invalid row or column
    if (i < 0 || i >= m || j >= n)
    {
        return 0;
    }

    // If this cell has already been calculated
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // Last column
    if (j == n - 1)
    {
        return dp[i][j] = gold[i][j];
    }

    // Diagonal Up-Right
    int x = maxGold(i - 1, j + 1);

    // Right
    int y = maxGold(i, j + 1);

    // Diagonal Down-Right
    int z = maxGold(i + 1, j + 1);

    // Store answer in DP table
    dp[i][j] = gold[i][j] + max({x, y, z});

    return dp[i][j];
}


// Main function
int main()
{
    // Initialize DP array with -1
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    int answer = 0;

    // Person can start from ANY row of column 0
    for (int i = 0; i < m; i++)
    {
        int x = maxGold(i, 0);

        answer = max(answer, x);
    }

    cout << "Maximum Gold = " << answer << endl;

    return 0;
}