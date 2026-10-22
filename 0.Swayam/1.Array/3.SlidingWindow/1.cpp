/*
Given an array of integers and a number k, find the maximum sum of any 
contiguous subarray of size k.

Example:
Input: arr = [2, 1, 5, 1, 3, 2], k = 3
Output: 9
Explanation: Subarray [5, 1, 3] has the maximum sum = 9
*/

#include <iostream>
#include <climits>
using namespace std;

int maxSumSlidingWindow(int arr[], int n, int k)
{
    if (n < k) return -1; // edge case

    int windowSum = 0;

    // Step 1: Calculate sum of first window
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Step 2: Slide the window from index k to n-1
    for (int i = k; i < n; i++)
    {
        windowSum += arr[i] - arr[i - k];   // add new element, remove old one
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";  
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cout << "Enter value of k: ";
    cin >> k;

    int result = maxSumSlidingWindow(arr, n, k);

    if (result == -1)
        cout << "Invalid input: k cannot be greater than array size." << endl;
    else
        cout << "Maximum sum of subarray of size " << k << " = " << result << endl;

    return 0;
}