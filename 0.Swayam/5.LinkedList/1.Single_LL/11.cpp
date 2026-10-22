/*
    Problem : Reverse Linked List from Position Left to Right

    Example:
    Input : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
    left = 3, right = 5

    Output:
    1 -> 2 -> 5 -> 4 -> 3 -> 6 -> 7 -> 8 -> 9
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverseBetween(Node* head, int left, int right) {

    if (head == NULL || left == right)  // If left == right → only one node is selected, so it remains the same.
        return head;

    //Initialize Pointers
    Node *prev = NULL;
    Node *curr = head;

    // Move to left position
    for (int i = 1; i < left; i++) { 
        prev = curr;
        curr = curr->next;
    }

    Node *leftPrev = prev;
    Node *leftNode = curr;

    // Reverse nodes
    prev = NULL;

    for (int i = left; i <= right; i++) {     
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Connect first part
    if (leftPrev != NULL)
        leftPrev->next = prev;
    else
        head = prev;

    // Connect last part
    leftNode->next = curr;

    return head;
}

// Print List
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    Node *head = new Node(1);
    Node *temp = head;

    for (int i = 2; i <= 9; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }

    cout << "Original List : ";
    printList(head);

    head = reverseBetween(head, 3, 5);
    cout << "After Reverse (3 to 5): ";
    printList(head);

    head = reverseBetween(head, 8, 9);
    cout << "After Reverse (8 to 9): ";
    printList(head);

    return 0;
}