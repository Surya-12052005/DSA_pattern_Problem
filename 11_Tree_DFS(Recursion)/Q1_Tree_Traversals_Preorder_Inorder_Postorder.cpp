/*
    Problem   : Binary Tree Preorder / Inorder / Postorder Traversal
    Difficulty: Easy
    Topic     : Tree DFS

    Given the root of a binary tree, return preorder, inorder, and
    postorder traversal of its node values, using recursive DFS.

    Example:
    Tree:      1
                \
                 2
                /
               3
    Preorder : [1,2,3]
    Inorder  : [1,3,2]
    Postorder: [3,2,1]

    Approach:
    - Preorder : root -> left -> right
    - Inorder  : left -> root -> right
    - Postorder: left -> right -> root
    - Simple recursive DFS, visiting node and recursing on children.

    Time Complexity : O(n)
    Space Complexity: O(h) recursion stack, h = height of tree
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* root, vector<int>& out) {
    if (!root) return;
    out.push_back(root->val);
    preorder(root->left, out);
    preorder(root->right, out);
}

void inorder(TreeNode* root, vector<int>& out) {
    if (!root) return;
    inorder(root->left, out);
    out.push_back(root->val);
    inorder(root->right, out);
}

void postorder(TreeNode* root, vector<int>& out) {
    if (!root) return;
    postorder(root->left, out);
    postorder(root->right, out);
    out.push_back(root->val);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> pre, in, post;
    preorder(root, pre);
    inorder(root, in);
    postorder(root, post);

    for (int x : pre) cout << x << " "; cout << endl;
    for (int x : in) cout << x << " "; cout << endl;
    for (int x : post) cout << x << " "; cout << endl;
    return 0;
}
