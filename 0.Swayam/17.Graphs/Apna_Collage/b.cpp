
/*Question: Implement an Undirected Graph Using an Adjacency List in C++

Problem Statement:
Write a C++ program to implement an undirected graph using an adjacency list. The program should:

1.Create a graph with V vertices.
2.Add edges between vertices using an addEdge() function.
3.Display the adjacency list of the graph using printAdjList().*/

#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;              // Number of vertices
    list<int>* l;       // Array of linked lists     

public:

    // Constructor
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    // Function to add an edge
    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);   // Undirected graph
    }

    // Function to print adjacency list
    void printAdjList() {
        for (int i = 0; i < V; i++) {

            cout << i << " : ";

            for (int neigh : l[i]) {
                cout << neigh << " ";
            }

            cout << endl;
        }
    }
};

int main() {

    // Create graph with 5 vertices: 0, 1, 2, 3, 4
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    // Display adjacency list
    g.printAdjList();

    return 0;
}
