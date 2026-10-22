/*
========================================================
Q3. COUNT NODES HAVING ONLY RIGHT CHILD
========================================================

Question:
Write a recursive function to count nodes which have
only a RIGHT child and NO LEFT child.

Condition:
left == NULL && right != NULL
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
int countRightChild(Node* x) {

    // Base case
    if (x == NULL)
        return 0;

    // Count left and right subtree
    int leftCount = countRightChild(x->left);
    int rightCount = countRightChild(x->right);

    // Check if current node has ONLY right child      
    if (x->left == NULL && x->right != NULL)
        return 1 + leftCount + rightCount;

    return leftCount + rightCount;
}

int main() {

    /*
            1
           / \
          2   3
           \   \
            4   5
               /
              6
    */

    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    root->right->right->left = new Node(6);

    // Call function
    int result = countRightChild(root);

    cout << "Nodes having only right child: " << result << endl;

    return 0;
}