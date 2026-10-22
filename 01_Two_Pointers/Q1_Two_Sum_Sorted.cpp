/*
    Problem   : Two Sum II - Input Array Is Sorted
    Difficulty: Easy
    Topic     : Two Pointers

    Given a 1-indexed array of integers "arr" sorted in ascending order,
    find two numbers such that they add up to a specific "target" number.
    Return the indices (1-indexed) of the two numbers as an array [i, j].

    Example:
    Input : arr = [2, 7, 11, 15], target = 9
    Output: [1, 2]   (arr[0] + arr[1] = 2 + 7 = 9)

    Approach:
    - Since the array is sorted, use two pointers: left at start, right at end.
    - If sum == target, answer found.
    - If sum < target, move left pointer right (increase sum).
    - If sum > target, move right pointer left (decrease sum).

    Time Complexity : O(n)
    Space Complexity: O(1)
*/
#include <iostream>
using namespace std;

int main() {
    // Step 1: Take input size of array
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Step 2: Create array and take input values
    int arr[n];
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: Take target sum
    int target;
    cout << "Enter target sum: ";
    cin >> target;

    // Step 4: Set two pointers
    // left pointer starts from beginning
    // right pointer starts from end
    int left = 0;
    int right = n - 1;

    // Step 5: Variables to store the answer indices
    int index1 = -1, index2 = -1;

    // Step 6: Move pointers until they cross each other
    while (left < right) {

        int sum = arr[left] + arr[right]; // current sum of two numbers

        if (sum == target) {
            // Found the answer
            index1 = left;
            index2 = right;
            break; // stop the loop since we found the answer
        }
        else if (sum < target) {
            // Sum is too small, so increase it
            // Move left pointer to the right
            left++;
        }
        else {
            // Sum is too big, so decrease it
            // Move right pointer to the left
            right--;
        }
    }


    // Step 7: Print the result (1-indexed as required)
    if (index1 != -1 && index2 != -1) {
        cout << "Indices: [" << index1 + 1 << ", " << index2 + 1 << "]" << endl;
    } else {
        cout << "No solution found" << endl;  
    }

    return 0;   
}




