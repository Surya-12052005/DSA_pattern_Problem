/*
    Problem   : Kth Smallest Element Present So Far (using BIT / order statistics)
    Difficulty: Medium
    Topic     : Fenwick Tree (BIT)

    Given a stream of numbers in range [1, maxVal], support:
    1. add(x)      -> mark x as present
    2. findKth(k)  -> find the kth smallest number currently present

    Approach:
    - Use a BIT where index x stores 1 if present.
    - add(x): update BIT at position x with +1.
    - findKth(k): binary search over the BIT using prefixSum(mid) to
      find the smallest index whose prefix count == k (order-statistics
      technique, sometimes called "BIT walk" or binary lifting on BIT).

    Time Complexity : O(log^2(maxVal)) using binary search, or O(log(maxVal)) with BIT walk
    Space Complexity: O(maxVal)
*/

#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
public:
    vector<int> bit;
    int n;
    FenwickTree(int size) { n = size; bit.assign(n + 1, 0); }

    void update(int i, int delta) {
        for (; i <= n; i += i & (-i)) bit[i] += delta;
    }
    int prefixSum(int i) {
        int sum = 0;
        for (; i > 0; i -= i & (-i)) sum += bit[i];
        return sum;
    }

    // Binary search for smallest index with prefixSum(index) >= k
    int findKth(int k) {
        int lo = 1, hi = n, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (prefixSum(mid) >= k) { ans = mid; hi = mid - 1; }
            else lo = mid + 1;
        }
        return ans;
    }
};

int main() {
    int maxVal = 10;
    FenwickTree ft(maxVal);

    ft.update(3, 1);
    ft.update(7, 1);
    ft.update(5, 1);

    cout << "1st smallest: " << ft.findKth(1) << endl; // 3
    cout << "2nd smallest: " << ft.findKth(2) << endl; // 5
    cout << "3rd smallest: " << ft.findKth(3) << endl; // 7
    return 0;
}
