/*Q1. Minimum Spanning Tree (MST)
Question

Given a connected, weighted, undirected graph, find its Minimum Spanning Tree (MST). The MST should connect all vertices with the minimum possible total edge weight and must not contain any cycle.

Important Points
MST contains all vertices.
If there are V vertices, MST contains exactly V - 1 edges.
It should have the minimum total weight.
It should not contain a cycle.
Example

Consider:

        10
    A ------- B
    | \       |
  2 |  4\     | 2
    |     \   |
    C ------- E
       7

We select the minimum-weight edges while avoiding cycles.

Q2. Kruskal's Algorithm
Question

Implement Kruskal's Algorithm in C++ to find the Minimum Spanning Tree of a connected, weighted, undirected graph.

Approach

Kruskal's Algorithm follows:

1. Sort all edges according to weight.
2. Pick the smallest edge.
3. Check whether adding it creates a cycle.
4. If no cycle → include the edge.
5. If cycle → skip the edge.
6. Continue until V - 1 edges are selected.*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Store an edge
struct Edge {
    int u;
    int v;
    int wt;
};

// Find parent
int findParent(int node, vector<int>& parent) {

    if (parent[node] == node) {
        return node;
    }

    return parent[node] = findParent(parent[node], parent);
}

// Union two sets
void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {

    u = findParent(u, parent);
    v = findParent(v, parent);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

int main() {

    int V = 5;

    vector<Edge> edges;

    // Add edges
    edges.push_back({0, 1, 10});
    edges.push_back({0, 2, 2});
    edges.push_back({1, 2, 3});
    edges.push_back({1, 3, 4});
    edges.push_back({1, 4, 2});
    edges.push_back({2, 3, 7});
    edges.push_back({3, 4, 1});

    // Sort edges according to weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.wt < b.wt;
    });

    // Initially every node is its own parent
    vector<int> parent(V);

    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    int totalWeight = 0;

    cout << "Edges in MST:\n";

    int count = 0;

    for (Edge edge : edges) {

        int u = edge.u;
        int v = edge.v;
        int wt = edge.wt;

        // Check if adding edge creates cycle
        if (findParent(u, parent) != findParent(v, parent)) {

            cout << u << " - " << v << " : " << wt << endl;

            totalWeight += wt;

            unionSet(u, v, parent, rank);

            count++;

            // MST has V-1 edges
            if (count == V - 1) {
                break;
            }
        }
    }

    cout << "Minimum Cost = " << totalWeight << endl;

    return 0;
}