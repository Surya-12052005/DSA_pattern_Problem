/*
Q3. Rotate First K Elements to the End

Question:
Given an array and an integer k, move the first k elements
to the end of the array while maintaining their relative order.

Example:

Input:
arr = {1,2,3,4,5,6,7,8,9}
k = 3

Output:
{4,5,6,7,8,9,1,2,3}

Approach:
1. Reverse the first k elements.
2. Reverse the remaining elements.
3. Reverse the complete array.
*/

#include <iostream>
#include <algorithm>
using namespace std;

template <size_t N>
void rotateArray(int (&arr)[N], int k)
{
    int n = N;

    k = k % n;

    // Step 1: Reverse first k elements
    reverse(begin(arr), begin(arr) + k);

    // Step 2: Reverse remaining elements
    reverse(begin(arr) + k, begin(arr) + n);

    // Step 3: Reverse complete array
    reverse(begin(arr), begin(arr) + n);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;

    rotateArray(arr, k);

    cout << "Rotated array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}