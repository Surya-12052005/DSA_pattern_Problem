/*Day 21 — Dynamic Programming / Recursion
Indexing used in all matrix questions

We will use 0-based indexing:

        j=0   j=1   j=2   j=3
      ┌─────┬─────┬─────┬─────┐
i=0   │ 0,0 │ 0,1 │ 0,2 │ 0,3 │
      ├─────┼─────┼─────┼─────┤
i=1   │ 1,0 │ 1,1 │ 1,2 │ 1,3 │
      ├─────┼─────┼─────┼─────┤
i=2   │ 2,0 │ 2,1 │ 2,2 │ 2,3 │
      ├─────┼─────┼─────┼─────┤
i=3   │ 3,0 │ 3,1 │ 3,2 │ 3,3 │
      └─────┴─────┴─────┴─────┘

Start = (0,0)
End   = (3,3)*/



/*
1.cpp — Number of Ways to Reach End
Question

Given an m × n matrix, a person starts at cell (0,0).
The person can move only Right or Down.
Find the total number of ways to reach the last cell (m-1,n-1).*/ 


/*     
        RIGHT →
        ┌─────┬─────┬─────┐
        │ S   │     │     │
        ├─────┼─────┼─────┤
 DOWN ↓ │     │     │     │
        ├─────┼─────┼─────┤
        │     │     │  E  │
        └─────┴─────┴─────┘

S = (0,0)
E = (m-1,n-1)

Allowed:
→ Right
↓ Down
*/


/*
Recursion idea

From (m,n):

              (m,n)
             /     \
        Down ↓       → Right
          (m+1,n)   (m,n+1)
          */
/*For the reverse approach used in your notebook:

         numOfWays(m,n)

        /             \
   numOfWays(m-1,n)   numOfWays(m,n-1)
        ↑                  ↑
       up                left */  


#include <iostream>
using namespace std;

int numOfWays(int m, int n)
{
    // Starting cell
    if (m == 0 && n == 0)
        return 1;

    // No more rows or columns
    if (m < 0 || n < 0)
        return 0;

    int x = numOfWays(m - 1, n);
    int y = numOfWays(m, n - 1);

    return x + y;
}

int main()
{
    int m, n;

    cout << "Enter rows: ";
    cin >> m;

    cout << "Enter columns: ";
    cin >> n;

    cout << "Total ways = " << numOfWays(m - 1, n - 1);

    return 0;
}


/*leetcode version:
class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& cache) {

        // 1. Base case
        if (m == 1 && n == 1)
            return 1;

        if (m <= 0 || n <= 0)
            return 0;

        // 2. Already calculated?
        if (cache[m][n] != -1)
            return cache[m][n];

        // 3. Recursion
        int x = solve(m - 1, n, cache);
        int y = solve(m, n - 1, cache);

        // 4. Store answer
        return cache[m][n] = x + y;
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> cache(m + 1, vector<int>(n + 1, -1));

        return solve(m, n, cache);
    }
};*/



/* given a m*n mattrix , a person can only travel in front and bottom direction , currently he is at starting position (cell(0,0)) , find the total no of ways he can travel so that he can reach at the last cell (m*n)
there is no backward and diagonal movement.

int numOfWays(int m, int n)
{
if(m==0 && n==0){return 0;}
if(m==0 || n==0){return 1;}
int x=numOfWays(m-1,n);
int y=numOfWays(m,n-1);
return x+y;
}

*/ 
/*
#include <iostream>
using namespace std;

int numOfWays(int m, int n)
{
    // Starting cell
    if (m == 1 && n == 1)
        return 1;

    // Only one row or one column
    if (m == 1 || n == 1)
        return 1;

    // Move down + move right
    int x = numOfWays(m - 1, n);
    int y = numOfWays(m, n - 1);

    return x + y;
}

int main()
{
    int m, n;

    cout << "Enter rows: ";
    cin >> m;

    cout << "Enter columns: ";
    cin >> n;

    cout << "Total ways = " << numOfWays(m, n);

    return 0;
}
*/
