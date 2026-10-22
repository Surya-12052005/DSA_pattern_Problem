/*
985. Insert node before tail in Doubly Linked List
Given the head of a doubly linked list and an integer X, insert a node with value X before the tail of the linked list and return the head of the modified list.

Example 1:
Input: head = [1, 2, 4], X = 3

Output: head = [1, 2, 3, 4]

Explanation: 3 was added before the last node.*/

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

//Insert node before tail in Doubly Linked List
Node* insertBeforeTail(Node* head, int x) {
    Node* newNode = new Node(x);

    if (head->next == NULL) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    Node* tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
    }

    Node* secondLast = tail->prev;

    secondLast->next = newNode;
    newNode->prev = secondLast;

    newNode->next = tail;
    tail->prev = newNode;

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;

    int x;
    cout << "Enter value to insert: ";
    cin >> x;

    head = insertBeforeTail(head, x);

    cout << "Updated DLL: ";
    printList(head);

    return 0;
}

