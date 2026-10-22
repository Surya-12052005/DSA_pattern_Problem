//find the max sum of the tree's node such that no two Nodes are adjacent (ie:parent and child node cannot come together.), use recursion, make a function outside the main function .

// using dynamic programming.
/*
            5
           / \
          3   2
         / \  / 
        1   4 7  
       /     
      8     
      
      */

      
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

// Function to find maximum sum of non-adjacent nodes
int maxSum(Node* root) {

    // Base case
    if (root == NULL)
        return 0;

    // Case 1: Take the current node
    // We cannot take its children
    int take = root->data;

    if (root->left != NULL) {
        take += maxSum(root->left->left);
        take += maxSum(root->left->right);
    }

    if (root->right != NULL) {
        take += maxSum(root->right->left);
        take += maxSum(root->right->right);
    }

    // Case 2: Do not take the current node
    // We can take its children
    int skip = maxSum(root->left) + maxSum(root->right);

    // Return the maximum of both cases
    return max(take, skip);
}

int main() {

    // Create the tree
    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(2);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->left = new Node(7);

    root->left->left->left = new Node(8);

    cout << "Maximum Sum = " << maxSum(root);

    return 0;
}