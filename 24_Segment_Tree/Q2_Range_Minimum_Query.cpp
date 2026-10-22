/*
    Problem   : Range Minimum Query (Segment Tree)
    Difficulty: Medium
    Topic     : Segment Tree

    Given an array, support queries that ask for the minimum value in
    a given range [l, r], with point updates allowed.

    Example:
    Input : arr = [1,3,2,7,9,11,5], query(1,5)
    Output: 2

    Approach:
    - Build a segment tree where each node stores the minimum of a range.
    - Same recursive build/update/query pattern as Range Sum Query,
      but combine children using min() instead of sum.

    Time Complexity : O(log n) per update/query, O(n) build
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class SegmentTreeMin {
public:
    vector<int> tree;
    int n;
    const int INF = INT_MAX;

    SegmentTreeMin(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        if (n > 0) build(arr, 1, 0, n - 1);
    }

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) { tree[node] = arr[start]; return; }
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) { tree[node] = val; return; }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return INF;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return min(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
    }
    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main() {
    vector<int> arr = {1,3,2,7,9,11,5};
    SegmentTreeMin st(arr);
    cout << "Min in [1,5]: " << st.query(1, 5) << endl; // 2
    return 0;
}
