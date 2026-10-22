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

//1. Function to delete the first node
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


//2.Function to delete the last node
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


//3. Function to delete the Kth node
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


//4. Function to remove a specific node using its pointer
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
