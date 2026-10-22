/*A number is represented as a singly linked list, where each node stores a single digit (most significant digit first). Increment the number by 1 and return the head of the resulting list.
The key challenge: if the last digit is 9, incrementing it causes a carry — it becomes 0 and the carry propagates to the digit before it, which may also be 9, and so on (like 1999 + 1 = 2000).*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Increment the number represented by the linked list by 1
Node* incrementByOne(Node* head) {
    Node* lastNotNine = nullptr;
    Node* temp = head;

    // Step 1: find the last node whose digit is not 9
    while (temp != nullptr) {
        if (temp->data != 9)
            lastNotNine = temp;
        temp = temp->next;
    }

    // Step 2: handle the two cases
    if (lastNotNine == nullptr) {
        // Every digit was 9 (e.g., 999 -> 1000): prepend a new node
        Node* newHead = new Node(1);
        newHead->next = head;

        // Set all original digits to 0
        temp = head;
        while (temp != nullptr) {
            temp->data = 0;
            temp = temp->next;
        }
        return newHead;
    } else {
        // Increment lastNotNine, and zero out everything after it
        lastNotNine->data += 1;
        temp = lastNotNine->next;
        while (temp != nullptr) {
            temp->data = 0;
            temp = temp->next;
        }
        return head;
    }
}

// Helper to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

// Helper to build a list from a number string
Node* buildList(string num) {
    Node* head = new Node(num[0] - '0');
    Node* temp = head;
    for (int i = 1; i < num.size(); i++) {
        temp->next = new Node(num[i] - '0');
        temp = temp->next;
    }
    return head;
}

int main() {
    // Test 1: matches your notes -> 19229939 -> 19229940
    Node* head1 = buildList("19229939");
    cout << "Before: ";
    printList(head1);
    head1 = incrementByOne(head1);
    cout << "After:  ";
    printList(head1);

    cout << endl;

    // Test 2: all 9's -> new digit gets added
    Node* head2 = buildList("999");
    cout << "Before: ";
    printList(head2);
    head2 = incrementByOne(head2);
    cout << "After:  ";
    printList(head2);

    return 0;
}