
/*DFS Traversal of a Graph — C++
Proper Question

Q. Write a C++ program to perform Depth First Search (DFS) traversal of an undirected graph using an adjacency list and recursion. Start the DFS traversal from vertex 0.*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V;                  // Number of vertices
    list<int>* l;           // Adjacency list

public:

    // Constructor
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    // Add edge
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);      // Undirected graph
    }

    // DFS Helper Function
    void dfsHelper(int u, vector<bool>& vis) {

        // Print current vertex
        cout << u << " ";

        // Mark vertex as visited
        vis[u] = true;

        // Visit all neighbours
        for (int v : l[u]) {

            if (!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    // DFS Traversal
    void dfs() {

        int src = 0;                    // Starting vertex

        vector<bool> vis(V, false);     // Visited array

        // Call DFS helper
        dfsHelper(src, vis);

        cout << endl;
    }
};

int main() {

    // Create graph with 5 vertices
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    // Perform DFS
    cout << "DFS : ";
    g.dfs();

    return 0;
}