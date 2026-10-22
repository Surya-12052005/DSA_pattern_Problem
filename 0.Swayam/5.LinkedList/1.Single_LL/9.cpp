/*Given the head of a singly linked list and two positions left and right (1-indexed), reverse the nodes of the list from position left to position right, and return the head of the modified list.

This matches what's shown in your notes — the list 1→2→3→4→5→6→7→8→9 has sub-parts reversed:

Positions 3 to 5 (3→4→5) reversed → 5→4→3
Positions 8 to 9 (8→9) reversed → 9→8

Giving the final result: 1→2→5→4→3→6→7→9→8 */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Reverse the sub-list from position 'left' to 'right' (1-indexed)
Node* reverseBetween(Node* head, int left, int right) {
    if (head == nullptr || left == right)
        return head;

    // Dummy node simplifies edge case where left == 1
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* prev = dummy;
    // Move 'prev' to the node just before position 'left'
    for (int i = 1; i < left; i++)
        prev = prev->next;

    // 'curr' will be pushed to the end of the reversed segment
    Node* curr = prev->next;

    // Standard "insert at front of sublist" reversal
    for (int i = 0; i < right - left; i++) {
        Node* nextNode = curr->next;
        curr->next = nextNode->next;
        nextNode->next = prev->next;
        prev->next = nextNode;
    }

    Node* newHead = dummy->next;
    delete dummy;
    return newHead;
}

// Helper to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Build list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
    Node* head = new Node(1);
    Node* temp = head;
    for (int i = 2; i <= 9; i++) {
        temp->next = new Node(i);
        temp = temp->next;
    }

    cout << "Original list: ";
    printList(head);

    // Reverse sub-part from position 3 to 5
    head = reverseBetween(head, 3, 5);
    cout << "After reversing (3 to 5): ";
    printList(head);

    // Reverse sub-part from position 8 to 9
    head = reverseBetween(head, 8, 9);
    cout << "After reversing (8 to 9): ";
    printList(head);

    return 0;
}