/*
    Problem   : Number of Connected Components in an Undirected Graph
    Difficulty: Medium
    Topic     : Graph DFS

    Given n nodes labeled 0..n-1 and a list of undirected edges, find
    the number of connected components.

    Example:
    Input : n = 5, edges = [[0,1],[1,2],[3,4]]
    Output: 2

    Approach:
    - Build an adjacency list from the edges.
    - For each unvisited node, run DFS to mark its entire component
      as visited, and increment the component count.

    Time Complexity : O(V + E)
    Space Complexity: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) dfs(neighbor, adj, visited);
    }
}

int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }
    return components;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{3,4}};
    cout << "Connected components: " << countComponents(n, edges) << endl;
    return 0;
}
