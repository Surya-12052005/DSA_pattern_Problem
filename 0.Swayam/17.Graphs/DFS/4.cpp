/*Problem 3. Largest Island After Changing One 0 to 1

Problem Statement:
Given a binary matrix where:

1 = land
0 = water

You are allowed to change exactly one 0 into 1.

Find the maximum possible size of an island after making this one change.

Example
1 1 0
1 0 0
0 0 1*/  

#include <iostream>
using namespace std;

int m = 3, n = 3;

int dfs(int a[][3], int i, int j)
{
    if(i < 0 || i >= m || j < 0 || j >= n)
        return 0;

    if(a[i][j] != 1)
        return 0;

    a[i][j] = 2;

    return 1
        + dfs(a, i - 1, j)
        + dfs(a, i + 1, j)
        + dfs(a, i, j - 1)
        + dfs(a, i, j + 1);
}

int largestIsland(int a[][3])
{
    int maxSize = 0;

    // Find existing largest island
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
    int a[3][3] =
    {
        {1, 1, 0},
        {1, 0, 0},
        {0, 0, 1}
    };

    // Simple version:
    // First find the largest existing island.
    cout << "Largest existing island = "
         << largestIsland(a);

    return 0;
}


/*
 Problem 3: Largest Island After Changing One 0 to 1
 Topic    : Graph -> DFS -> Connected Components -> 2D Grid

 Input format:
   Line 1: rows cols
   Next `rows` lines: the grid, either as "1 1 0" or "110"

 Example input:
   3 3
   1 1 0
   1 0 0
   0 0 1

 Output:
   4


#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int rows, cols;
vector<vector<int>> g;

// Directions: UP, DOWN, LEFT, RIGHT
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// DFS: relabels the island containing (i, j) with `id`, returns its size
int dfs(int i, int j, int id) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || g[i][j] != 1)
        return 0;

    g[i][j] = id;          // label instead of just marking visited
    int size = 1;

    for (int d = 0; d < 4; d++)
        size += dfs(i + dx[d], j + dy[d], id);

    return size;
}

int largestIsland() {
    // sizes[id] = size of island labelled `id` (ids start from 2,
    // because 0 = water and 1 = unvisited land)
    vector<int> sizes(2, 0);
    int id = 2;
    int best = 0;

    // Phase 1: label all islands and store their sizes
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (g[i][j] == 1) {
                int s = dfs(i, j, id);
                sizes.push_back(s);
                best = max(best, s);
                id++;
            }
        }
    }

    // Phase 2: try flipping every water cell
    bool hasWater = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (g[i][j] == 0) {
                hasWater = true;
                unordered_set<int> seen;   // distinct neighbouring islands
                int total = 1;             // the flipped cell itself

                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols
                        && g[ni][nj] > 1) {
                        int nid = g[ni][nj];
                        if (!seen.count(nid)) {
                            seen.insert(nid);
                            total += sizes[nid];
                        }
                    }
                }
                best = max(best, total);
            }
        }
    }

    // No water at all: nothing to flip, the whole grid is one island
    if (!hasWater) return rows * cols;

    return best;
}

int main() {
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;

    g.assign(rows, vector<int>(cols, 0));

    cout << "Enter the grid (" << rows << " lines, 1 = land, 0 = water):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char c;
            cin >> c;
            g[i][j] = c - '0';
        }
    }

    cout << "Largest island after one change: " << largestIsland() << endl;
    return 0;
}*/
/*#include <iostream>
#include <set>
using namespace std;

int n = 3;

int dfs(int a[][3], int i, int j, int id)
{
    if(i < 0 || i >= n || j < 0 || j >= n)
        return 0;

    if(a[i][j] != 1)
        return 0;

    a[i][j] = id;

    return 1
        + dfs(a, i - 1, j, id)
        + dfs(a, i + 1, j, id)
        + dfs(a, i, j - 1, id)
        + dfs(a, i, j + 1, id);
}

int main()
{
    int a[3][3] =
    {
        {1, 1, 0},
        {1, 0, 0},
        {0, 0, 1}
    };

    int size[10] = {0};
    int id = 2;

    // Give every island a unique ID
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 1)
            {
                size[id] = dfs(a, i, j, id);
                id++;
            }
        }
    }

    int answer = 0;

    // Try converting every 0 to 1
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 0)
            {
                set<int> islands;

                if(i > 0 && a[i-1][j] > 1)
                    islands.insert(a[i-1][j]);

                if(i < n-1 && a[i+1][j] > 1)
                    islands.insert(a[i+1][j]);

                if(j > 0 && a[i][j-1] > 1)
                    islands.insert(a[i][j-1]);

                if(j < n-1 && a[i][j+1] > 1)
                    islands.insert(a[i][j+1]);

                int total = 1;

                for(int x : islands)
                    total += size[x];

                answer = max(answer, total);
            }
        }
    }

    // If matrix has no zero
    if(answer == 0)
        answer = n * n;

    cout << "Largest island after changing one 0 = "
         << answer;

    return 0;
}*/