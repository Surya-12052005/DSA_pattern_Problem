/*
    Problem   : Alien Dictionary (find character order)
    Difficulty: Hard
    Topic     : Topological Sort

    Given a list of words sorted lexicographically according to the
    rules of an alien language, derive the order of characters in
    that alien alphabet.

    Example:
    Input : words = ["wrt","wrf","er","ett","rftt"]
    Output: "wertf"

    Approach:
    - Compare adjacent words to find ordering constraints: the first
      differing character tells us charA comes before charB, forming
      a directed edge charA -> charB.
    - Build a graph of these constraints and perform topological sort
      (Kahn's algorithm) to get a valid character order.

    Time Complexity : O(C)  where C = total length of all words
    Space Complexity: O(1) (bounded by alphabet size, max 26)
*/

#include <bits/stdc++.h>
using namespace std;

string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> indegree;

    for (string& w : words)
        for (char c : w) indegree[c] = 0;

    for (int i = 0; i < (int)words.size() - 1; i++) {
        string& w1 = words[i];
        string& w2 = words[i + 1];
        int minLen = min(w1.size(), w2.size());
        bool foundDiff = false;

        for (int j = 0; j < minLen; j++) {
            if (w1[j] != w2[j]) {
                if (!adj[w1[j]].count(w2[j])) {
                    adj[w1[j]].insert(w2[j]);
                    indegree[w2[j]]++;
                }
                foundDiff = true;
                break;
            }
        }
        // Edge case: w1 is longer but is a prefix of w2's prefix in wrong order -> invalid
        if (!foundDiff && w1.size() > w2.size()) return "";
    }

    queue<char> q;
    for (auto& [c, deg] : indegree)
        if (deg == 0) q.push(c);

    string order;
    while (!q.empty()) {
        char c = q.front(); q.pop();
        order += c;
        for (char next : adj[c]) {
            if (--indegree[next] == 0) q.push(next);
        }
    }

    return (int)order.size() == (int)indegree.size() ? order : "";
}

int main() {
    vector<string> words = {"wrt","wrf","er","ett","rftt"};
    cout << "Alien Order: " << alienOrder(words) << endl;
    return 0;
}
