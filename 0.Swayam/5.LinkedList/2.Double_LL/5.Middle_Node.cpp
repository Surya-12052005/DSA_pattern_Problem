/*
LeetCode 876: Middle of the Linked List

Difficulty: Easy
Topic: Linked List, Two Pointers

Problem Statement

You are given the head of a singly linked list. Return the middle node of the linked list.

If the linked list has two middle nodes, return the second middle node.

Example 1

Input:

head = [1, 2, 3, 4, 5]

Output:

[3, 4, 5]

Explanation: The middle node is 3, so return the list starting from that node.

Example 2

Input:

head = [1, 2, 3, 4, 5, 6]

Output:

[4, 5, 6]

Explanation: The two middle nodes are 3 and 4. Return the second middle node, 4.
*/
#include <iostream>
using namespace std;

// Structure of a linked list node
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Function to find the middle node
ListNode* middleNode(ListNode* head) {
    ListNode* slowPtr = head;
    ListNode* fastPtr = head;

    // Slow moves one step, fast moves two steps
    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    return slowPtr;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;

        if (head->next != nullptr) {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << " -> NULL" << endl;
}

// Main function
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    ListNode* middle = middleNode(head);

    cout << "Middle Node: ";
    printList(middle);

    return 0;
}
