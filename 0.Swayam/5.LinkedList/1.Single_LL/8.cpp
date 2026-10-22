/*
    Problem   : Find Merge Point of Two Linked Lists
    Difficulty: Easy
    Topic     : Linked List

    Example:

    List 1 : 1 -> 2 -> 3 \
                           6 -> 7 -> NULL
    List 2 :      4 -> 5 /

    Output : 6

    Approach:
    1. Find the length of both linked lists.
    2. Move the pointer of the longer list ahead.
    3. Move both pointers together.
    4. When both pointers become equal, that is the merge point.  

    Time Complexity : O(n + m)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Find length of linked list
int getLength(Node *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

// Find merge point
Node *findMergePoint(Node *head1, Node *head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    // Move the longer list ahead
    if (len1 > len2)
    {
        for (int i = 0; i < diff; i++)
        {
            head1 = head1->next;
        }
    }
    else
    {
        for (int i = 0; i < diff; i++)
        {
            head2 = head2->next;
        }
    }

    // Compare both lists
    while (head1 != NULL && head2 != NULL)
    {
        if (head1 == head2)
        {
            return head1;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
}

int main()
{
    // Common part
    Node* common = new Node(6);
    common->next = new Node(7);      

    // First linked list
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = common;

    // Second linked list
    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = common;

    // Find merge point
    Node* merge = findMergePoint(head1, head2);

    if (merge != NULL)
    {
        cout << "Merge Point = " << merge->data << endl;
    }
    else
    {
        cout << "No Merge Point Found";
    }

    return 0;
}