/*
LeetCode 110: Balanced Binary Tree
Question (Short): Given the root of a binary tree, check whether it is height-balanced.
 A tree is balanced if the height difference between the left and right subtrees of every node is at most 1.*/

 /*
         3
       / \
      9   20
         /  \
        15   7

Output: true
 */
//A tree is balanced if for every node:    ∣height(left)−height(right)∣≤1

 
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right); 

    if (leftHeight == -1 || rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)   // Current node is unbalanced
        return -1;

    return 1 + max(leftHeight, rightHeight);  // Return height of current subtree
}

bool isBalanced(Node* root) {
    return height(root) != -1;  //This line means: If the height function does not return -1, the tree is balanced.
}

int main() {
    Node* root = new Node(3);

    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    if (isBalanced(root))
        cout << "true";
    else
        cout << "false";

    return 0;
}
