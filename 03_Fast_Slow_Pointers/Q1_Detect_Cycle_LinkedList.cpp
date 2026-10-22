/*
    Problem   : Linked List Cycle Detection (Floyd's Algorithm)
    Difficulty: Easy
    Topic     : Fast & Slow Pointers

    Given the head of a linked list, determine if the linked list has a cycle.

    Approach:
    - slow moves 1 step, fast moves 2 steps.
    - If there is a cycle, they will eventually meet.
    - If fast reaches nullptr, there is no cycle.

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

// Definition of a Linked List Node
struct ListNode
{
    int data;
    ListNode* next;

    ListNode(int x)
    {
        data = x;
        next = NULL;
    }
};

// Function to check if a cycle exists
bool hasCycle(ListNode* head)
{
    // Empty list or only one node
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Move slow by 1 step and fast by 2 steps
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        // If both pointers meet, cycle exists
        if (slow == fast)
        {
            return true;
        }
    }

    // Fast reached the end, so no cycle
    return false;
}

int main()
{
    // Creating nodes
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Uncomment the line below to create a cycle
    // head->next->next->next->next = head->next;

    if (hasCycle(head))
    {
        cout << "Cycle Found";
    }
    else
    {
        cout << "No Cycle";
    }

    return 0;
}
