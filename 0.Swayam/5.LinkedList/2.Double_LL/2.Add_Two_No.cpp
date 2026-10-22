/*
Problem 2: Add Two Numbers

Difficulty: Medium
Topic: Linked List, Math

Problem Statement

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each node contains a single digit.
Add the two numbers and return their sum as a linked list.
You may assume that the numbers do not contain any leading zeros, except for the number 0 itself.

Example 1

Input:

l1 = [2, 4, 3]
l2 = [5, 6, 4]

Output:

[7, 0, 8]

Explanation:

The first linked list represents 342, and the second represents 465.

Therefore, 342 + 465 = 807.

The result is stored in reverse order: [7, 0, 8].*/


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

// Function to add two numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(-1);
    ListNode* curr = dummyHead;

    int carry = 0;

    // Process both lists and any remaining carry
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry;

        // Add digit from the first list
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }

        // Add digit from the second list
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        // Calculate carry and digit
        carry = sum / 10;
        int digit = sum % 10;

        // Create a new node for the result
        curr->next = new ListNode(digit);
        curr = curr->next;
    }

    ListNode* result = dummyHead->next;
    delete dummyHead;

    return result;
}

// Function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // First number: 342 (reverse order: 2 -> 4 -> 3)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Second number: 465 (reverse order: 5 -> 6 -> 4)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    cout << "First list: ";
    printList(l1);

    cout << "Second list: ";
    printList(l2);

    // Call the addition function
    ListNode* result = addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}
