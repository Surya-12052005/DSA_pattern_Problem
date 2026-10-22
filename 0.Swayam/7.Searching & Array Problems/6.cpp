/*Q6. Find First Occurrence of an Element

Question:
Given a sorted array and a value val, find the first occurrence of val using Binary Search.

Example:

arr = {1,2,4,4,4,8,9,9,12,12,12}
val = 4


Output:
First occurrence index = 2*/

#include <iostream>
using namespace std;

int getFirstOcc(int arr[], int n, int val)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == val)
        {
            ans = mid;

            // Search for an earlier occurrence
            high = mid - 1;
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

    return ans;
}

int main()
{
    int arr[] = {1, 2, 4, 4, 4, 8, 9, 9, 12, 12, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int val = 4;

    int index = getFirstOcc(arr, n, val);

    if (index != -1)
        cout << "First occurrence is at index: " << index;
    else
        cout << "Element not found";

    return 0;
}
