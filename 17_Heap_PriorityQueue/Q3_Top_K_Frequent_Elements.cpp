/*
    Problem   : Top K Frequent Elements
    Difficulty: Medium
    Topic     : Heap / Priority Queue

    Given an integer array "nums" and an integer k, return the k most
    frequent elements.

    Example:
    Input : nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]

    Approach:
    - Count frequency of each element using a hashmap.
    - Use a min-heap of size k based on frequency.
    - Push (frequency, value) pairs; if heap exceeds size k, pop smallest.
    - Remaining elements in heap are the top k frequent ones.

    Time Complexity : O(n log k)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;

    // min-heap of (frequency, value)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

    for (auto& [val, count] : freq) {
        minHeap.push({count, val});
        if ((int)minHeap.size() > k) minHeap.pop();
    }

    vector<int> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = topKFrequent(nums, k);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
