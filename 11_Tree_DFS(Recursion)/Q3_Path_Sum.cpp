/*
    Problem   : Path Sum
    Difficulty: Easy
    Topic     : Tree DFS

    Given the root of a binary tree and an integer targetSum, return
    true if the tree has a root-to-leaf path such that the sum of
    values along the path equals targetSum.

    Example:
    Input : root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    Output: true

    Approach:
    - Recursive DFS, subtracting the current node's value from targetSum.
    - At a leaf node, check if remaining targetSum equals the leaf's value.

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

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    if (!root->left && !root->right) return targetSum == root->val;
    int remaining = targetSum - root->val;
    return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    cout << (hasPathSum(root, 22) ? "true" : "false") << endl;
    return 0;
}
