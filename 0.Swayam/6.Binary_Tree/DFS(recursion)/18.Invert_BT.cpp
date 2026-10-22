/*
LeetCode 226: Invert Binary Tree

Question:
Given the root of a binary tree, invert the tree
and return its root.

Inverting a binary tree means swapping the left
and right children of every node.

Example:

Input Tree:

          4
         / \
        2   7
       / \ / \
      1  3 6  9

Output Tree:

          4
         / \
        7   2
       / \ / \
      9  6 3  1

Output: [4,7,2,9,6,3,1]

Approach:
1. If the root is NULL, return NULL.
2. Swap the left and right children.
3. Invert the left subtree.
4. Invert the right subtree.
5. Return the root.
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* invertTree(Node* root) {
    if (root == NULL)
        return NULL;

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

void levelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;     
    q.push(root);

    while (q.size() > 0) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

    root = invertTree(root);

    cout << "Inverted tree: ";
    levelOrder(root);

    return 0;
}