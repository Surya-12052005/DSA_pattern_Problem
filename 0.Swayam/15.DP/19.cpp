/*Gold Mine Problem — Recursion
Given Problem

A person is standing in the first column of a gold mine. Each cell contains some amount of gold.

The person can move only in these three directions:

Right → (i, j+1)
Right-Upper Diagonal → (i-1, j+1)
Right-Lower Diagonal → (i+1, j+1)

The person can start from any row of the first column and wants to reach the last column.

Given the following matrix:

        Column
          0   1   2   3   4
       +---+---+---+---+---+
Row 0  | 2 | 3 | 1 | 2 | 5 |
       +---+---+---+---+---+
Row 1  | 1 | 1 | 3 | 4 | 1 |
       +---+---+---+---+---+
Row 2  | 3 | 1 | 2 | 3 | 3 |
       +---+---+---+---+---+
Row 3  | 1 | 2 | 1 | 2 | 2 |
       +---+---+---+---+---+
Row 4  | 1 | 4 | 4 | 1 | 1 |
       +---+---+---+---+---+
       
       
       */


/*Q1. Find the Maximum Gold
Approach

For every cell (i,j), we have three choices:

             (i-1,j+1)
                  ↗
             (i,j+1)
                  →
             (i+1,j+1)
                  ↘

So:

maxGold(i,j)
=
value[i][j] + max(
    maxGold(i-1,j+1),
    maxGold(i,j+1),
    maxGold(i+1,j+1)
)*/       


#include <iostream>
using namespace std;

int val[5][5] =
{
    {2, 3, 1, 2, 5},
    {1, 1, 3, 4, 1},
    {3, 1, 2, 3, 3},
    {1, 2, 1, 2, 2},
    {1, 4, 4, 1, 1}
};

int m = 5;
int n = 5;

// Function to find maximum gold from (i,j)
int maxGold(int i, int j)
{
    // Invalid row or column
    if (i < 0 || i >= m || j >= n)
        return 0;

    // Last column
    if (j == n - 1)
        return val[i][j];

    int x = maxGold(i - 1, j + 1);
    int y = maxGold(i, j + 1);
    int z = maxGold(i + 1, j + 1);

    return val[i][j] + max(x, max(y, z));
}

// Function to find maximum gold from any row
int maxGold()
{
    int ans = 0;

    for (int r = 0; r < m; r++)
    {
        int x = maxGold(r, 0);

        if (x > ans)
            ans = x;
    }

    return ans;
}

int main()
{
    cout << "Maximum Gold = " << maxGold();

    return 0;
}


/*given a 2D array, there is gold in each cell of the mattrix, a person can enter from column 1 and can travel in right direction , diagonal up right , and diagonal down right, he want to collect max gold
1.find the max gold a person can collect , he want to reach last column.
2.print the path that will give max gold.
3. print all posible path to get the max gold*/

/*
        2D ARRAY : 5 x 6

             Columns
          0   1   2   3   4   
        +---+---+---+---+---+
     0  |2  | 3 | 1 | 2 | 5 |  
        +---+---+---+---+---+
     1  |1  | 1 | 3 | 4 | 1 |   
        +---+---+---+---+---+
     2  |3  | 1 | 2 | 3 | 3 |  
Rows    +---+---+---+---+---+
     3  |1  | 2 | 1 | 2 | 2 |  
        +---+---+---+---+---+
     4  |1  | 4 | 4 | 1 | 1 |   
        +---+---+---+---+---+

       
*/
/*
int maxGold(int i, int (*mgos_jstore_cb)
{
    if(i<0||i>=m|| j>=n){return 0;}

    int x= maxGold(i-1,j+1)
    int y= maxGold(i,j+1)
    int z= maxGold(i+1,j+1)

    return max(x,y,z)+ val[i][j];

}

int maxGold()
{
    for (int r=0; r<m; r++)
    int x=maxGold(r,0);
    if(x>m)
}
*/