/*
    Problem   : N-Queens (count / print valid placements)
    Difficulty: Hard
    Topic     : Backtracking

    Place n queens on an n x n chessboard so that no two queens
    attack each other. Print all solutions (as board configurations).

    Example:
    Input : n = 4
    Output: 2 distinct solutions

    Approach:
    - Place queens row by row.
    - For each row, try placing a queen in every column, checking if
      it's safe (no other queen in same column or diagonal).
    - Use sets/arrays to track occupied columns and diagonals for O(1) checks.
    - Backtrack if no valid placement is possible.

    Time Complexity : O(n!) approx (pruned search)
    Space Complexity: O(n^2) for board + O(n) for tracking sets
*/

#include <bits/stdc++.h>
using namespace std;

void backtrack(int row, int n, vector<string>& board,
                unordered_set<int>& cols, unordered_set<int>& diag1, unordered_set<int>& diag2,
                vector<vector<string>>& solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        int d1 = row - col, d2 = row + col;
        if (cols.count(col) || diag1.count(d1) || diag2.count(d2)) continue;

        // place queen
        board[row][col] = 'Q';
        cols.insert(col); diag1.insert(d1); diag2.insert(d2);

        backtrack(row + 1, n, board, cols, diag1, diag2, solutions);

        // undo (backtrack)
        board[row][col] = '.';
        cols.erase(col); diag1.erase(d1); diag2.erase(d2);
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> solutions;
    unordered_set<int> cols, diag1, diag2;
    backtrack(0, n, board, cols, diag1, diag2, solutions);
    return solutions;
}

int main() {
    int n = 4;
    vector<vector<string>> res = solveNQueens(n);
    cout << "Number of solutions: " << res.size() << endl;
    for (auto& sol : res) {
        for (auto& row : sol) cout << row << endl;
        cout << "---" << endl;
    }
    return 0;
}
