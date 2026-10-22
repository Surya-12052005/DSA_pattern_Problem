/*
    Problem   : Merge K Sorted Lists
    Difficulty: Hard
    Topic     : Heap / Priority Queue

    You are given an array of k linked-lists, each sorted in ascending
    order. Merge all the linked-lists into one sorted linked-list.

    Example:
    Input : lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]

    Approach:
    - Use a min-heap to always pick the smallest current head among
      all k lists.
    - Pop the smallest, add it to result, push its "next" node (if any).

    Time Complexity : O(N log k)  where N = total nodes, k = number of lists
    Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
    for (auto node : lists) if (node) minHeap.push(node);

    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (!minHeap.empty()) {
        ListNode* smallest = minHeap.top(); minHeap.pop();
        tail->next = smallest;
        tail = tail->next;
        if (smallest->next) minHeap.push(smallest->next);
    }
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) { cout << head->val << " "; head = head->next; }
    cout << endl;
}

int main() {
    ListNode* l1 = new ListNode(1); l1->next = new ListNode(4); l1->next->next = new ListNode(5);
    ListNode* l2 = new ListNode(1); l2->next = new ListNode(3); l2->next->next = new ListNode(4);
    ListNode* l3 = new ListNode(2); l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* merged = mergeKLists(lists);
    printList(merged);
    return 0;
}
