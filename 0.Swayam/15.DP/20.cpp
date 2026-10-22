/*Q2. Print the Path Giving Maximum Gold- USING RECURSION

Now we don't only want the maximum value. We also want to print the path that gives that maximum.

For this, we use the same maxGold(i,j) function.

At every cell, we calculate:

x = upper-right
y = right
z = lower-right

Then we move to the direction having the maximum value.

*/

#include <iostream>
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

// Function to print maximum gold path
void printPath(int i, int j)
{
    cout << val[i][j] << " ";

    // Last column
    if (j == n - 1)
        return;

    int x = -1;
    int y = -1;
    int z = -1;

    if (i > 0)
        x = maxGold(i - 1, j + 1);

    y = maxGold(i, j + 1);

    if (i < m - 1)
        z = maxGold(i + 1, j + 1);

    int mx = max(x, max(y, z));

    // Move to upper-right
    if (x == mx && i > 0)
        printPath(i - 1, j + 1);

    // Move to right
    else if (y == mx)
        printPath(i, j + 1);

    // Move to lower-right
    else
        printPath(i + 1, j + 1);
}

int main()
{
    int ans = 0;
    int startRow = 0;

    // Find the best starting row
    for (int r = 0; r < m; r++)
    {
        int x = maxGold(r, 0);

        if (x > ans)
        {
            ans = x;
            startRow = r;
        }
    }

    cout << "Maximum Gold = " << ans << endl;

    cout << "Maximum Gold Path = ";
    printPath(startRow, 0);

    return 0;
}