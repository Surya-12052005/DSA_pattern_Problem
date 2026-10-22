/*
Q1(c). POSTORDER TRAVERSAL
Question:
Write a recursive function to print the Postorder traversal.

Order:
LEFT -> RIGHT -> ROOT
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

void postorder(Node* x) {
    if (x == NULL)
        return;

    postorder(x->left);         // LEFT
    postorder(x->right);        // RIGHT
    cout << x->data << " ";     // ROOT
}



int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "postorder Traversal: ";
    postorder(root);

    return 0;
}
