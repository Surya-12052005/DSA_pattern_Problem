/*4. Connect Nodes at the Same Level

Your 4th question is about connecting nodes at the same level using a next pointer.
For example:

          5
        /   \
       3     10
      / \    / \
     1   4  7   25

After connecting:

5 -> NULL
3 -> 10 -> NULL
1 -> 4 -> 7 -> 25 -> NULL
This can be easily done using BFS.*/

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;

    Node* left;
    Node* right;

    // next points to the next node at the same level
    Node* next;

    Node(int x) {
        data = x;
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

        // Number of nodes at current level
        int n = q.size();

        for (int i = 0; i < n; i++) {

            Node* temp = q.front();
            q.pop();

            // If this is not the last node of the level,
            // connect it to the next node
            if (i < n - 1)
                temp->next = q.front();

            // Add children for next level
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

            cout << temp->data << " ";

            temp = temp->next;
        }

        cout << "-> NULL\n";

        // Move to next level
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

    // Connect nodes at same level
    connectNodes(root);

    printLevels(root);

    return 0;
}