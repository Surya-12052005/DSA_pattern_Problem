/*
    Problem   : Reverse a Linked List
    Difficulty: Easy
    Topic     : Linked List Manipulation

    Given the head of a singly linked list, reverse the list and
    return the new head.

    Example:
    Input : 1->2->3->4->5
    Output: 5->4->3->2->1

    Approach:
    - Iterate through the list keeping track of prev, curr, next.
    - Reverse the "next" pointer of each node one by one.

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

void printList(ListNode* head) {
    while (head) { cout << head->val << " "; head = head->next; }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* reversed = reverseList(head);
    printList(reversed);
    return 0;
}
