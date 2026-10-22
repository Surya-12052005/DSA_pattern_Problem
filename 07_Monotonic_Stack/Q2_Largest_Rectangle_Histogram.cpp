/*
    Problem   : Largest Rectangle in Histogram
    Difficulty: Hard (frequent in campus rounds)
    Topic     : Monotonic Stack

    Given an array of heights representing a histogram, find the area
    of the largest rectangle that can be formed within the histogram.

    Example:
    Input : heights = [2,1,5,6,2,3]
    Output: 10

    Approach:
    - Maintain a stack of indices with increasing heights.
    - When a smaller height is found, pop from stack and calculate
      area using popped height as the smallest bar, with width
      determined by current index and new stack top.

    Time Complexity : O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st; // indices
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!st.empty() && heights[st.top()] >= h) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Max Area: " << largestRectangleArea(heights) << endl;
    return 0;
}
