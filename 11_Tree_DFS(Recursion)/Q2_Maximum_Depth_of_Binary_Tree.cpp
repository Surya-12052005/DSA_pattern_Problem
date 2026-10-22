/*
    Problem   : Maximum Depth of Binary Tree
    Difficulty: Easy
    Topic     : Tree DFS

    Given the root of a binary tree, return its maximum depth
    (number of nodes along the longest path from root to a leaf).

    Example:
    Input : [3,9,20,null,null,15,7]
    Output: 3

    Approach:
    - Recursive DFS: depth of a node = 1 + max(depth(left), depth(right)).
    - Base case: null node has depth 0.

    Time Complexity : O(n)
    Space Complexity: O(h)
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Max Depth: " << maxDepth(root) << endl;
    return 0;
}
