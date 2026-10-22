/*Q2. N-Queens Problem
Question

Given an N × N chessboard, place N queens on the board such that no two queens attack each other.

Two queens cannot be placed in the same:

Row
Column
Diagonal

Print all possible solutions.

Example: N = 4

One valid arrangement:

. Q . .
. . . Q
Q . . .
. . Q .

Here:

Q = Queen
. = Empty cell
Graph/Board Representation
       C0 C1 C2 C3
     +------------+
R0   | .  Q  .  . |
     |            |
R1   | .  .  .  Q |
     |            |
R2   | Q  .  .  . |
     |            |
R3   | .  .  Q  . |
     +------------+
C++ Solution*/

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {

    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0;
         i--, j--) {

        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n;
         i--, j++) {

        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void solveNQueens(vector<vector<int>>& board, int row, int n) {

    // All queens placed
    if (row == n) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
        return;
    }

    // Try every column
    for (int col = 0; col < n; col++) {

        if (isSafe(board, row, col, n)) {

            // Place queen
            board[row][col] = 1;

            // Move to next row
            solveNQueens(board, row + 1, n);

            // Backtrack
            board[row][col] = 0;
        }
    }
}

int main() {

    int n = 4;

    vector<vector<int>> board(
        n, vector<int>(n, 0)
    );

    cout << "All possible solutions:\n\n";

    solveNQueens(board, 0, n);

    return 0;
}