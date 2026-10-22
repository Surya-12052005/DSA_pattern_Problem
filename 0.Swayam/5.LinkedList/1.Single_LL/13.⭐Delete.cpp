/*
# LeetCode 237: Delete Node in a Linked List

**Difficulty:** Medium

**Problem:**

You are given a node in a singly linked list that needs to be deleted. You are not given access to the head of the linked list.

Each node contains an integer value and a pointer to the next node.

Delete the given node from the linked list.

**Conditions:**
- You are not given access to the head of the linked list.
- All node values are unique.
- The given node is guaranteed not to be the last node.
- The value of the given node must no longer appear in the linked list.

**Example 1:**

Input: `head = [4,5,1,9]`, `node = 5`

Output: `[4,1,9]`

**Example 2:**

Input: `head = [4,5,1,9]`, `node = 1`

Output: `[4,5,9]`

**Expected complexity:**
- Time: O(1)
- Auxiliary space: O(1)*/



#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Delete the given node

    void deleteNode(Node* node) {
        node->data = node->next->data;
        node->next = node->next->next;
    }

// Print linked list
void printLL(Node* head) {
    if (head == NULL) return;

    cout << head->data;
    if (head->next != NULL)
        cout << " -> ";

    printLL(head->next);
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printLL(head);

    int value;
    cout << "\nEnter value to delete: ";
    cin >> value;

    Node* temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL) {
        deleteNode(temp);
    } else {
        cout << "Deletion not possible!";
        return 0;
    }

    cout << "Updated List: ";
    printLL(head);

    return 0;
}




/*
inside the main function:

Original List: 1 -> 2 -> 3 -> 4 -> 5
Now value = 3.

Dry run of the while loop:

Iteration	temp->data	Condition temp->data != 3	    Action
1            	1	        1 != 3 → true           	Move to next node
2	            2	        2 != 3 → true           	Move to next node
3            	3	        3 != 3 → false          	Stop 

Now temp points to the node containing 3



Step 4: Check whether deletion is possible
if (temp != NULL && temp->next != NULL)

Evaluate both conditions:
- temp != NULL → true, because node 3 exists.
- temp->next != NULL → true, because node 3 points to node 4.
Therefore, the if condition is true, and your code calls:
s.deleteNode(temp);


*/