/*🏝️ Problem: Number of Islands

Topic: Graph → DFS → Connected Components → 2D Grid

Question

You are given a 2D grid consisting of '1' and '0'.

'1' represents land.
'0' represents water.
An island is formed by connected land cells.
Two land cells are considered connected only if they are adjacent up, down, left, or right.
Diagonal cells are not considered connected.

Write a C++ program using Depth First Search (DFS) to find the total number of islands in the given grid.

Example
Input:

1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1

Diagram:

🟩 🟩 🌊 🌊 🌊
🟩 🟩 🌊 🌊 🌊
🌊 🌊 🟩 🌊 🌊
🌊 🌊 🌊 🟩 🟩

There are 3 islands.

Output:
3
💡 Approach

We scan every cell of the grid.

Step 1

If we find:

it means we found a new island.

Step 2

Increase the island count:

cnt++;
Step 3

Call DFS from that cell.

DFS visits all connected land cells.

Step 4

Change every visited '1' into '0'.

g[i][j] = '0';

This means:

"I have already visited this land."

Therefore, we won't count the same island again.

🧭 DFS Directions

From every land cell, DFS checks:

             UP
              ↑
              |
        LEFT ← ● → RIGHT
              |
              ↓
            DOWN

In code:

i - 1, j    // UP
i + 1, j    // DOWN
i, j - 1    // LEFT
i, j + 1    // RIGHT

The order can be changed; we just need to check all four directions.*/



/* OR:

 Problem: Number of Islands
 Topic  : Graph -> DFS -> Connected Components -> 2D Grid

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
   3
*/

#include <iostream>
#include <vector>
using namespace std;

int rows, cols;
vector<vector<char>> g;
//vector<vector<char>> is a vector of rows, so it is a grid. g[i][j] means row i, column j.

// DFS: sinks the whole island starting from (i, j)
void dfs(int i, int j) {
    // Boundary check + water check
    if (i < 0 || i >= rows || j < 0 || j >= cols || g[i][j] != '1')
        return;

    g[i][j] = '0';   // mark as visited

    dfs(i - 1, j);   // UP
    dfs(i + 1, j);   // DOWN
    dfs(i, j - 1);   // LEFT
    dfs(i, j + 1);   // RIGHT
}

int numIslands() {
    int cnt = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (g[i][j] == '1') {   // found a new island
                cnt++;
                dfs(i, j);          // visit all connected land
            }
        }
    }
    return cnt;  
}

int main() {
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;

    g.assign(rows, vector<char>(cols, '0'));

    cout << "Enter the grid (" << rows << " lines, 1 = land, 0 = water):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> g[i][j];   // cin skips spaces, so "1 1 0" and "110" both work
        }
    }

    cout << "Number of islands: " << numIslands() << endl;
    return 0;
}