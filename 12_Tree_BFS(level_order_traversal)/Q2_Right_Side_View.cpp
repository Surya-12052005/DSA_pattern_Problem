/*
    Problem   : Binary Tree Right Side View
    Difficulty: Medium
    Topic     : Tree BFS

    Given the root of a binary tree, imagine standing on the right
    side of it. Return the values of the nodes visible from that side,
    ordered from top to bottom.

    Example:
    Input : [1,2,3,null,5,null,4]
    Output: [1,3,4]

    Approach:
    - BFS level by level.
    - The last node processed at each level is the one visible from the right side.

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

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == size - 1) result.push_back(node->val); // last node of level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> res = rightSideView(root);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
