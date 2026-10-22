/*Q2. Move All Negative Numbers to the Beginning of an Array
Question

Given an array, rearrange it so that all negative numbers come first, followed by positive numbers.

Example:

Input:  [2, -4, 5, -7, 8, -1, 3]

Output: [-1, -4, -7, 5, 8, 2, 3]

The exact order may be different because we are using partitioning.

Concept

This is similar to the partition step of Quick Sort.

We divide the array into:

Negative numbers | Positive numbers */

#include <bits/stdc++.h>
using namespace std;

void moveNegativeFirst(vector<int>& arr)
{
    int i = 0;
    int j = arr.size() - 1;

    while (i < j)
    {
        // Find positive number from left
        while (i < j && arr[i] < 0)
        {
            i++;
        }

        // Find negative number from right
        while (i < j && arr[j] >= 0)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    vector<int> arr = {2, -4, 5, -7, 8, -1, 3};

    moveNegativeFirst(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
/*Time  : O(n)
Space : O(1)*/