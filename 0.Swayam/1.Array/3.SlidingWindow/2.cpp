/*
Given a binary array, find the minimum number of swaps required to bring 
all 1's together (anywhere in the array).

Example:
Input: arr = [1, 0, 1, 0, 1]
Output: 1
Explanation: Swap index 1 and 4 → [1, 1, 1, 0, 0]. All 1's together in 1 swap.

Key Idea
1.Count total number of 1s in the array — call it k. This is the size of the group we eventually want.
2.Now imagine sliding a window of size k across the array — the goal is to find the window that already contains the maximum number of 1's.
3.Since we only need to "swap in" 0's for 1's (not move things around endlessly), the answer is:
*/

#include <iostream>
using namespace std;

int minSwaps(int arr[], int n)
{
    // Step 1: Count total number of 1's
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1) 
        k++;
    }  

    if (k == 0 || k == n) return 0; // no 1's or all 1's already together   

    // Step 2: Count 1's in first window of size k.  
    int currentOnes = 0;
    for (int i = 0; i < k; i++)
    {
        if (arr[i] == 1) 
        currentOnes++;   
    }

    int maxOnes = currentOnes;

    // Step 3: Slide the window across the array
    for (int i = k; i < n; i++) 
    {
        if (arr[i] == 1) currentOnes++;         // new element enters window
        if (arr[i - k] == 1) currentOnes--;      // old element leaves window

        maxOnes = max(maxOnes, currentOnes);
    }

    // Step 4: Minimum swaps = k - max ones found in any window
    return k - maxOnes;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements (0's and 1's only): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Minimum swaps required = " << minSwaps(arr, n) << endl;

    return 0;
}