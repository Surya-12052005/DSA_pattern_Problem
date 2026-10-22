//3.Insert a node at the end of a Doubly Linked List
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

//Insert a node at the end of a Doubly Linked List
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

    head = insertAtEnd(head, x);

    cout << "Updated DLL: ";
    printList(head);

    return 0;
}