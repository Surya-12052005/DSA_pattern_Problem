/*
927. Insert before given node in Doubly Linked List
Given a node's reference within a doubly linked list and an integer X, insert a node with value X before the given node in the linked list while preserving the list's integrity.

You will only be given the node's reference, not the head of the list. It is guaranteed that the given node will not be the head of the list.

Example 1:
Input: head = [1, 2, 6], node = 6, X = 7

Output: head = [1, 2, 7, 6]

Explanation: Note that the head was not given to the function.*/


#include <iostream>
using namespace std;

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


//Insert before given node in Doubly Linked List
Node* insertBeforeNode(Node* head, int target, int x) {
    Node* temp = head;

    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return head;
    }

    Node* newNode = new Node(x);

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }

    temp->prev = newNode;

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;

    int target, x;

    cout << "Enter the node before which to insert: ";
    cin >> target;

    cout << "Enter the new value: ";
    cin >> x;

    head = insertBeforeNode(head, target, x);

    cout << "Updated DLL: ";
    printList(head);

    return 0;
}

