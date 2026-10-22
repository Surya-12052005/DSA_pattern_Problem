/*
    Problem   : Course Schedule
    Difficulty: Medium
    Topic     : Topological Sort

    There are numCourses courses labeled 0 to numCourses-1. Given
    prerequisites[i] = [a, b] meaning you must take course b before a,
    determine if you can finish all courses (i.e., no cycle exists).

    Example:
    Input : numCourses = 2, prerequisites = [[1,0]]
    Output: true

    Approach:
    - Model as a directed graph; detecting a cycle means it's impossible.
    - Use Kahn's Algorithm (BFS-based topological sort):
      compute in-degree for each node, start with in-degree 0 nodes,
      remove them one by one reducing neighbors' in-degree.
    - If all nodes get processed, no cycle exists.

    Time Complexity : O(V + E)
    Space Complexity: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    for (auto& p : prerequisites) {
        adj[p[1]].push_back(p[0]); // b -> a
        indegree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (indegree[i] == 0) q.push(i);

    int processed = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        processed++;
        for (int next : adj[node]) {
            if (--indegree[next] == 0) q.push(next);
        }
    }
    return processed == numCourses;
}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    cout << (canFinish(numCourses, prerequisites) ? "true" : "false") << endl;
    return 0;
}
