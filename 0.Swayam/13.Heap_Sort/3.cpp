/*Q7. Check Whether a Binary Tree is Full
Question

Write a C++ program to check whether a given binary tree is a Full Binary Tree.

Logic

For every node:

0 children → valid
2 children → valid
1 child    → invalid*/

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

bool isFull(Node* root) {

    if (root == NULL) {
        return true;
    }

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    // Node having only one child
    if (root->left == NULL || root->right == NULL) {
        return false;
    }

    // Check both subtrees
    return isFull(root->left) && isFull(root->right);
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    if (isFull(root)) {
        cout << "Tree is Full Binary Tree";
    }
    else {
        cout << "Tree is NOT Full Binary Tree";
    }

    return 0;
}