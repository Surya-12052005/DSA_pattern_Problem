/*
    Problem   : Merge Two Sorted Lists
    Difficulty: Easy
    Topic     : Linked List Manipulation

    Merge two sorted linked lists and return it as a new sorted list.

    Example:
    Input : l1 = 1->2->4, l2 = 1->3->4
    Output: 1->1->2->3->4->4

    Approach:
    - Use a dummy node to simplify edge cases.
    - Compare current nodes of both lists, attach the smaller one,
      and advance that list's pointer.
    - Attach remaining nodes of whichever list is non-empty.

    Time Complexity : O(m + n)
    Space Complexity: O(1) (excluding output)
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) { tail->next = l1; l1 = l1->next; }
        else { tail->next = l2; l2 = l2->next; }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) { cout << head->val << " "; head = head->next; }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* merged = mergeTwoLists(l1, l2);
    printList(merged);
    return 0;
}
