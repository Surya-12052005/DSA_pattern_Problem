/*
LeetCode 572: Subtree of Another Tree
Difficulty: Easy
Topic: Binary Tree, DFS, Recursion
Language: C++
1. Question (copy-paste for VS Code)
Given the roots of two binary trees, root and subRoot, return true if subRoot is a subtree of root. Otherwise, return false.

A subtree must have the same structure and the same node values as a part of the main tree.
2. Example with diagram
Input:
root = [3,4,5,1,2]
subRoot = [4,1,2]
*/

/*
LeetCode 572: Subtree of Another Tree

Main Tree (root):

          3
         / \
        4   5
       / \
      1   2


SubTree (subRoot):

        4
       / \
      1   2


Output: true

Explanation:
The subtree rooted at node 4 in the main tree
matches the subRoot exactly in structure and values.
*/


#include <iostream>
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

// Check whether two trees are identical
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }

    if (p == NULL || q == NULL) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

// Check whether subRoot exists inside root
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == NULL) {
        return false;
    }

    if (isSameTree(root, subRoot)) {
        return true;
    }

    return isSubtree(root->left, subRoot) ||
           isSubtree(root->right, subRoot);
}

int main() {
    // Main tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    // Subtree
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);

    if (isSubtree(root, subRoot)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}
