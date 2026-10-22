/*Q1. Binary Search in a Sorted Array
Question

Write a function bSearch() to search an element in a sorted array using Binary Search.
*/

#include <iostream>
using namespace std;

bool bSearch(int a[], int n, int val)
{
    int L = 0;
    int H = n - 1;

    while (L <= H)
    {
        int m = (L + H) / 2;

        // CND1: Element found
        if (a[m] == val)
            return true;

        // CND2: Search in right half
        if (a[m] < val)
            L = m + 1;

        // CND3: Search in left half
        else
            H = m - 1;
    }

    return false;
}

int main()
{
    int a[] = {1, 5, 10, 15, 18};
    int n = 5;

    int val = 10;

    if (bSearch(a, n, val))
        cout << "Element found";
    else
        cout << "Element not found";

    return 0;
}