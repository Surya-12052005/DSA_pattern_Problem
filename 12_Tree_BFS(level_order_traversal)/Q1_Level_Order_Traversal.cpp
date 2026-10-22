/*
    Problem   : Binary Tree Level Order Traversal
    Difficulty: Easy
    Topic     : Tree BFS

    Given the root of a binary tree, return the level order traversal
    of its nodes' values (i.e., level by level, left to right).

    Example:
    Input : [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]

    Approach:
    - Use a queue for BFS.
    - Process nodes level by level: record the queue size at the
      start of each level, then pop that many nodes and push their children.

    Time Complexity : O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = levelOrder(root);
    for (auto& level : res) {
        for (int x : level) cout << x << " ";
        cout << endl;
    }
    return 0;
}
