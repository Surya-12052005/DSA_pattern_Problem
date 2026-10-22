/*1. Insert a Node at the Beginning of a DLL
Question: Given the head of a doubly linked list and an integer val, insert a new node containing val at the beginning of the list and return the updated head.
Example
- Input: DLL = 10 20 30, val = 5
- Output: 5 10 20 30**/

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

 //Insert a Node at the Beginning of a DLL
Node* insertBeforeHead(Node* head, int x) {
    Node* newNode = new Node(x);

    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
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
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    int x;
    cout << "Enter value to insert: ";
    cin >> x;

    head = insertBeforeHead(head, x);

    cout << "Updated DLL: ";
    printList(head);

    return 0;
}