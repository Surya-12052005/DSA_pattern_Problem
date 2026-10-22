/*Q4. Print All Possible Paths in a Graph
Question

Given a directed graph and two vertices source and destination, print all possible paths from the source vertex to the destination vertex using backtracking.

Example
        1
       / \
      ↓   ↓
     2     3
      \   / \
       ↓ ↓   ↓
        4     5
         \   /
          ↓ ↓
           6

Possible paths from 1 to 6:

1 → 2 → 4 → 6
1 → 3 → 4 → 6
1 → 3 → 5 → 6*/

#include <iostream>
#include <vector>
using namespace std;

void printPaths(vector<vector<int>>& graph,
                int current,
                int destination,
                vector<bool>& visited,
                vector<int>& path) {

    // Add current vertex
    path.push_back(current);

    // Destination reached
    if (current == destination) {

        for (int node : path) {
            cout << node << " ";
        }

        cout << endl;

        path.pop_back();
        return;
    }

    visited[current] = true;

    // Visit neighbours
    for (int next : graph[current]) {

        if (!visited[next]) {

            printPaths(graph, next,
                       destination,
                       visited,
                       path);
        }
    }

    // Backtrack
    visited[current] = false;

    path.pop_back();
}

int main() {

    int V = 7;

    vector<vector<int>> graph(V);

    graph[1].push_back(2);
    graph[1].push_back(3);

    graph[2].push_back(4);

    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(6);
    graph[5].push_back(6);

    vector<bool> visited(V, false);
    vector<int> path;

    cout << "All paths from 1 to 6:\n";

    printPaths(graph, 1, 6, visited, path);

    return 0;
}