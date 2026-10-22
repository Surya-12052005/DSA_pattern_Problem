/*Part A — Graph / Matrix Problems
Problem 1. Count the Number of Islands

Problem Statement:
Given a 6 × 6 binary matrix where:

1 represents land
0 represents water

An island is a group of connected 1s. For this problem, consider 4-directional connectivity: up, down, left, and right.

Find the total number of islands present in the matrix.

Example
1 1 0 0 0 1
1 0 0 1 1 0
0 0 1 0 0 0
1 1 0 0 1 1
0 0 0 1 1 0
1 0 1 0 0 0*/

#include <iostream>
using namespace std;

int m = 6, n = 6;

void dfs(int a[][6], int i, int j)
{
    // Boundary condition
    if(i < 0 || i >= m || j < 0 || j >= n)
        return;

    // If water or already visited
    if(a[i][j] != 1)
        return;

    // Mark island cell as visited
    a[i][j] = 2;

    // Move up
    dfs(a, i - 1, j);

    // Move down
    dfs(a, i + 1, j);

    // Move left
    dfs(a, i, j - 1);

    // Move right
    dfs(a, i, j + 1);
}

int countIslands(int a[][6])
{
    int count = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(a[i][j] == 1)
            {
                count++;

                // Visit complete island
                dfs(a, i, j);
            }
        }
    }

    return count;
}

int main()
{
    int a[6][6] =
    {
        {1, 1, 0, 0, 0, 1},
        {1, 0, 0, 1, 1, 0},
        {0, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 0, 0}
    };

    cout << "Number of islands = "
         << countIslands(a);

    return 0;
}

/*given a matrix 6*6, 1 represent the island , and null value represent the water , 
1. find the no of island present( hint : once traverse the island ->change 1 to 2)
2. find the size of largest/smallest island
*3. **we can make one ero to one(0->1), then find the biggest island which will be made by changing one zero to one(0->1)
*/
/*
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        if(a[i][j]==1)
        dfs(i,j);
        cnt++;
    }
}


void dfs(int i;int j){
    
}*/