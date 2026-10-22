/*
    Problem   : Count Nodes in a Singly Linked List
    Difficulty: Easy
    Topic     : Linked List

    Given the head of a linked list, count the total number of nodes.

    Example:
    1 -> 2 -> 3 -> 4 -> 5

    Output:
    5
*/

#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Function to count nodes
int countNodes(Node* head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

int main()
{
    // Create linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Total Nodes = " << countNodes(head);

    return 0;
}