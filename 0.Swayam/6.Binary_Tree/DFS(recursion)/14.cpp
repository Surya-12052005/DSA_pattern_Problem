/*
========================================================
Q8. CHECK WHETHER TWO BINARY TREES ARE MIRROR IMAGES
========================================================

Question:
Given two Binary Trees, check whether they are mirror images.

Two trees are mirror images if:
    1. Their root values are same.
    2. Left subtree of first = mirror of right subtree of second.
    3. Right subtree of first = mirror of left subtree of second.
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

// Recursive function to check mirror
bool isMirror(Node* x, Node* y) {

    // Both trees are empty
    if (x == NULL && y == NULL)
        return true;

    // One tree is empty, other is not  
    if (x == NULL || y == NULL)  
        return false;

    // Values must be same
    if (x->data != y->data)
        return false;

    // Cross comparison
    return isMirror(x->left, y->right)
        && isMirror(x->right, y->left);
}

int main() {

    /*
        Tree 1:              Tree 2:

            1                   1
           / \                 / \
          2   3               3   2
         / \                 / \
        4   5               5   4
    */

    // Create Tree 1
    Node* root1 = new Node(1);

    root1->left = new Node(2);
    root1->right = new Node(3);

    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    // Create Tree 2
    Node* root2 = new Node(1);

    root2->left = new Node(3);
    root2->right = new Node(2);

    root2->left->left = new Node(5);
    root2->right->right = new Node(4);

    // Check mirror
    if (isMirror(root1, root2))
        cout << "The two Binary Trees are Mirror Images." << endl;
    else
        cout << "The two Binary Trees are NOT Mirror Images." << endl;

    return 0;
}