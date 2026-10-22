/*
    Problem   : write a recursive funstion to delete all duplicate nodes from the given sorted list
    Difficulty: Easy
    Topic     : Linked List

    

    Example:
    1 -> 2 ->2-> 3->3-> 4 -> 4 -> 4

    Output:
    1->2->3->4
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


int removeDuplicate(Node *Temp)
{
    while(Temp != NULL)
    {
        if(Temp->data == Temp->next->data)
        Temp->next=Temp

        head = head->next;

    }
    return 
}
int main()
{
    // Create linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Total Nodes = " << countNodes(head);

    return 0;
}