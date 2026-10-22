/*Q2. Find Rotation Point in a Sorted Rotated Array

Question:
A sorted array is rotated by some positions. Find the rotation point (pivot) using Binary Search.

Example:
{1, 2, 3, 4, 5, 6, 7, 8, 9}

After rotation:
{4, 5, 6, 7, 8, 9, 1, 2, 3}

The rotation point is 1, whose index is 6.*/

#include <iostream>
using namespace std;

int findRotationPoint(int arr[], int n)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check if mid is the rotation point
        if (mid < high && arr[mid] > arr[mid + 1])
        {
            return mid + 1;
        }

        // Check if previous element is greater
        if (mid > low && arr[mid - 1] > arr[mid])
        {
            return mid;
        }

        // Left part is sorted
        if (arr[mid] >= arr[low])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    // Array is not rotated
    return 0;
}

int main()
{
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int index = findRotationPoint(arr, n);

    cout << "Rotation point index: " << index << endl;
    cout << "Rotation point value: " << arr[index] << endl;

    return 0;
}