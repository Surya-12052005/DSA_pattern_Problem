/*
    Problem   : Clone Graph
    Difficulty: Medium
    Topic     : Graph DFS

    Given a reference to a node in a connected undirected graph, return
    a deep copy (clone) of the graph.

    Approach:
    - Use DFS with a hashmap (original node -> cloned node) to avoid
      cloning the same node twice and to handle cycles.
    - For each neighbor of a node, recursively clone it if not already done.

    Time Complexity : O(V + E)
    Space Complexity: O(V)
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val) : val(_val) {}
};

Node* cloneGraph(Node* node, unordered_map<Node*, Node*>& visited) {
    if (!node) return nullptr;
    if (visited.count(node)) return visited[node];

    Node* clone = new Node(node->val);
    visited[node] = clone;

    for (Node* neighbor : node->neighbors) {
        clone->neighbors.push_back(cloneGraph(neighbor, visited));
    }
    return clone;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> visited;
    return cloneGraph(node, visited);
}

int main() {
    // Build a small graph: 1 - 2 - 3 - 1 (triangle)
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    n1->neighbors = {n2, n3};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n1, n2};

    Node* cloned = cloneGraph(n1);
    cout << "Cloned node value: " << cloned->val << ", neighbors: ";
    for (auto nb : cloned->neighbors) cout << nb->val << " ";
    cout << endl;
    return 0;
}
