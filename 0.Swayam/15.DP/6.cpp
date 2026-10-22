/*4.cpp — Number of Ways with Blocked Cells

Your screenshot shows this type of matrix:

       0   1   2   3
     ┌───┬───┬───┬───┐
  0  │   │   │ X │   │
     ├───┼───┼───┼───┤
  1  │ X │   │   │   │
     ├───┼───┼───┼───┤
  2  │   │ X │   │ X │
     ├───┼───┼───┼───┤
  3  │   │   │   │ X │
     └───┴───┴───┴───┘

X = Blocked
S = (0,0)
E = (3,3)  

Question

Given an m × n grid containing blocked cells, a person starts at (0,0) and wants to reach (m-1,n-1). The person can move only Right or Down. Find the number of possible paths.

Important

If a cell is blocked:

X → cannot enter

*/

#include <iostream>
using namespace std;  

int grid[4][4] =
{
    {0, 0, 1, 0},
    {1, 0, 0, 0},
    {0, 1, 0, 1},
    {0, 0, 0, 1}
};

int numOfWays(int i, int j)  
{
    // Outside grid
    if (i >= 4 || j >= 4)  
        return 0;

    // Blocked cell
    if (grid[i][j] == 1)  
        return 0;

    // Reached destination
    if (i == 3 && j == 3)
        return 1;

    int right = numOfWays(i, j + 1);
    int down = numOfWays(i + 1, j);  

    return right + down;
}

int main()
{
    cout << "Total ways = " << numOfWays(0, 0);

    return 0;
}



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
[ ][ ][*][ ]
[*][ ][ ][ ]
[ ][*][ ][*]
[ ][ ][ ][ ]

here some cells are block.*/