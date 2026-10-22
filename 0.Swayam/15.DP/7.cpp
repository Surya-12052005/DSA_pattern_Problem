/*
5.cpp — Minimum Cost Path

This is the cost matrix from your screenshot:

        j=0  j=1  j=2  j=3
      ┌────┬────┬────┬────┐
i=0   │  2 │  4 │  1 │  4 │
      ├────┼────┼────┼────┤
i=1   │  1 │  8 │  1 │  3 │
      ├────┼────┼────┼────┤
i=2   │  9 │  7 │  2 │  1 │
      ├────┼────┼────┼────┤
i=3   │  1 │  4 │  3 │  2 │
      └────┴────┴────┴────┘

Start = (0,0)
End   = (3,3)


Question

Given a cost matrix, find the minimum cost required to travel from (0,0) to (m-1,n-1). A person can move only Right or Down.

Recursion idea

At every cell:  

              current
              (i,j)
             /     \
        Right →     ↓ Down
       (i,j+1)    (i+1,j)
       
We choose the smaller cost:

min(right, down)
*/

#include <iostream>
using namespace std;

int cost[4][4] =
{
    {2, 4, 1, 4},
    {1, 8, 1, 3},
    {9, 7, 2, 1},
    {1, 4, 3, 2}
};

int minCost(int i, int j)
{
    // Starting cell
    if (i == 0 && j == 0)
        return cost[0][0];

    // First row
    if (i == 0)
        return cost[i][j] + minCost(i, j - 1);
  
    // First column
    if (j == 0)
        return cost[i][j] + minCost(i - 1, j);  

    // Come from top or left
    int top = minCost(i - 1, j);
    int left = minCost(i, j - 1);

    return cost[i][j] + min(top, left);  
}

int main()
{
    cout << "Minimum cost = " << minCost(3, 3); //Find the minimum cost to reach cell (m,n) from (0,0).

    return 0;  
}

/*given a cost mattrix , find the min cost to travel from start to end

[2 ][4 ][1][4 ]
[1][8 ][1 ][3 ]
[9 ][7][2 ][1]
[ 1][4 ][3 ][2 ]
 start from last and use recursion

int minCost(int m, int n)
{

min(x+2,y+2)

}


#include <iostream>
using namespace std;

int cost[4][4] =
{
    {2, 4, 1, 4},
    {1, 8, 1, 3},
    {9, 7, 2, 1},
    {1, 4, 3, 2}
};

int minCost(int m, int n)
{
    // Starting cell
    if (m == 0 && n == 0)
        return cost[0][0];

    // First row
    if (m == 0)
        return cost[m][n] + minCost(m, n - 1);

    // First column
    if (n == 0)
        return cost[m][n] + minCost(m - 1, n);

    // Come from up or left
    int x = minCost(m - 1, n);
    int y = minCost(m, n - 1);

    return cost[m][n] + min(x, y);
}

int main()
{
    cout << "Minimum cost = " << minCost(3, 3);

    return 0;
}*/