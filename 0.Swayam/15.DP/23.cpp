/*
Q. MAXIMUM GOLD PATH USING DP

Given a 2D array, each cell contains some amount of gold.
A person can enter from any row of the first column.

He can move in only 3 directions:
1. Right
2. Diagonal Up-Right
3. Diagonal Down-Right

Find the maximum gold he can collect while reaching
the last column.

        2D ARRAY : 5 x 6

              Columns
           0   1   2   3   4   5
        +---+---+---+---+---+---+
   0    | 2 | 3 | 1 | 2 | 5 | 4 |
        +---+---+---+---+---+---+
   1    | 1 | 1 | 3 | 4 | 1 | 2 |
        +---+---+---+---+---+---+
   2    | 3 | 1 | 2 | 3 | 3 | 1 |
        +---+---+---+---+---+---+
   3    | 1 | 2 | 1 | 2 | 2 | 3 |
        +---+---+---+---+---+---+
   4    | 1 | 4 | 4 | 1 | 1 | 5 |
        +---+---+---+---+---+---+

Movement:

             ↗ Up-Right
            /
       [ i ][ j ] → Right
            \
             ↘ Down-Right
*/

#include <iostream>
#include <algorithm>
using namespace std;


int m = 5;
int n = 6;

int gold[5][6] = {
    {2, 3, 1, 2, 5, 4},
    {1, 1, 3, 4, 1, 2},
    {3, 1, 2, 3, 3, 1},
    {1, 2, 1, 2, 2, 3},
    {1, 4, 4, 1, 1, 5}
};

int dp[5][6];

int maxGold(int i, int j)
{
    if (i < 0 || i >= m || j >= n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (j == n - 1)
        return dp[i][j] = gold[i][j];

    int x = maxGold(i - 1, j + 1);
    int y = maxGold(i, j + 1);
    int z = maxGold(i + 1, j + 1);

    return dp[i][j] = gold[i][j] + max({x, y, z});
}

int main()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    int answer = 0;

    for (int i = 0; i < m; i++)
    {
        int x = maxGold(i, 0);
        answer = max(answer, x);
    }

    cout << "Maximum Gold = " << answer << endl;

    return 0;
}