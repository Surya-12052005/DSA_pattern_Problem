/*
    Problem   : Container With Most Water
    Difficulty: Medium
    Topic     : Two Pointers

    Given n non-negative integers height[0..n-1], where each represents
    a point (i, height[i]), find two lines that together with the x-axis
    form a container that holds the most water.

    Example:
    Input : height = [1,8,6,2,5,4,8,3,7]
    Output: 49

    Approach:
    - Use two pointers at both ends.
    - Area = min(height[l], height[r]) * (r - l).
    - Move the pointer pointing to the smaller height inward,
      since moving the larger one can never increase the area.

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Step 1: Take input size
    int n;
    cout << "Enter number of lines: ";
    cin >> n;

    // Step 2: Take heights of each line
    vector<int> height(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    // Step 3: Set two pointers at both ends
    int left = 0;
    int right = n - 1;

    // Step 4: Variable to store the best (maximum) area found so far
    int maxArea = 0;

    // Step 5: Move pointers toward each other until they meet
    while (left < right) {

        // Width = distance between the two lines
        int width = right - left;

        // Height = limited by the SHORTER line (water spills over shorter side)
        int minHeight = min(height[left], height[right]);

        // Current area formed by these two lines
        int currentArea = width * minHeight;

        // Update maxArea if this one is bigger
        maxArea = max(maxArea, currentArea);

        // Move the pointer with the SMALLER height inward
        // (moving the taller one can never help, only hurt)
        if (height[left] < height[right]) {
            left++;   // left line is shorter, move it right
        } else {
            right--;  // right line is shorter (or equal), move it left
        }
    }

    // Step 6: Print the final answer
    cout << "Maximum water container area: " << maxArea << endl;

    return 0;
}