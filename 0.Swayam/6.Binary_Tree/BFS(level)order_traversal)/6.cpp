/*
3. Top View and Bottom View

Question
Print the nodes visible from the top and bottom of a binary tree.

We assign a horizontal distance (HD):

             5
           /   \
          3     10
         / \   /  \
        1   4 7   25
       /     \
      2       9

Horizontal distance:

             0
          -1   +1
        -2 +0  0  +2
       -3       +1

For Top View, take the first node encountered at each horizontal distance.

For Bottom View, take the last node encountered.*/

#include <iostream>
#include <queue>
#include <map>
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

// Pair contains:
// 1. Node
// 2. Horizontal Distance
void topView(Node* root) {

    if (root == NULL)
        return;

    // Map stores horizontal distance -> node value
    map<int, int> mp;

    queue<pair<Node*, int>> q;

    // Root has horizontal distance 0
    q.push({root, 0});

    while (!q.empty()) {

        Node* temp = q.front().first;
        int hd = q.front().second;
        q.pop();

        // Insert only the FIRST node at this horizontal distance
        if (mp.find(hd) == mp.end())
            mp[hd] = temp->data;

        // Left child decreases horizontal distance
        if (temp->left != NULL)
            q.push({temp->left, hd - 1});

        // Right child increases horizontal distance
        if (temp->right != NULL)
            q.push({temp->right, hd + 1});
    }

    // map automatically prints from smallest HD to largest HD
    for (auto x : mp)
        cout << x.second << " ";
}

void bottomView(Node* root) {

    if (root == NULL)
        return;

    map<int, int> mp;

    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {

        Node* temp = q.front().first;
        int hd = q.front().second;
        q.pop();

        // For Bottom View, keep updating.
        // The last node at each HD will remain.
        mp[hd] = temp->data;

        if (temp->left != NULL)
            q.push({temp->left, hd - 1});

        if (temp->right != NULL)
            q.push({temp->right, hd + 1});
    }

    for (auto x : mp)
        cout << x.second << " ";
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

    cout << "Top View: ";
    topView(root);

    cout << "\nBottom View: ";
    bottomView(root);

    return 0;
}