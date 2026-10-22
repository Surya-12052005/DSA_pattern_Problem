/*givn two link list  whos ha ar h1, h2 (h1->1->5->8->10) an (h2->2->->9->12->15) , w hav top mrg two link list  , ie( 1->2->->->5->8->9->10->12->15 )*/
//without rursion

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
public:

    Node* merge(Node* h1, Node* h2)
    {
        if (h1 == NULL)
            return h2;

        if (h2 == NULL)
            return h1;

        if (h2->data < h1->data)              
            swap(h1, h2);

        Node* temp = h1;

        while (h1->next != NULL && h2 != NULL)      
        {
            if (h1->next->data < h2->data)           
            {
                h1 = h1->next;
            }
            else
            {
                Node* x = h1->next;

                h1->next = h2;

                h2 = h2->next;

                h1->next->next = x;

                h1 = h1->next;
            }
        }

        if (h2 != NULL)
            h1->next = h2;

        return temp;
    }

    void display(Node* head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
    }
};

int main()
{
    Node* h1 = new Node(1);
    h1->next = new Node(5);
    h1->next->next = new Node(8);
    h1->next->next->next = new Node(10);

    Node* h2 = new Node(2);
    h2->next = new Node(9);
    h2->next->next = new Node(12);
    h2->next->next->next = new Node(15);

    LinkedList obj;

    h1 = obj.merge(h1, h2);

    obj.display(h1);

    return 0;
}