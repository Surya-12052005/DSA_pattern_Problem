/*
    Problem   : Remove Duplicates from Sorted Array
    Difficulty: Easy
    Topic     : Two Pointers (Simple Loop Technique)

    Given a sorted array "arr", remove duplicates in-place such that
    each unique element appears only once, and return the new length.

    Example:
    Input : arr = [1,1,2,2,3]
    Output: 3, arr becomes [1,2,3,_,_]

    Approach:
    - "slow" pointer marks the position of last unique element.
    - "fast" pointer scans the array using a simple for loop.
    - When arr[fast] != arr[slow], increment slow and copy the value.

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
    // Edge case: empty array
    if (n == 0) return 0;

    int slow = 0; // slow points to last unique element found so far

    // simple loop from index 1 to n-1
    for (int fast = 1; fast < n; fast++) {

        // if current element is different from the last unique one
        if (arr[fast] != arr[slow]) {
            slow = slow + 1;       // move slow one step forward
            arr[slow] = arr[fast]; // copy new unique value into that spot
        }
        // else: it's a duplicate, do nothing
    }

    // total unique elements = slow + 1
    return slow + 1;
}

int main() {
    int n;

    // Step 1: ask user for size of array
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100]; // fixed-size array (assuming n <= 100)

    // Step 2: ask user to enter elements (must be sorted!)
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: process
    int newLength = removeDuplicates(arr, n);

    // Step 4: show result
    cout << "New length: " << newLength << endl;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*

Initial setup
arr   = [1, 1, 2, 2, 3]
index =  0  1  2  3  4

n = 5 (not 0, so we continue)
slow = 0   →  arr[slow] = arr[0] = 1



Iteration 1: fast = 1 (STEP C, D, G)

arr[fast] = arr[1] = 1
arr[slow] = arr[0] = 1

Compare: 1 == 1  →  DUPLICATE
Action : do nothing (STEP G)

slow stays = 0
arr = [1, 1, 2, 2, 3]   (unchanged)



Iteration 2: fast = 2 (STEP D, E, F)

arr[fast] = arr[2] = 2
arr[slow] = arr[0] = 1

Compare: 2 != 1  →  NEW UNIQUE VALUE FOUND
Action : slow = slow + 1 = 1        (STEP E)
         arr[slow] = arr[fast]       (STEP F)
         arr[1] = 2

arr = [1, 2, 2, 2, 3]
        ^slow=1



        Iteration 3: fast = 3 (STEP D, G)
        arr[fast] = arr[3] = 2
arr[slow] = arr[1] = 2

Compare: 2 == 2  →  DUPLICATE
Action : do nothing

slow stays = 1
arr = [1, 2, 2, 2, 3]   (unchanged)



Iteration 4: fast = 4 (STEP D, E, F)

arr[fast] = arr[4] = 3
arr[slow] = arr[1] = 2

Compare: 3 != 2  →  NEW UNIQUE VALUE FOUND
Action : slow = slow + 1 = 2
         arr[slow] = arr[fast]
         arr[2] = 3

arr = [1, 2, 3, 2, 3]
           ^slow=2
*/