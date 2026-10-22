/*
LeetCode 328: Odd Even Linked List

Difficulty: Medium
Topic: Linked List

Problem Statement
You are given the head of a singly linked list. Rearrange the list so that all nodes at odd positions come first, followed by all nodes at even positions.
The relative order of nodes within both groups must remain the same.

Remember: positions start from 1, not 0.

Example 1

Input:
1 -> 2 -> 3 -> 4 -> 5

Output:
1 -> 3 -> 5 -> 2 -> 4
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// Function to group odd-indexed nodes before even-indexed nodes
ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* odd = head;              //odd points to the first odd-position node.
    ListNode* even = head->next;       //even points to the first even-position node.
    ListNode* evenHead = even;          //Save the beginning of the even list.

    while (even != nullptr && even->next != nullptr) {   //Continue while: even exists  , even->next exists
        odd->next = even->next;                          // 1 -> 2 -> 3 -> 4 -> 5
        odd = odd->next;                                //   ↑    ↑    ↑
                                                     //   odd even new_odd           ie. 1->next = 3
        even->next = odd->next;
        even = even->next;                              // 2->next = 4
    }

    odd->next = evenHead;                             //Second Iteration     //Current pointers:   //odd = 3   ,  even = 4

    return head;
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
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    head = oddEvenList(head);

    cout << "Reordered List: ";
    printList(head);

    return 0;
}
