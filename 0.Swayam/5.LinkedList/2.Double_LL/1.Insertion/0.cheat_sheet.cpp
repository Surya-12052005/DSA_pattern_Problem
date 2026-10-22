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

//1.Insert a Node at the Beginning of a DLL.
Node* insertBeforeHead(Node* head, int x) {
    Node* newNode = new Node(x);

    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
    return head;
}

//2.Insert node before tail in Doubly Linked List
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


//3.Insert a node at the end of a Doubly Linked List
Node* insertAtEnd(Node* head, int x) {
    Node* newNode = new Node(x);

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


//4.Insert before given node in Doubly Linked List
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

//print DLL.
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