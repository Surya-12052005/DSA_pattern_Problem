/*givn two link list  whos ha ar h1, h2 (h1->1->5->8->10) an (h2->2->->9->12->15) , w hav top mrg two link list  , ie( 1->2->->->5->8->9->10->12->15 )*/
//use h3(new pointer)
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
        Node* h3 = NULL;
        Node* tail = NULL;

        while (h1 != NULL && h2 != NULL)
        {
            Node* temp;

            if (h1->data < h2->data)
            {
                temp = h1;
                h1 = h1->next;
            }
            else
            {
                temp = h2;
                h2 = h2->next;
            }

            if (h3 == NULL)
            {
                h3 = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }

        if (h1 != NULL)
            tail->next = h1;

        if (h2 != NULL)
            tail->next = h2;

        return h3;
    }

    void display(Node* h3)
    {
        while (h3 != NULL)
        {
            cout << h3->data << " ";
            h3 = h3->next;
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

    Node* h3 = obj.merge(h1, h2);

    cout << "Merged List: ";

    obj.display(h3);

    return 0;
}