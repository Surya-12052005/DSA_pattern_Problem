/*
    Problem   : Shortest Path in an Unweighted Graph
    Difficulty: Medium
    Topic     : Graph BFS

    Given an unweighted graph with n nodes and a list of edges, find
    the shortest distance from a source node to every other node.

    Example:
    Input : n = 5, edges = [[0,1],[0,2],[1,3],[2,3],[3,4]], src = 0
    Output: dist = [0,1,1,2,3]

    Approach:
    - BFS naturally explores nodes level by level, so the first time
      a node is visited, that is its shortest distance in an unweighted graph.
    - Use a queue starting from src, distance array initialized to -1 (unvisited).

    Time Complexity : O(V + E)
    Space Complexity: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPathBFS(int n, vector<vector<int>>& edges, int src) {
    vector<vector<int>> adj(n);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> dist(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{2,3},{3,4}};
    vector<int> dist = shortestPathBFS(n, edges, 0);
    for (int d : dist) cout << d << " ";
    cout << endl;
    return 0;
}
