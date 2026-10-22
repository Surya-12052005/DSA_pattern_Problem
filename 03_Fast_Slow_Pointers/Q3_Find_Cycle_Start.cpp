/*
    Problem   : Linked List Cycle II (Find the start of the cycle)
    Difficulty: Medium
    Topic     : Fast & Slow Pointers

    Given the head of a linked list, return the node where the cycle
    begins. If there is no cycle, return nullptr.

    Approach:
    - Phase 1: Use slow/fast pointers to detect if a cycle exists (meeting point).
    - Phase 2: Reset one pointer to head; move both pointers one step at a
      time. The point where they meet again is the start of the cycle.
      (This works due to the mathematics of Floyd's cycle detection.)

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

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    bool cycleFound = false;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { cycleFound = true; break; }
    }

    if (!cycleFound) return nullptr;

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // start of cycle
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // cycle starts at node with val 2

    ListNode* cycleStart = detectCycle(head);
    if (cycleStart) cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    else cout << "No cycle" << endl;
    return 0;
}
