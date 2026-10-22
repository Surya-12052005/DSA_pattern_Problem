/*Q1. Number of Ways to Reach the End — Memoization
Question

Given an m × n matrix, a person starts from the starting cell (0,0). The person can move only in two directions:

Right → (i, j+1)
Down ↓ (i+1, j)

Find the total number of different ways to reach the last cell (m-1,n-1) using recursion with memoization.

Example

For a 3 × 3 matrix:

        Columns
       0    1    2
     ┌────┬────┬────┐
  0  │ S  │    │    │
     ├────┼────┼────┤
  1  │    │    │    │
     ├────┼────┼────┤
  2  │    │    │ E  │
     └────┴────┴────┘

S = Starting cell (0,0)
E = Ending cell (2,2)
Possible movement
             Start
             (0,0)
            /     \
          ↓         →
        (1,0)      (0,1)
          ↓           ↓
        (2,0)       (1,1)
                     ↓
                    ...
                       → End

There are 6 total ways.

Memoization Concept

We create:

int cache[100][100];

cache[i][j] stores:

Number of ways to reach cell (i,j)

Initially:

cache = -1

-1 means:

This cell has not been calculated yet.*/ 

       #include <iostream>
using namespace std;

int cache[100][100];

int numOfWays(int m, int n)
{
    // Already calculated
    if (cache[m][n] != -1)
        return cache[m][n];

    // Starting cell
    if (m == 0 && n == 0)
        return 1;

    // First row or first column
    if (m == 0 || n == 0)
        return 1;

    // Move up + move left
    cache[m][n] = numOfWays(m - 1, n) + numOfWays(m, n - 1);

    return cache[m][n];
}

int main()
{
    int m = 3;
    int n = 3;

    // Initialize cache with -1
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cache[i][j] = -1;
        }
    }

    cout << "Total ways = " << numOfWays(m - 1, n - 1);

    return 0;
}