/*
Problem Statement:
Given the head of a singly linked list, print all its elements recursively (without using loops).
Recursion naturally fits this problem because a linked list is itself a recursive structure — a node followed by "the rest of the list," which is a smaller linked list.*/

#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Print linked list recursively
void printListRecursive(Node* head) {
    // Base case: empty list / end reached
    if (head == nullptr)
        return;

    // Print current node
    cout << head->data;
    if (head->next != nullptr)
        cout << " -> ";

    // Recurse on the rest of the list
    printListRecursive(head->next);
}

int main() {
    // Build list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    printListRecursive(head);
    cout << endl;

    return 0;
}