/*
    Problem   : Range Sum Query - Mutable (using Binary Indexed Tree / Fenwick Tree)
    Difficulty: Medium
    Topic     : Fenwick Tree (BIT)

    Support point update and prefix sum queries efficiently.
    update(index, val) -> add val at index
    sumRange(l, r)      -> sum of elements from l to r

    Example:
    Input : nums = [1,3,5], update index 1 by +2 (becomes 2->4? see note), sumRange(0,2)

    Approach:
    - BIT stores partial sums; index i is responsible for a range of
      size (i & -i) [lowest set bit].
    - update(i, delta): move up the tree using i += (i & -i), adding
      delta at each node.
    - prefixSum(i): move down using i -= (i & -i), accumulating sum.
    - Range sum [l, r] = prefixSum(r+1) - prefixSum(l).

    Time Complexity : O(log n) per update/query
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
public:
    vector<long long> bit;
    int n;

    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int i, long long delta) { // 0-indexed input
        for (++i; i <= n; i += i & (-i)) bit[i] += delta;
    }

    long long prefixSum(int i) { // sum of first i elements (0-indexed count)
        long long sum = 0;
        for (; i > 0; i -= i & (-i)) sum += bit[i];
        return sum;
    }

    long long rangeSum(int l, int r) { // inclusive, 0-indexed
        return prefixSum(r + 1) - prefixSum(l);
    }
};

int main() {
    vector<int> nums = {1,3,5};
    FenwickTree ft(nums.size());
    for (int i = 0; i < (int)nums.size(); i++) ft.update(i, nums[i]);

    cout << "Sum [0,2]: " << ft.rangeSum(0, 2) << endl; // 9

    ft.update(1, 2 - 3); // change nums[1] from 3 to 2 (delta = -1)
    cout << "Sum [0,2] after update: " << ft.rangeSum(0, 2) << endl; // 8
    return 0;
}
