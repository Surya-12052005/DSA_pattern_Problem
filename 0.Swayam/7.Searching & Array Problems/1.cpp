/*Q1. Binary Search

Question:
Given a sorted array and a value val, find the index of val using Binary Search. If the value is not present, return -1.

Example:
arr = {1, 3, 4, 6, 7, 9, 12}, val = 7
Output: 4*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int val)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == val)
        {
            return mid;
        }
        else if (arr[mid] < val)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 3, 4, 6, 7, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int val = 7;

    int index = binarySearch(arr, n, val);

    if (index != -1)
        cout << "Element found at index: " << index;
    else
        cout << "Element not found";

    return 0;
}