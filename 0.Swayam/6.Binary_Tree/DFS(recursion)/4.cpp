/*
========================================================
Q2. COUNT TOTAL NUMBER OF NODES
========================================================

Question:
Write a recursive function to count the total number
of nodes in a Binary Tree.

Logic:
NULL -> 0
Otherwise:
1 + nodes in left subtree + nodes in right subtree(ie: 1+n)
*/
#include <iostream>  //#include <bits/stdc++.h>
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

// Recursive function to count nodes
int countNodes(Node* x) {

    // Base case
    if (x == NULL)
        return 0;

    // Count left subtree
    int leftCount = countNodes(x->left);

    // Count right subtree
    int rightCount = countNodes(x->right);

    // Current node + left + right
    return 1 + leftCount + rightCount;
}

int main() {

    /*
            1
           / \
          2   3
         / \
        4   5
    */

    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Call recursive function
    int total = countNodes(root);

    // Print result
    cout << "Total number of nodes: " << total << endl;

    return 0;
}