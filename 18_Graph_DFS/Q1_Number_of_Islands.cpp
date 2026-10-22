/*
    Problem   : Number of Islands
    Difficulty: Medium
    Topic     : Graph DFS

    Given an m x n 2D grid of '1's (land) and '0's (water), return
    the number of islands. An island is surrounded by water and formed
    by connecting adjacent lands horizontally or vertically.

    Example:
    Input : grid = [["1","1","0"],["1","0","0"],["0","0","1"]]
    Output: 2

    Approach:
    - Traverse each cell; if it's land ('1') and not visited, it's a
      new island - increment count.
    - Use DFS to mark all connected land cells as visited (sink the island).

    Time Complexity : O(m * n)
    Space Complexity: O(m * n) recursion stack in worst case
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid, int r, int c) {
    int m = grid.size(), n = grid[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') return;

    grid[r][c] = '0'; // mark visited
    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int r = 0; r < (int)grid.size(); r++) {
        for (int c = 0; c < (int)grid[0].size(); c++) {
            if (grid[r][c] == '1') {
                count++;
                dfs(grid, r, c);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0'},
        {'1','0','0'},
        {'0','0','1'}
    };
    cout << "Number of Islands: " << numIslands(grid) << endl;
    return 0;
}
