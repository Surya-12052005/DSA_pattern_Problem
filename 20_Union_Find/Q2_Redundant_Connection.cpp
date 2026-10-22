/*
    Problem   : Redundant Connection
    Difficulty: Medium
    Topic     : Union Find (Disjoint Set)

    You are given a graph that started as a tree with n nodes, with one
    additional edge added, creating a cycle. Find the edge that can be
    removed so that the graph becomes a tree again. If multiple answers
    exist, return the one that occurs last in the input.

    Example:
    Input : edges = [[1,2],[1,3],[2,3]]
    Output: [2,3]

    Approach:
    - Process edges one at a time using Union-Find.
    - If the two nodes of an edge already belong to the same set
      (i.e., find(u) == find(v)), this edge creates a cycle - it's the answer.
    - Otherwise, union the two nodes.

    Time Complexity : O(n * alpha(n))
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false; // already connected -> cycle
        parent[rx] = ry;
        return true;
    }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    DSU dsu(n);
    for (auto& edge : edges) {
        if (!dsu.unite(edge[0], edge[1])) return edge; // this edge creates cycle
    }
    return {};
}

int main() {
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<int> res = findRedundantConnection(edges);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
