
/*
Q1(b). INORDER TRAVERSAL
Question:
Write a recursive function to print the Inorder traversal.

Order:
LEFT -> ROOT -> RIGHT
*/

#include <iostream>
using namespace std;

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

void inorder(Node* x) {
    if (x == NULL)
        return;

    inorder(x->left);           // LEFT
    cout << x->data << " ";     // ROOT
    inorder(x->right);          // RIGHT
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "inorder Traversal: ";
    inorder(root);

    return 0;
}
