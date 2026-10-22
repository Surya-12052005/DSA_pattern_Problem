/*Q2. Search an Element in a Row-wise Sorted Matrix

The matrix shown in your picture is:

1   5   10   15   18
2   7   12   17   19
4   9   16   21   23
6   11  20   26   29
8   13  25   30   35

Each row is sorted.

Question

Search an element in a row-wise sorted 2D array using Binary Search.

Solution

We can apply Binary Search separately on every row.*/

#include <iostream>
using namespace std;

bool bSearch(int a[], int n, int val)
{
    int L = 0;
    int H = n - 1;

    while (L <= H)
    {
        int m = (L + H) / 2;

        if (a[m] == val)
            return true;

        if (a[m] < val)
            L = m + 1;
        else
            H = m - 1;
    }

    return false;
}

bool searchMatrix(int a[][5], int n, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (bSearch(a[i], n, val))
            return true;
    }

    return false;
}

int main()
{
    int a[5][5] =
    {
        {1, 5, 10, 15, 18},
        {2, 7, 12, 17, 19},
        {4, 9, 16, 21, 23},
        {6, 11, 20, 26, 29},
        {8, 13, 25, 30, 35}
    };

    int val = 20;

    if (searchMatrix(a, 5, val))
        cout << "Element found";
    else
        cout << "Element not found";

    return 0;
}

/*Complexity

There are n rows and Binary Search on each row takes O(log n).

Therefore:

Time Complexity = O(n log n)

Space Complexity = O(1)*/