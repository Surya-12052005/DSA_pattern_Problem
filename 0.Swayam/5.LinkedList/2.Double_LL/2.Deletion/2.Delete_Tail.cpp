//2. Delete Tail of Doubly Linked List


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

// Function to delete the last node
Node* deleteTail(Node* head) {
    // If the list is empty
    if (head == NULL) {
        return NULL;
    }

    // If there is only one node
    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;

    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Disconnect the last node from the previous node
    temp->prev->next = NULL;

    // Delete the last node
    delete temp;

    return head;
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

    // Delete the last node
    head = deleteTail(head);

    cout << "After deleting tail: ";
    printList(head);

    return 0;
}
