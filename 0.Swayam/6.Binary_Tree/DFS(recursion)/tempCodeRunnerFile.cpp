/*
Print All Ancestors of a Given Node

Question
Write a C++ program to print all ancestors of a given node in a Binary Tree.

             5
           /   \
          3     10
         / \    / \
        1   4  7   25
       /       \
      2         9


For example, if the given node is:
9

Its ancestors are:
7 10 5

Because:

5
 \
  10
    \
     7
      \
       9  */

#include <iostream>
using namespace std;

// Node of Binary Tree
struct Node
{
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

// Function to print all ancestors of a given node
bool PrintAncestors(Node* root, int target)
{
    // Base case
    if (root == NULL)
        return false;

    // If current node is the target,
    // it is not its own ancestor
    if (root->data == target)
        return true;

    // Search in left subtree
    if (PrintAncestors(root->left, target))  
    {
        cout << root->data << " ";
        return true;
    }

    // Search in right subtree
    if (PrintAncestors(root->right, target))
    {
        cout << root->data << " ";
        return true;
    }

    // Target not found in this subtree  
    return false;
}

int main()
{
    /*
                 5
               /   \
              3     10
             / \    / \
            1   4  7   25
           /       \
          2         9
    */

    // Creating the binary tree
    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->left = new Node(7);
    root->right->right = new Node(25);

    root->left->left->left = new Node(2);
    root->right->left->right = new Node(9);

    // Node whose ancestors we want to print
    int target = 9;

    cout << "Ancestors of " << target << " are: ";

    PrintAncestors(root, target);

    cout << endl;

    return 0;
}