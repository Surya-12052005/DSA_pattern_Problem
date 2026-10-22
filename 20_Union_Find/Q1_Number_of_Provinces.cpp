/*
    Problem   : Number of Provinces
    Difficulty: Medium
    Topic     : Union Find (Disjoint Set)

    There are n cities. isConnected[i][j] = 1 if city i and city j are
    directly connected. A province is a group of directly or indirectly
    connected cities. Return the total number of provinces.

    Example:
    Input : isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    Output: 2

    Approach:
    - Use Union-Find (Disjoint Set Union) with path compression and
      union by rank for efficiency.
    - Union every pair of directly connected cities.
    - Count the number of distinct roots (parents) at the end.

    Time Complexity : O(n^2 * alpha(n))  -- near O(n^2)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank_;
    DSU(int n) {
        parent.resize(n);
        rank_.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // path compression
        return parent[x];
    }
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (rank_[rx] < rank_[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank_[rx] == rank_[ry]) rank_[rx]++;
    }
};

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    DSU dsu(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (isConnected[i][j] == 1) dsu.unite(i, j);

    unordered_set<int> roots;
    for (int i = 0; i < n; i++) roots.insert(dsu.find(i));
    return roots.size();
}

int main() {
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    cout << "Number of Provinces: " << findCircleNum(isConnected) << endl;
    return 0;
}
