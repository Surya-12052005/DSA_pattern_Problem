/*
    Problem   : Remove Nth Node From End of List
    Difficulty: Medium
    Topic     : Linked List Manipulation (Two Pointers)

    Given the head of a linked list, remove the nth node from the end
    and return the head.

    Example:
    Input : head = 1->2->3->4->5, n = 2
    Output: 1->2->3->5

    Approach:
    - Use two pointers: fast and slow, with a dummy node before head.
    - Move fast n steps ahead first.
    - Then move both fast and slow together until fast reaches the end.
    - slow->next is now the node to remove; skip it.

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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    for (int i = 0; i < n; i++) fast = fast->next;

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return dummy.next;
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

    ListNode* res = removeNthFromEnd(head, 2);
    printList(res);
    return 0;
}
