/*Q1. Move All Odd Numbers to the Beginning of an Array
Question

Given an array, rearrange it so that all odd numbers come first, followed by all even numbers.

Example:

Input:  [5, 1, 3, 2, 4, 8, 6, 7, 9]

Output: [5, 1, 3, 7, 9, 2, 4, 8, 6]
Concept

We use the Two Pointer / Partition technique.

i starts from the left.
j starts from the right.
Find an even number from the left.
Find an odd number from the right.
Swap them. */

#include <bits/stdc++.h>
using namespace std;

void moveOddFirst(vector<int>& arr)
{
    int i = 0;
    int j = arr.size() - 1;

    while (i < j)
    {
        // Find even number from left
        while (i < j && arr[i] % 2 != 0)
        {
            i++;
        }

        // Find odd number from right
        while (i < j && arr[j] % 2 == 0)
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
    vector<int> arr = {5, 1, 3, 2, 4, 8, 6, 7, 9};

    moveOddFirst(arr);

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}

/*Time  : O(n)
Space : O(1)*/