/*
    Problem   : Insert a Node at the Beginning of a Linked List
    Difficulty: Easy
    Topic     : Linked List

    Given the head of a linked list and a value,
    insert a new node at the beginning and return the new head.

    Example:
    Before : 2 -> 3 -> 4
    Insert : 1
    After  : 1 -> 2 -> 3 -> 4
*/


#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert node at beginning
Node* insertBegg(Node* head, int val) {
    Node* newNode = new Node(val);

    newNode->next = head;

    return newNode;
}

// Print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }
}

int main() {
    // Build list: 1 -> 2 -> 3 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    int val;
    cout << "Enter value to insert: ";
    cin >> val;

    head = insertBegg(head, val);

    cout << "Updated List: ";
    printList(head);

    return 0;
}