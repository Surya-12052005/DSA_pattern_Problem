/*
    Problem   : Accounts Merge (simplified version)
    Difficulty: Medium
    Topic     : Union Find (Disjoint Set)

    Given a list of accounts where accounts[i][0] is the name and the
    rest are emails, merge accounts that share at least one common
    email (they belong to the same person), then return each person's
    merged, sorted list of emails.

    Approach:
    - Map each unique email to an index; use Union-Find to union all
      emails that appear together in the same account.
    - Group emails by their root parent.
    - Attach the account name and sort emails for each group.

    Time Complexity : O(N * K log(N*K))  N=accounts, K=avg emails per account
    Space Complexity: O(N * K)
*/

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx != ry) parent[rx] = ry;
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, int> emailToId;
    unordered_map<string, string> emailToName;
    int id = 0;

    for (auto& account : accounts) {
        string name = account[0];
        for (int i = 1; i < (int)account.size(); i++) {
            if (!emailToId.count(account[i])) emailToId[account[i]] = id++;
            emailToName[account[i]] = name;
        }
    }

    DSU dsu(id);
    for (auto& account : accounts) {
        int firstId = emailToId[account[1]];
        for (int i = 2; i < (int)account.size(); i++) {
            dsu.unite(firstId, emailToId[account[i]]);
        }
    }

    unordered_map<int, set<string>> groups;
    for (auto& [email, eid] : emailToId) {
        groups[dsu.find(eid)].insert(email);
    }

    vector<vector<string>> result;
    for (auto& [root, emails] : groups) {
        vector<string> merged;
        string name = emailToName[*emails.begin()];
        merged.push_back(name);
        for (auto& e : emails) merged.push_back(e);
        result.push_back(merged);
    }
    return result;
}

int main() {
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"}
    };
    vector<vector<string>> res = accountsMerge(accounts);
    for (auto& acc : res) {
        for (auto& s : acc) cout << s << " ";
        cout << endl;
    }
    return 0;
}
