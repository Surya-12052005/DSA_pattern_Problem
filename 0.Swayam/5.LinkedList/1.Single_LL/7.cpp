/*Given the head of a singly linked list, print all its elements in reverse order without modifying the original list structure.*/
// use Recursion
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}                   
};

// Print linked list in reverse order
void printReverse(Node* head) {
    // Base case: end of list
    if (head == nullptr)
        return;

    // Recurse first (go to the end)
    printReverse(head->next);

    // Print after returning from recursion      
    cout << head->data << " ";
}

int main() {
    // Build list: 10 -> 20 -> 30 -> 40 -> 50 
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Linked list in reverse: ";
    printReverse(head);
    cout << endl;

    return 0;
}