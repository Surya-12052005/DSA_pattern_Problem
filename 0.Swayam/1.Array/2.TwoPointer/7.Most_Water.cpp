/*LeetCode 11 — Container With Most Water
Problem Statement

You are given an integer array height of length n.

There are n vertical lines such that the two endpoints of the i-th line are at:

(i, 0) and (i, height[i])

Choose two lines that, together with the x-axis, form a container that holds the most water.

Return the maximum amount of water that the container can store.

Important

You cannot slant the container.

Example 1

Input:

height = [1,8,6,2,5,4,8,3,7]

Output:

49*/
#include <iostream>
using namespace std;
#include <vector>


int maxArea(vector<int> &height)
{
    int L = 0;
    int R = height.size() - 1;
    int maxArea = 0;
    int currArea = 0;

    while (L < R)
    {
        currArea = (R - L) * min(height[L], height[R]);
        maxArea = max(maxArea, currArea);
        if (height[L] < height[R])
            L++;
        else
            R--;
    }
    return maxArea;
}

int main()
{
}