/*
    Problem   : Binary Tree Zigzag Level Order Traversal
    Difficulty: Medium
    Topic     : Tree BFS

    Return the zigzag level order traversal of a binary tree's node
    values (left to right, then right to left for the next level, alternating).

    Example:
    Input : [3,9,20,null,null,15,7]
    Output: [[3],[20,9],[15,7]]

    Approach:
    - Standard BFS level order traversal.
    - Reverse the order of values for every alternate level.

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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->val;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
        leftToRight = !leftToRight;
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> res = zigzagLevelOrder(root);
    for (auto& level : res) {
        for (int x : level) cout << x << " ";
        cout << endl;
    }
    return 0;
}
