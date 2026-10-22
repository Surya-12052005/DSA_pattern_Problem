//3. Delete Kth Element of Doubly Linked List


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

// Function to delete the Kth node
Node* deleteKth(Node* head, int k) {
    // Invalid position or empty list
    if (head == NULL || k <= 0) {
        return head;
    }

    Node* temp = head;
    int count = 1;

    // Move to the Kth node
    while (temp != NULL && count < k) {
        temp = temp->next;
        count++;
    }

    // If K is greater than the list length
    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return head;
    }

    // If the node is not the head, connect its previous node
    // to its next node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        // If deleting the head, update head
        head = temp->next;
    }

    // If the node is not the tail, update the next node's prev
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Delete the Kth node
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
    int n, val, k;

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

    // Take the position to delete
    cout << "Enter position K to delete: ";
    cin >> k;

    head = deleteKth(head, k);

    cout << "After deletion: ";
    printList(head);

    return 0;
}
