/*
Problem Statement:
Given the head of a singly linked list, print all its elements recursively (without using loops).
Recursion naturally fits this problem because a linked list is itself a recursive structure — a node followed by "the rest of the list," which is a smaller linked list.*/

#include <iostream>
using namespace std;

// Node structure
struct Node{
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;  
    }
};


//1. Recursive traversal pattern
void printListRecursive(Node* head) {
    // Base case: empty list / end reached
    if (head == nullptr)
        return;

    // Print current node
    cout << head->data;
    if (head->next != nullptr)
        cout << " -> ";

    // Recurse on the rest of the list
    printListRecursive(head->next);
}

//2. Function to count nodes
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


//3.Insert node at beginning
Node* insertBegg(Node* head, int val) {
    Node* newNode = new Node(val);

    newNode->next = head;

    return newNode;
}



//4. Insert a value into a sorted linked list, keeping it sorted
Node* insertSorted(Node* head, int val) {
    
    Node* newNode = new Node(val);

    // Case 1: List is empty -> new node becomes the head
    if (head == nullptr) {  
        return newNode; 
    }

    // Case 2: New value is smaller than the head -> insert at front
    if (val < head->data) {  
        newNode->next = head; 
        return newNode;  
    }
    
    // Insert a value into a sorted linked list, keeping it sorted
    Node* curr = head;

    while (curr->next != nullptr && curr->next->data <= val) {  
        curr = curr->next;  
    }

    // Insert newNode right after curr
    newNode->next = curr->next; 
    curr->next = newNode;

    return head;
}



//5. Reverse the linked list iteratively
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





/*

// Insert a value into a sorted linked list, keeping it sorted

Node* insertSorted(Node* head, int val) {  
    Node* newNode = new Node(val);        
                                      
    if (head == nullptr) {  
        return newNode; 
    }
    
    if (val < head->data) {  
        newNode->next = head; 
        return newNode;  
    }
  
    Node* curr = head;    
    while (curr->next != nullptr && curr->next->data <= val) {  
        curr = curr->next;  
    }

    */



/*
// Reverse the linked list iteratively
Node* reverseList(Node* Head) {      //it will return you the Node value which point to the last node of the list.   
    Node* prev = nullptr;
    Node* curr = Head;

    while (curr != nullptr) {        //nullptr==NULL
        Node* nextNode = curr->next; // save next node
        curr->next = prev;           // reverse the link
        prev = curr;                 // move prev forward
        curr = nextNode;             // move curr forward     
    }

    return prev;  // prev is the new head
*/





//print Nodes of a LL
    void printLL(Node* Head){
    if(Head==NULL) return;

    cout << Head->data;
    if(Head->next!=NULL)
    cout<<"->";

    printLL(Head->next);
}

int main(){
    Node* Head=new Node(1);
    Head->next=new Node(2);
    Head->next->next=new Node(3);
    Head->next->next->next=new Node(4);

    
    printLL(Head);
    cout<<endl;

    return 0;
}