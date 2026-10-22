//1. Delete Head of Doubly Linked List

#include <iostream>
using namespace std;

// Structure of a doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Function to delete the first node
Node* deleteHead(Node* head) {
    // If the list is empty, nothing to delete
    if (head == NULL) {
        return NULL;
    }

    // Store the old head
    Node* temp = head;

    // Move head to the second node
    head = head->next;

    // If the new head exists, remove its backward link
    if (head != NULL) {
        head->prev = NULL;
    }

    // Delete the old head
    delete temp;

    return head;
}

// Function to insert a node at the end
Node* insertAtTail(Node* head, int val) {
    Node* newNode = new Node(val);

    // If the list is empty, new node becomes the head
    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;

    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Connect the new node to the last node
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to print the list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;

        if (head->next != NULL) {
            cout << " <-> ";
        }

        head = head->next;
    }

    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, val;

    // Take the number of nodes
    cout << "Enter number of nodes: ";
    cin >> n;

    // Create the linked list
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        head = insertAtTail(head, val);
    }

    cout << "Original List: ";
    printList(head);

    // Delete the first node
    head = deleteHead(head);

    cout << "After deleting head: ";
    printList(head);

    return 0;
}
