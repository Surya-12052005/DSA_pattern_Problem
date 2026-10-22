/*Q6. Check Whether a Binary Tree is Complete
Question

Write a C++ program to check whether a given binary tree is a Complete Binary Tree.

Concept

We use Level Order Traversal (BFS).

Once we encounter a missing child (NULL), all nodes appearing after it must also be NULL.

For example:

          1
        /   \
       2     3
      / \   /
     4   5 6

Valid.

But:

          1
        /   \
       2     3
        \   
         5

Invalid because a right child exists while the corresponding left position is empty.*/

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

int countNodes(Node* root) {

    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

bool isComplete(Node* root, int index, int totalNodes) {

    if (root == NULL)
        return true;

    // If index goes outside total nodes
    if (index >= totalNodes)
        return false;

    return isComplete(root->left, 2 * index + 1, totalNodes)
        && isComplete(root->right, 2 * index + 2, totalNodes);  
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);

    int totalNodes = countNodes(root);

    if (isComplete(root, 0, totalNodes))
        cout << "Complete Binary Tree";
    else
        cout << "Not a Complete Binary Tree";  

    return 0;
}