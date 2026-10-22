/*Problem 2. Find the Size of the Largest Island

Problem Statement:
Given a binary matrix where 1 represents land and 0 represents water, find the size of the largest island.

The size of an island is the number of connected land cells.

Use 4-directional connectivity.*/



/*
 Problem 2: Find the Size of the Largest Island
 Topic    : Graph -> DFS -> Connected Components -> 2D Grid

 Input format:
   Line 1: rows cols
   Next `rows` lines: the grid, either as "1 1 0 0 0" or "11000"

 Example input:
   4 5
   1 1 0 0 0
   1 1 0 0 0
   0 0 1 0 0
   0 0 0 1 1

 Output:
   4
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rows, cols;
vector<vector<char>> g;

// DFS: returns the number of land cells in the island containing (i, j)
int dfs(int i, int j) {
    // Boundary check + water/visited check
    if (i < 0 || i >= rows || j < 0 || j >= cols || g[i][j] != '1')
        return 0;

    g[i][j] = '0';   // mark as visited

    int size = 1;    // count the current cell

    size += dfs(i - 1, j);   // UP
    size += dfs(i + 1, j);   // DOWN
    size += dfs(i, j - 1);   // LEFT
    size += dfs(i, j + 1);   // RIGHT

    return size;
}

int largestIsland() {
    int best = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (g[i][j] == '1') {                 // found a new island
                best = max(best, dfs(i, j));      // measure it, keep the biggest
            }
        }
    }
    return best;
}

int main() {
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;

    g.assign(rows, vector<char>(cols, '0'));

    cout << "Enter the grid (" << rows << " lines, 1 = land, 0 = water):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> g[i][j];
        }
    }

    cout << "Largest island size: " << largestIsland() << endl;
    return 0;
}


/*
#include <iostream>
using namespace std;

int m = 6, n = 6;

int dfs(int a[][6], int i, int j)
{
    if(i < 0 || i >= m || j < 0 || j >= n)
        return 0;

    if(a[i][j] != 1)
        return 0;

    // Mark visited
    a[i][j] = 2;

    int size = 1;

    size += dfs(a, i - 1, j); // up
    size += dfs(a, i + 1, j); // down
    size += dfs(a, i, j - 1); // left
    size += dfs(a, i, j + 1); // right

    return size;
}

int largestIsland(int a[][6])
{
    int maxSize = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 1)
            {
                int size = dfs(a, i, j);

                if(size > maxSize)
                    maxSize = size;
            }
        }
    }

    return maxSize;
}

int main()
{
    int a[6][6] =
    {
        {1, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 0, 0}
    };

    cout << "Largest island size = "
         << largestIsland(a);

    return 0;
}*/