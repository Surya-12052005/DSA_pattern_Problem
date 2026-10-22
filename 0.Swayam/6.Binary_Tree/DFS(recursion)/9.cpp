/*
========================================================
Q7. CREATE THE MIRROR IMAGE OF A BINARY TREE
========================================================

Question:
Write a recursive function:

    void mirrorImage(Node*& x)

Logic:
For every node:
    1. Swap left and right
    2. Mirror left subtree
    3. Mirror right subtree
*/

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Preorder traversal
void preorder(Node* x) {

    if (x == NULL)
        return;

    cout << x->data << " ";

    preorder(x->left);
    preorder(x->right);
}

// Recursive function to create mirror
void mirrorImage(Node*& x) {

    // Base case
    if (x == NULL)
        return;

    // Swap left and right children
    Node* temp = x->left;
    x->left = x->right;
    x->right = temp;

    // Mirror left subtree
    mirrorImage(x->left);

    // Mirror right subtree
    mirrorImage(x->right);
}

int main() {

    /*
            5
           / \
          3   10
         / \
        2   4
    */

    // Create Binary Tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);     

    // Original tree
    cout << "Original Preorder: ";
    preorder(root);

    // Create mirror
    mirrorImage(root);

    // Mirror tree
    cout << "\nMirror Preorder: ";
    preorder(root);

    return 0;
}