/*Horizontal / Level Order Traversal

Question
Given a binary tree, print all nodes level by level from left to right using BFS.

For example:

          5
        /   \
       3     10
      / \    / \
     1   4  7   25
    /     \
   2       9

Output:

5 3 10 1 4 7 25 2 9 */


//#include <iostream>
//#include <queue>
#include <bits/stdc++.h>
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

void levelOrder(Node* root) {

    // If tree is empty, there is nothing to print
    if (root == NULL)
        return;

    // Queue is used for BFS  
    queue<Node*> q;

    // Start BFS from root
    q.push(root);

    while (q.size() > 0) {

        // Take the front node from queue
        Node* temp = q.front();            // temp = 5
        q.pop();                           // Remove 5

        // Print current node
        cout << temp->data << " ";        // Print 5

        // Node 5 has two children: 3 and 10.

        // Add left child to queue
        if (temp->left != NULL)
            q.push(temp->left);

        // Add right child to queue
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main() {

    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->left = new Node(7);
    root->right->right = new Node(25);

    root->left->left->left = new Node(2);
    root->left->right->right = new Node(9);

    levelOrder(root);

    return 0;
}

/*
5 3 10 1 4 7 25 2 9


2. Understand the important variables
queue<Node*> q;
q.push(root);


- queue<Node*> q — creates a queue that stores node addresses.
- q.push(root) — inserts the root node (5) into the queue.
- Node* temp = q.front() — stores the address of the first node in temp.
- q.pop() — removes the front node from the queue.
- temp->data — accesses the data of the node stored in temp.
Remember: A queue follows FIFO — First In, First Out.*/