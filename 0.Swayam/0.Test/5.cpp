// find the max sum of the tree's node such that no two Nodes are adjacent (ie:parent and child node cannot come together.), use recursion, make a function outside the main function .
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

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int maxSum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int take = root->data;

    if (root->left != NULL)
    {
        take += maxSum(root->left->left);
        take += maxSum(root->left->right);
    }

    if (root->right != NULL)
    {
        take += maxSum(root->right->left);
        take += maxSum(root->right->right);
    }

    int skip = maxSum(root->left) + maxSum(root->right);

    return max(take, skip);
}

int main()
{

    
    Node *root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(2);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->left = new Node(7);

    root->left->left->left = new Node(8);

    cout << "Maximum Sum = " << maxSum(root);

    return 0;
}

