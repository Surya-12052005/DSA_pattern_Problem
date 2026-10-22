/*
    Problem   : Maximum Sum Subarray of Size K
    Difficulty: Easy
    Topic     : Sliding Window

    Given an array of integers and a number k, find the maximum sum of
    any contiguous subarray of size k.

    Example:
    Input : arr = [2,1,5,1,3,2], k = 3
    Output: 9   (subarray [5,1,3])

    Approach:
    - Compute the sum of the first window of size k.
    - Slide the window: subtract the element going out, add the element coming in.
    - Track the maximum sum seen.

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int maxSumSubarray(int arr[], int n, int k) {
    if (n < k) {
        // Not enough elements to form a window of size k
        return -1;
    }

    // Step 1: sum of the first window
    int windowSum = 0;
    for (int i = 0; i < k; i++) {
        windowSum += arr[i];
    }

    int maxSum = windowSum;

    // Step 2: slide the window from index k to n-1
    for (int i = k; i < n; i++) {
        windowSum += arr[i];       // add the new element coming into the window
        windowSum -= arr[i - k];   // remove the element going out of the window

        if (windowSum > maxSum) {
            maxSum = windowSum;
        }
    }

    return maxSum;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the value of k (window size): ";
    cin >> k;

    int result = maxSumSubarray(arr, n, k);
    cout << "Maximum sum of subarray of size " << k << " is: " << result << endl;

    return 0;
}

/* 

Index:   0   1   2   3   4   5
Array:  [2,  1,  5,  1,  3,  2]


Initial window (before the loop): covers indices 0,1,2
[2  1  5] 1  3  2      windowSum = 8


i = 3:
windowSum += arr[3]   → 8 + 1  = 9
windowSum -= arr[3-3] → 9 - arr[0] = 9 - 2 = 7

Window slides to indices 1,2,3:
2 [1  5  1] 3  2      windowSum = 7
7 > 8? No → maxSum stays 8

i = 4:
windowSum += arr[4]   → 7 + 3  = 10
windowSum -= arr[4-3] → 10 - arr[1] = 10 - 1 = 9

Window slides to indices 2,3,4:
2  1 [5  1  3] 2      windowSum = 9
9 > 8? Yes → maxSum = 9

i = 5:
windowSum += arr[5]   → 9 + 2  = 11
windowSum -= arr[5-3] → 11 - arr[2] = 11 - 5 = 6

Window slides to indices 3,4,5:
2  1  5 [1  3  2]      windowSum = 6
6 > 9? No → maxSum stays 9
*/