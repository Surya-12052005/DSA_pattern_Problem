/*
    Problem   : Middle of the Linked List
    Difficulty: Easy
    Topic     : Fast & Slow Pointers

    Given the head of a singly linked list, return the middle node.
    If there are two middle nodes, return the second one.

    Example:
    Input : 1->2->3->4->5
    Output: 3

    Approach:
    - slow moves 1 step, fast moves 2 steps.
    - When fast reaches the end, slow is at the middle.

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

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* mid = middleNode(head);
    cout << "Middle node value: " << mid->val << endl;
    return 0;
}
