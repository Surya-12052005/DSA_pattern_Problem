/*
    Problem   : Is Graph Bipartite? (using BFS coloring)
    Difficulty: Medium
    Topic     : Graph BFS

    Given an undirected graph, determine if it is bipartite, i.e., can
    the nodes be colored with 2 colors such that no two adjacent nodes
    have the same color.

    Example:
    Input : graph = [[1,3],[0,2],[1,3],[0,2]]
    Output: true

    Approach:
    - Use BFS to 2-color the graph.
    - Start each uncolored component with color 0.
    - For each neighbor, if uncolored, assign opposite color and push
      to queue; if already colored with the SAME color as current node,
      graph is not bipartite.

    Time Complexity : O(V + E)
    Space Complexity: O(V)
*/

#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1); // -1 = uncolored

    for (int i = 0; i < n; i++) {
        if (color[i] != -1) continue;

        queue<int> q;
        q.push(i);
        color[i] = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    cout << (isBipartite(graph) ? "true" : "false") << endl;
    return 0;
}
