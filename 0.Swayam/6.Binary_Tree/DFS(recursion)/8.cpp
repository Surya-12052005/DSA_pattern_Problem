 /*
========================================================
Q6. FIND LEVEL OF A VALUE
========================================================

Question:
Write a recursive function:

    int getLevel(Node* r, int val)

Root level = 1

If value is not present:
    return 0
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
int getLevel(Node* x, int val) {

    // Base case
    if (x == NULL)
        return 0;

    // If current node contains the value
    if (x->data == val)
        return 1;

    // Search in left subtree
    int leftLevel = getLevel(x->left, val);

    if (leftLevel != 0)
        return leftLevel + 1;

    // Search in right subtree
    int rightLevel = getLevel(x->right, val);

    if (rightLevel != 0)
        return rightLevel + 1;

    // Value not found
    return 0;
}

int main() {

    /*
            1              Level 1
           / \
          2   3            Level 2
         / \
        4   5              Level 3
    */

    // Create Binary Tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Value to search
    int val;

    cout << "Enter value: ";
    cin >> val;

    // Find level
    int result = getLevel(root, val);

    // Display result
    if (result != 0)
        cout << "Level of " << val << " is: " << result << endl;
    else
        cout << "Value " << val << " is not present in the Binary Tree." << endl;

    return 0;
}

