/*BACKTRACKING — QUESTION SET
Q1. Rat in a Maze — Find All Possible Paths
Question

Given an N × N binary matrix representing a maze, a rat starts from the top-left cell (0,0) and has to reach the bottom-right cell (N-1,N-1).

1 represents an open cell.
0 represents a blocked cell.
The rat can move Down (D), Left (L), Right (R), or Up (U).
A cell cannot be visited more than once in the same path.

Print all possible paths from source to destination.

Example
Maze:

1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

Diagram:

S → 0   0   0
↓   ↓
1 → 1   0   1
↓   ↓
1 → 1   0   0
0   ↓ → 1 → D

One valid path is:

D D R D R*/

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& maze, int x, int y,
            vector<vector<bool>>& visited, int n) {

    if (x >= 0 && x < n &&
        y >= 0 && y < n &&
        maze[x][y] == 1 &&
        visited[x][y] == false) {

        return true;
    }

    return false;
}

void findPaths(vector<vector<int>>& maze, int x, int y,
               int n, vector<vector<bool>>& visited,
               string path) {

    // Destination reached
    if (x == n - 1 && y == n - 1) {
        cout << path << endl;
        return;
    }

    visited[x][y] = true;

    // Down
    if (isSafe(maze, x + 1, y, visited, n)) {
        findPaths(maze, x + 1, y, n, visited, path + "D");
    }

    // Left
    if (isSafe(maze, x, y - 1, visited, n)) {
        findPaths(maze, x, y - 1, n, visited, path + "L");
    }

    // Right
    if (isSafe(maze, x, y + 1, visited, n)) {
        findPaths(maze, x, y + 1, n, visited, path + "R");
    }

    // Up
    if (isSafe(maze, x - 1, y, visited, n)) {
        findPaths(maze, x - 1, y, n, visited, path + "U");
    }

    // Backtrack
    visited[x][y] = false;
}

int main() {

    int n = 4;

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<vector<bool>> visited(
        n, vector<bool>(n, false)
    );

    cout << "All possible paths:\n";

    if (maze[0][0] == 1) {
        findPaths(maze, 0, 0, n, visited, "");
    }

    return 0;
}