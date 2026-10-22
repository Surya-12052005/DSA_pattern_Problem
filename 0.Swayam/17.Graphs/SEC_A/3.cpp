/*Q7. Minimum Spanning Tree Using Prim's Algorithm
Question

Given a connected, weighted, undirected graph with V vertices and E edges, write a C++ program to find its Minimum Spanning Tree (MST) using Prim's Algorithm. Print the edges selected for the MST and the minimum total cost.

Example Graph

We will use the same type of graph from your notes:

             10
        0 -------- 1
        | \        | \
       2|  \3      |4 \2
        |   \      |   \
        2 --- 3----+----4
             7       1

For simplicity, the edges are:

0 -- 1 : 10
0 -- 2 : 2
1 -- 2 : 3
1 -- 3 : 4
1 -- 4 : 2
2 -- 3 : 7
3 -- 4 : 1*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int V = 5;

    // Adjacency list
    vector<vector<pair<int, int>>> graph(V);

    // Add edges
    graph[0].push_back({1, 10});
    graph[1].push_back({0, 10});

    graph[0].push_back({2, 2});
    graph[2].push_back({0, 2});

    graph[1].push_back({2, 3});
    graph[2].push_back({1, 3});

    graph[1].push_back({3, 4});
    graph[3].push_back({1, 4});

    graph[1].push_back({4, 2});
    graph[4].push_back({1, 2});

    graph[2].push_back({3, 7});
    graph[3].push_back({2, 7});

    graph[3].push_back({4, 1});
    graph[4].push_back({3, 1});

    // Minimum weight, vertex
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // Visited array
    vector<bool> vis(V, false);

    // Start from vertex 0
    pq.push({0, 0});

    int totalCost = 0;

    cout << "Edges in MST:\n";

    while (!pq.empty()) {

        int wt = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        // If already visited, skip
        if (vis[u]) {
            continue;
        }

        // Mark visited
        vis[u] = true;

        // Add edge weight to MST cost
        totalCost += wt;

        // Visit all neighbours
        for (auto edge : graph[u]) {

            int v = edge.first;
            int weight = edge.second;

            if (!vis[v]) {
                pq.push({weight, v});
            }
        }

        // Print selected edge weight
        if (wt != 0) {
            cout << "Vertex " << u
                 << " with edge weight " << wt << endl;
        }
    }

    cout << "Minimum Cost = " << totalCost << endl;

    return 0;
}