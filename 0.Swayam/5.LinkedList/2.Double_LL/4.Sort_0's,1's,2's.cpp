/*
Sort a Linked List of 0's, 1's and 2's
Problem: Given the head of a linked list containing only 0, 1, and 2, sort the list so that all 0s come first, followed by 1s and then 2s.

Example:
Input:  1 -> 0 -> 2 -> 1 -> 0 -> 2 -> NULL

Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL
*/


#include <iostream>
using namespace std;

// Structure of a linked list node
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to sort the linked list containing 0, 1 and 2
Node* sortList(Node* head) {
    int count0 = 0, count1 = 0, count2 = 0;

    Node* temp = head;

    // Count the number of 0s, 1s and 2s
    while (temp != nullptr) {
        if (temp->data == 0)
            count0++;
        else if (temp->data == 1)
            count1++;
        else
            count2++;

        temp = temp->next;
    }

    // Replace node values in sorted order
    temp = head;

    while (temp != nullptr) {
        if (count0 > 0) {
            temp->data = 0;
            count0--;
        }
        else if (count1 > 0) {
            temp->data = 1;
            count1--;
        }
        else {
            temp->data = 2;
            count2--;
        }

        temp = temp->next;
    }

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data;

        if (temp->next != nullptr)
            cout << " -> ";

        temp = temp->next;
    }

    cout << " -> NULL" << endl;
}

// Main function
int main() {
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);
    head->next->next->next->next->next = new Node(2);

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
