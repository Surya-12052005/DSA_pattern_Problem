
/*
========================================================
Q116. Populating Next Right Pointers in Each Node
========================================================

Given a perfect binary tree, connect each node's next
pointer to the next node on its right at the same level.

If there is no node on the right, set next = NULL.

Example:

             1
           /   \
          2     3
         / \   / \
        4   5 6   7

Output:

1 -> NULL
2 -> 3 -> NULL
4 -> 5 -> 6 -> 7 -> NULL

Note:
- The tree is a perfect binary tree.
- Initially, all next pointers are NULL.

Approach: BFS (Level Order Traversal) using Queue.

LeetCode Link:
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

========================================================
*/

/*
LeetCode 116 — Approach (BFS)
Idea: Connect every node to the next node on its right at the same level using a queue.
Steps
1. Check the root: If root == NULL, return root.
2. Create a queue: Insert the root node into the queue.
3. Process each level: Store the current queue size in size. This tells us how many nodes belong to the current level.
4. Connect nodes: Use a pointer prev to remember the previously processed node.
   - If prev != NULL, connect it to the current node using prev->next = curr.
   - Update prev = curr.
5. Add children: Push the current node's left and right children into the queue if they exist.
6. End the level: Set prev->next = NULL for the last node of the level.
7. Repeat until the queue is empty, then return root.*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void connectNodes(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            Node* temp = q.front();
            q.pop();

            if (i < n - 1)
                temp->next = q.front();
            else
                temp->next = NULL;

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

void printLevels(Node* root) {
    Node* start = root;

    while (start != NULL) {
        Node* temp = start;

        while (temp != NULL) {
            cout << temp->data << " -> ";  
            temp = temp->next;
        }

        cout << "NULL" << endl;
        start = start->left;
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

    connectNodes(root);

    printLevels(root);

    return 0;
}
