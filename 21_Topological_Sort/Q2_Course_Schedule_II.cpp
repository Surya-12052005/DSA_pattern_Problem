/*
    Problem   : Course Schedule II
    Difficulty: Medium
    Topic     : Topological Sort

    Same setup as Course Schedule, but return the actual order in
    which courses should be taken. Return an empty array if impossible.

    Example:
    Input : numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
    Output: [0,1,2,3]  (one valid order)

    Approach:
    - Kahn's Algorithm: same as Course Schedule, but this time we
      record the order in which nodes are processed.
    - If the recorded order's length != numCourses, a cycle exists
      -> return empty array.

    Time Complexity : O(V + E)
    Space Complexity: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    for (auto& p : prerequisites) {
        adj[p[1]].push_back(p[0]);
        indegree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
        if (indegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);
        for (int next : adj[node]) {
            if (--indegree[next] == 0) q.push(next);
        }
    }
    if ((int)order.size() != numCourses) return {};
    return order;
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> res = findOrder(numCourses, prerequisites);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
