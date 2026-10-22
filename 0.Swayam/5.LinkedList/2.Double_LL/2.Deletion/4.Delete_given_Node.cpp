//4. Delete Given Node in Doubly Linked List

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

// Function to remove a specific node using its pointer
void removeGivenNode(Node*& head, Node* node) {
    // If the node does not exist
    if (node == NULL) {
        return;
    }

    // If the node is not the head, connect the previous node
    // to the next node
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        // If removing the head, update head
        head = node->next;
    }

    // If the node is not the tail, update the next node's prev
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    // Delete the selected node
    delete node;
}

// Function to insert a node at the end
Node* insertAtTail(Node* head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to find a value and delete its first occurrence
Node* deleteByValue(Node* head, int value) {
    Node* temp = head;

    // Search for the node containing the given value
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // If the value is not present
    if (temp == NULL) {
        cout << "Value not found!" << endl;
        return head;
    }

    // Remove the node that was found
    removeGivenNode(head, temp);

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
    int n, val, target;

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

    // Ask which value should be deleted
    cout << "Enter value of node to delete: ";
    cin >> target;

    head = deleteByValue(head, target);

    cout << "After deletion: ";
    printList(head);

    return 0;
}
