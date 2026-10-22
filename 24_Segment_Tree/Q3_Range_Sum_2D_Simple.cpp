/*
    Problem   : Lazy Propagation Segment Tree (Range Update, Range Sum)
    Difficulty: Hard
    Topic     : Segment Tree

    Support two operations efficiently on an array:
    1. update(l, r, val) -> add val to every element in range [l, r]
    2. query(l, r)       -> get sum of elements in range [l, r]

    Approach:
    - Standard segment tree, but with lazy propagation to defer
      range updates instead of updating every leaf immediately.
    - Each node stores accumulated pending updates in "lazy[]".
    - Before recursing into children, "push down" any pending lazy value.

    Time Complexity : O(log n) per update/query
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class LazySegmentTree {
public:
    vector<long long> tree, lazy;
    int n;

    LazySegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    void pushDown(int node, int start, int end) {
        if (lazy[node] != 0) {
            int mid = (start + end) / 2;
            for (int child : {2 * node, 2 * node + 1}) {
                lazy[child] += lazy[node];
            }
            tree[2 * node] += lazy[node] * (mid - start + 1);
            tree[2 * node + 1] += lazy[node] * (end - mid);
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            tree[node] += val * (end - start + 1);
            lazy[node] += val;
            return;
        }
        pushDown(node, start, end);
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void updateRange(int l, int r, long long val) { updateRange(1, 0, n - 1, l, r, val); }

    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        pushDown(node, start, end);
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
    }
    long long query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main() {
    LazySegmentTree st(6); // array of size 6, initially all zero
    st.updateRange(1, 3, 5);   // add 5 to indices [1,3]
    st.updateRange(2, 4, 3);   // add 3 to indices [2,4]
    cout << "Sum [0,5]: " << st.query(0, 5) << endl; // 5+5+8+8+3 = 29
    cout << "Sum [2,2]: " << st.query(2, 2) << endl; // 5+3 = 8
    return 0;
}
