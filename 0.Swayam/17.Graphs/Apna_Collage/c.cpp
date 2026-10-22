/*BFS Traversal of a Graph — C++
Proper Question

Q. Write a C++ program to perform Breadth First Search (BFS) traversal of an undirected graph using an adjacency list and a queue. 
Start the BFS traversal from vertex 0.*/

#include <iostream>
#include <vector>
#include <list>
#include <queue>

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

    // BFS Traversal
    void bfs() {

        queue<int> Q;

        // To keep track of visited vertices  
        vector<bool> vis(V, false);

        // Start BFS from vertex 0  
        Q.push(0);
        vis[0] = true;

        while (Q.size() > 0) {

            // Get front vertex
            int u = Q.front();

            // Remove it from queue
            Q.pop();

            // Print vertex
            cout << u << " ";

            // Visit all immediate neighbours
            for (int v : l[u]) {

                if (!vis[v]) {

                    vis[v] = true;
                    Q.push(v);
                }
            }
        }

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

    // Perform BFS traversal
    g.bfs();

    return 0;
}