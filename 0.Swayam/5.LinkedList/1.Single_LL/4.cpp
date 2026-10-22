/*Given the head of a singly linked list, reverse the list in place and return the new head.*/

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

// Reverse the linked list iteratively
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* nextNode = curr->next; // save next node
        curr->next = prev;           // reverse the link
        prev = curr;                 // move prev forward
        curr = nextNode;             // move curr forward     
    }

    return prev;  // prev is the new head
}

// Helper to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Build list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Original list: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}




/*function declaration/signature 
ListNode* reverseList(ListNode* head)

1.ListNode* (the first one, before the function name) — return type  
This means the function returns a pointer to a ListNode

2. reverseList — function name
Just the name of the function, chosen to describe what it does.

3. (ListNode* head) — parameter
This function takes one argument: a pointer named head, which points to a ListNode. This is the head (starting node) of the original linked list that you want to reverse.
*/




/*
START:
NULL   1 → 2 → 3 → NULL
prev  curr

Step 1: (curr = 1)
  next = curr->next   → next points to 2
  curr->next = prev   → 1 now points to NULL (arrow flipped!)    
  
  NULL ← 1    2 → 3 → NULL
  prev   curr next

  prev = curr  → prev moves to 1
  curr = next  → curr moves to 2
  
  

  
  Step 2: (curr = 2)
  next = curr->next   → next points to 3
  curr->next = prev   → 2 now points to 1 (arrow flipped!)

  NULL ← 1 ← 2    3 → NULL
        prev  curr next

  prev = curr → prev moves to 2
  curr = next → curr moves to 3
  


  
  Step 3: (curr = 3)
  next = curr->next   → next points to NULL
  curr->next = prev   → 3 now points to 2 (arrow flipped!)

  NULL ← 1 ← 2 ← 3    NULL
             prev  curr/next

  prev = curr → prev moves to 3
  curr = next → curr becomes NULL
  
  
  LOOP STOPS because curr == NULL




FINAL RESULT:
NULL ← 1 ← 2 ← 3
              ↑
            prev (this is returned as new head!)

New list: 3 → 2 → 1 → NULL ✅*/ 