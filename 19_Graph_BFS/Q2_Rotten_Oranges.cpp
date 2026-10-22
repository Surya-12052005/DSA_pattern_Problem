/*
    Problem   : Rotting Oranges
    Difficulty: Medium
    Topic     : Graph BFS (Multi-source BFS)

    Given a grid where 0 = empty, 1 = fresh orange, 2 = rotten orange,
    every minute any fresh orange adjacent to a rotten one becomes
    rotten. Return the minimum minutes until no cell has a fresh
    orange, or -1 if impossible.

    Example:
    Input : grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4

    Approach:
    - Multi-source BFS: push all initially rotten oranges into queue.
    - BFS level by level (each level = 1 minute), rotting fresh
      neighbors and pushing them into the queue.
    - Track remaining fresh oranges; if any left after BFS, return -1.

    Time Complexity : O(m * n)
    Space Complexity: O(m * n)
*/

#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    queue<pair<int,int>> q;
    int fresh = 0;

    for (int r = 0; r < m; r++)
        for (int c = 0; c < n; c++) {
            if (grid[r][c] == 2) q.push({r, c});
            else if (grid[r][c] == 1) fresh++;
        }

    if (fresh == 0) return 0;

    int minutes = 0;
    vector<int> dr = {1,-1,0,0}, dc = {0,0,1,-1};

    while (!q.empty()) {
        int size = q.size();
        bool rottedAny = false;
        for (int i = 0; i < size; i++) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                    rottedAny = true;
                }
            }
        }
        if (rottedAny) minutes++;
    }
    return fresh == 0 ? minutes : -1;
}

int main() {
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << "Minutes: " << orangesRotting(grid) << endl;
    return 0;
}
