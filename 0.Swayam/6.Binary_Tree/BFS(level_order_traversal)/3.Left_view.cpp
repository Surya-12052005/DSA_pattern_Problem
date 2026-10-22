/*
LeetCode / Binary Tree — Left Side View
1. Question (short for VS Code)
Given the root of a binary tree, return the values of the nodes visible when the tree is viewed from the left side.

Example:
Input:
        1
       / \
      2   3
       \   \
        5   4

Output: [1, 2, 5]*/



#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> leftSideView(TreeNode* root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            // First node of each level
            if (i == 0) {
                ans.push_back(node->val);
            }

            if (node->left != NULL) {
                q.push(node->left);
            }

            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> ans = leftSideView(root);

    cout << "Left Side View: ";

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
