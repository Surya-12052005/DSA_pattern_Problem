/*Q3. Print All Possible Paths Giving Maximum Gold- USING RECURSION

This is the next level.

Suppose more than one path gives the same maximum gold. We have to print all such maximum paths.

For this, we use recursion and a path string.

At every cell:

        Upper Right
             ↗
Current → Right
             ↘
        Lower Right

We continue recursively for all directions that can produce the maximum answer.*/

#include <iostream>
#include <string>
using namespace std;

int val[5][5] =
{
    {2, 3, 1, 2, 5},
    {1, 1, 3, 4, 1},
    {3, 1, 2, 3, 3},
    {1, 2, 1, 2, 2},
    {1, 4, 4, 1, 1}
};

int m = 5;
int n = 5;

// Function to find maximum gold from (i,j)
int maxGold(int i, int j)
{
    if (i < 0 || i >= m || j >= n)
        return 0;

    if (j == n - 1)
        return val[i][j];

    int x = maxGold(i - 1, j + 1);
    int y = maxGold(i, j + 1);
    int z = maxGold(i + 1, j + 1);

    return val[i][j] + max(x, max(y, z));
}

// Function to print all maximum gold paths
void printAllPaths(int i, int j, string path)
{
    path = path + to_string(val[i][j]);

    // Last column reached
    if (j == n - 1)
    {
        cout << path << endl;
        return;
    }

    int x = -1;
    int y = -1;
    int z = -1;

    if (i > 0)
        x = maxGold(i - 1, j + 1);

    y = maxGold(i, j + 1);

    if (i < m - 1)
        z = maxGold(i + 1, j + 1);

    int mx = max(x, max(y, z));

    // Upper-right path
    if (x == mx && i > 0)
        printAllPaths(i - 1, j + 1, path + " -> ");

    // Right path
    if (y == mx)
        printAllPaths(i, j + 1, path + " -> ");

    // Lower-right path
    if (z == mx && i < m - 1)
        printAllPaths(i + 1, j + 1, path + " -> ");
}

int main()
{
    int ans = 0;

    // Find maximum gold
    for (int r = 0; r < m; r++)
    {
        int x = maxGold(r, 0);

        if (x > ans)
            ans = x;
    }

    cout << "Maximum Gold = " << ans << endl;

    cout << "All Maximum Gold Paths:" << endl;

    // Print all paths starting from rows
    for (int r = 0; r < m; r++)
    {
        if (maxGold(r, 0) == ans)
        {
            printAllPaths(r, 0, "");
        }
    }

    return 0;
}