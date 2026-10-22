/*
========================================================
Q5. SEARCH A VALUE IN A BINARY TREE
========================================================

Question:
Write a recursive function:

    bool search(Node* r, int val)

Important:
This is a normal Binary Tree search, NOT necessarily a BST.
So we may need to search both subtrees.
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

// Recursive function
bool search(Node* x, int val) {

    // Base case: tree is empty
    if (x == NULL)
        return false;

    // If current node contains the value
    if (x->data == val)
        return true;

    // Search in left subtree
    if (search(x->left, val))     
        return true;

    // Search in right subtree
    return search(x->right, val);   
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

    // Value to search
    int val;

    cout << "Enter value to search: ";
    cin >> val;

    // Call search function
    bool result = search(root, val);

    // Display result
    if (result)
        cout << "Value " << val << " is present in the Binary Tree." << endl;
    else
        cout << "Value " << val << " is NOT present in the Binary Tree." << endl;

    return 0;
}