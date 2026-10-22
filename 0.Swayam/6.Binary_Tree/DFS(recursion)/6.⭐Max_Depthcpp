/*
========================================================
Q4. HEIGHT OF A BINARY TREE
========================================================
Question:
Write a recursive function to find the height of a
Binary Tree.

Here:
    Height(NULL) = 0
    Height(tree) = 1 + max(left height, right height)

This version counts the number of NODES on the longest path.
*/

#include <iostream>
using namespace std;

//Node structure
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

//Recursive function
int getHeight(Node* x) {
    if (x == NULL)
        return 0;

    int leftHeight = getHeight(x->left);
    int rightHeight = getHeight(x->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int result = getHeight(root);

    cout << "Hight of Binary Tree: "<< result <<endl;
    getHeight(root);

    return 0;
}
