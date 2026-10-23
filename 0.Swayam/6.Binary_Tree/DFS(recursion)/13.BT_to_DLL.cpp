/*
Convert Binary Tree into Doubly Linked List

Question
Write a C++ program to convert a Binary Tree into a Doubly Linked List using inorder traversal and return the head of the linked list.

The important point from your notes is:

Convert Binary Tree to Doubly Linked List in inorder traversal and retain its head.
                 5
               /   \
              3     10
             / \    / \
            1   4  7   25
           /       \
          2         9
For our tree, inorder traversal is:

2 1 3 4 5 7 9 10 25

Therefore the DLL becomes:

NULL <- 2 <-> 1 <-> 3 <-> 4 <-> 5 <-> 7 <-> 9 <-> 10 <-> 25 -> NULL*/

#include <iostream>
using namespace std;

// Node of Binary Tree / Doubly Linked List
struct Node
{
    int data;

    // In Binary Tree:
    // left  = left child
    // right = right child
    //
    // In Doubly Linked List:
    // left  = previous node
    // right = next node

    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to convert Binary Tree into DLL
// using inorder traversal
void convertToDLL(Node* root, Node*& head, Node*& prev)
{
    // Base case
    if (root == nullptr)
        return;

    // Step 1: Convert left subtree
    convertToDLL(root->left, head, prev);

    // Step 2: Process current node

    // If this is the first node,
    // it becomes the head of DLL
    if (prev == nullptr)
    {
        head = root;
    }
    else
    {
        // Connect previous node with current node

        // Previous node's next = current node
        prev->right = root;

        // Current node's previous = previous node
        root->left = prev;
    }

    // Current node becomes previous node
    prev = root;

    // Step 3: Convert right subtree
    convertToDLL(root->right, head, prev);
}

// Function to print DLL from left to right
void printDLL(Node* head)
{
    Node* current = head;

    while (current != nullptr)
    {
        cout << current->data;

        if (current->right != nullptr)
            cout << " <-> ";

        current = current->right;
    }

    cout << endl;
}

int main()
{
    // Creating the Binary Tree

    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->left = new Node(7);
    root->right->right = new Node(25);

    root->left->left->right = new Node(2);
    root->right->left->right = new Node(9);

    // head = first node of DLL
    Node* head = nullptr;

    // prev = previously processed node
    Node* prev = nullptr;

    // Convert Binary Tree to DLL
    convertToDLL(root, head, prev);

    // Print the resulting DLL
    cout << "Doubly Linked List (Inorder):\n";
    printDLL(head);

    return 0;
}