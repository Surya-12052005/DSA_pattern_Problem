/*
    Problem   : Range Sum Query - Mutable (Segment Tree)
    Difficulty: Medium
    Topic     : Segment Tree

    Given an array "nums", support two operations:
    1. update(index, val)   -> update nums[index] to val
    2. sumRange(left, right) -> return sum of nums[left..right]

    Example:
    Input : nums = [1,3,5], update(1,2), sumRange(0,2)
    Output: 8   (1+2+5)

    Approach:
    - Build a segment tree where each node stores the sum of a range.
    - update: change a leaf value, then update all its ancestors.
    - query: recursively combine results from segments that overlap
      the query range.

    Time Complexity : O(log n) per update/query, O(n) build
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
public:
    vector<int> tree;
    int n;

    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        if (n > 0) build(nums, 1, 0, n - 1);
    }

    void build(vector<int>& nums, int node, int start, int end) {
        if (start == end) { tree[node] = nums[start]; return; }
        int mid = (start + end) / 2;
        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) { tree[node] = val; return; }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0; // no overlap
        if (l <= start && end <= r) return tree[node]; // total overlap
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
    }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main() {
    vector<int> nums = {1,3,5};
    SegmentTree st(nums);
    cout << st.query(0, 2) << endl; // 9
    st.update(1, 2); // nums[1] = 2
    cout << st.query(0, 2) << endl; // 8
    return 0;
}
