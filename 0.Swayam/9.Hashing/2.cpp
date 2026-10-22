/*Q3. Find the Row Having Maximum Number of 1s

The second picture shows a binary matrix where every row is sorted:

0  0  1  1  1
0  0  0  0  0
0  0  0  1  1
0  1  1  1  1
0  0  1  1  1
Question

Given a binary matrix in which every row is sorted, find the row having the maximum number of 1s.*/

/*Method 2: Optimized Approach

Since every row is sorted, we don't need to scan every element.

Start from the top-right corner.

0  0  1  1  1  ← start

Rules:

If current element is 1, move left.
If current element is 0, move down.*/

#include <iostream>
using namespace std;

int maxOnesRow(int a[][5], int n, int m)
{
    int row = 0;
    int col = m - 1;

    int ans = -1;

    while (row < n && col >= 0)
    {
        if (a[row][col] == 1)
        {
            ans = row;
            col--;
        }
        else
        {
            row++;
        }
    }

    return ans;
}

int main()
{
    int a[5][5] =
    {
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 1, 1, 1}
    };

    int row = maxOnesRow(a, 5, 5);

    cout << "Row with maximum number of 1s = " << row;

    return 0;
}

/*Time  = O(n + m)
Space = O(1)*/