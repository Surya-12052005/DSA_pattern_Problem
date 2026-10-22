/*Q. Check Whether a Binary Tree is a BST

Your second picture contains this function:

boolean isBST(Node r, int min, int max)
Question

Write a function to check whether a given Binary Tree is a Binary Search Tree or not.*/

#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

bool isBST(Node* root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;

    if (root->data < minValue || root->data > maxValue)
        return false;

    return isBST(root->left, minValue, root->data - 1) &&
           isBST(root->right, root->data + 1, maxValue);
}

int main()
{
    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->left = new Node(7);
    root->right->right = new Node(20);

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "Tree is a BST";
    else
        cout << "Tree is not a BST";

    return 0;
}