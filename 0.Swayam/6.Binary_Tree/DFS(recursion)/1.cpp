/*
========================================================
BINARY TREE - QUICK REVISION + IMPORTANT RECURSIVE CODES
========================================================

BASIC IDEA
----------
Binary Tree:
Each node has at most 2 children:
    left child
    right child

For every recursive tree function:
    1. Handle NULL/base case
    2. Solve left subtree
    3. Solve right subtree
    4. Combine/print/return the answer

TRAVERSAL MEMORY TRICK
----------------------
Preorder  = ROOT -> LEFT -> RIGHT   = ROOT first  [rLR]
Inorder   = LEFT -> ROOT -> RIGHT   = ROOT middle [LrR]
Postorder = LEFT -> RIGHT -> ROOT   = ROOT last   [LRr]        

Example tree:

            5
           / \
          3   10
         / \  / \
        1   4 7  25
       /     /
      2     9

Preorder  : 5 3 1 2 4 10 7 9 25
Inorder   : 2 1 3 4 5 9 7 10 25
Postorder : 2 1 4 3 9 7 25 10 5

========================================================
Q1. WRITE FUNCTIONS FOR TREE TRAVERSALS
========================================================
*/

/*
Q1(a). PREORDER TRAVERSAL
Question:
Write a recursive function to print the Preorder traversal.  

Order:
ROOT -> LEFT -> RIGHT
*/
#include <iostream>
using namespace std;

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

void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";  // Root
    preorder(root->left);       // Left
    preorder(root->right);      // Right
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder Traversal: ";
    preorder(root);
    return 0;
}


// pure code ko decode krne ki zarurat nhi h bas root node dekho , left node , right node : rule of recursion