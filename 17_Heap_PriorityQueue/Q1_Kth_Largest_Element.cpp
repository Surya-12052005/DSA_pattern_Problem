/*
    Problem   : Kth Largest Element in an Array
    Difficulty: Medium
    Topic     : Heap / Priority Queue

    Given an integer array "nums" and integer k, return the kth
    largest element in the array.

    Example:
    Input : nums = [3,2,1,5,6,4], k = 2
    Output: 5

    Approach:
    - Maintain a min-heap of size k.
    - Push elements one by one; if heap size exceeds k, pop the smallest.
    - After processing all elements, the top of the heap is the kth largest.

    Time Complexity : O(n log k)
    Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if ((int)minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << "Kth Largest: " << findKthLargest(nums, k) << endl;
    return 0;
}
