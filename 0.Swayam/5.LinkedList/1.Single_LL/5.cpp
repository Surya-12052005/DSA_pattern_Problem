/*Given the head of a sorted (ascending order) singly linked list and a value, insert a new node with that value into the list such that the list remains sorted. Return the head of the updated list.*/

#include <iostream>
using namespace std;

struct Node {  //This creates a new "blueprint" called Node. Think of it like a template for a box that will hold a value and a link to the next box.
    int data;  //Each Node box stores one integer
    Node* next; //This is a pointer — basically an arrow pointing to the next Node box in the list
    Node(int val) : data(val), next(nullptr) {} //This is the constructor — a special function that runs automatically whenever you create a new Node
};                                            // explained below

// Insert a value into a sorted linked list, keeping it sorted
Node* insertSorted(Node* head, int val) {  //This is a function named insertSorted. this take two input , "head", "val".
    Node* newNode = new Node(val);        //This creates a brand-new box (Node) on the heap, using the constructor we discussed earlier.
                                         //val is stored as data, and next is automatically set to nullptr (not connected to anything yet).
    // Case 1: List is empty -> new node becomes the head
    if (head == nullptr) {  
        return newNode; //Since there's nothing to insert into, newNode (the box we just created) simply becomes the list.
    }

    // Case 2: New value is smaller than the head -> insert at front
    if (val < head->data) {  //This checks: "Is the new value smaller than the current first value?"
        newNode->next = head; //This attaches newNode to the front of the chain, right before the old first node.
        return newNode;  //Since newNode is now the first box in the list, we return it as the new head.
    }

    // Case 3: Find the right spot in the middle or at the end
    Node* curr = head;    //curr is a pointer we'll use to "walk" down the list, one box at a time.
    while (curr->next != nullptr && curr->next->data <= val) {  //Stop as soon as you find a next box that's bigger than your new value
        curr = curr->next;  
    }

    // Insert newNode right after curr
    newNode->next = curr->next;  //Point newNode's arrow to whatever curr was currently pointing to.
    curr->next = newNode;  //Now redirect curr's arrow to point at newNode instead of whatever it pointed to before

    return head;
}

// Print the list like: 10 -> 20 -> 30
void printList(Node* head) {  //Takes the head of the list as input.
    Node* curr = head;       //curr is our "walking pointer," starting at the first node.
    while (curr != nullptr) {  //Keep looping as long as curr is pointing to a real node.
        cout << curr->data;   //Print the value stored in the current box.
        if (curr->next != nullptr) cout << " -> ";  //Only print the arrow " -> " if there's another node after this one.
        curr = curr->next;  //Move curr forward to the next box, so the loop can process it next.
    }
    cout << endl;
}

int main() {
    // Build sorted list: 10 -> 20 -> 40 -> 50  //head points to it. Its next is automatically nullptr (from the constructor).
    Node* head = new Node(10);  //Purpose: Manually create a linked list of 4 nodes by creating each box and connecting it to the previous one, one line at a time.
    head->next = new Node(20);
    head->next->next = new Node(40);
    head->next->next->next = new Node(50);

    cout << "Original list: ";
    printList(head);

    head = insertSorted(head, 30); // insert in the middle
    cout << "After inserting 30: ";
    printList(head);

    head = insertSorted(head, 5);  // insert at the front
    cout << "After inserting 5: ";
    printList(head);

    head = insertSorted(head, 100); // insert at the end
    cout << "After inserting 100: ";
    printList(head);

    return 0;
}

/* 
 Node(int val) : data(val), next(nullptr) {}
This is the constructor — a special function that runs automatically whenever you create a new Node. It sets things up so you don't have to do it manually every time.

Node(int val) → when you write new Node(10), the 10 goes into val.
data(val) → stores that value into data.
next(nullptr) → automatically sets next to "nothing" (no next node yet), since a brand-new node isn't connected to anything yet.*/