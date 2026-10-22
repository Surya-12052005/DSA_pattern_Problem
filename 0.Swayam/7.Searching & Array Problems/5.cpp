/*Q5. Count Occurrences of K in a Sorted Array

Question:
Given a sorted array and an integer k, find how many times k occurs in the array.

Example:

arr = {1,2,4,4,4,8,9,9,12,12,12}
k = 4


Output:
3
Approach

Because the array is sorted, use Binary Search to find:

First occurrence of k
Last occurrence of k

Then:

Frequency = Last Index - First Index + 1*/

#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] < k)
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

int lastOccurrence(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] < k)
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

int countOccurrences(int arr[], int n, int k)
{
    int first = firstOccurrence(arr, n, k);

    if (first == -1)
        return 0;

    int last = lastOccurrence(arr, n, k);

    return last - first + 1;
}

int main()
{
    int arr[] = {1, 2, 4, 4, 4, 8, 9, 9, 12, 12, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 4;

    cout << "Number of occurrences: "
         << countOccurrences(arr, n, k);

    return 0;
}