//QUEUE: FIFO
/* Perform the following operations on a Queue:

What are the basic operations of a Queue?
push(x)   // Insert an element into the queue
pop()     // Remove the front element
front()   // Return the front element
size()    // Return the number of elements

Q1. Perform the following operations on a Queue:
push(2)    -> 2
push(2)    -> 2, 2
push(4)    -> 2, 2, 4
push(1)    -> 2, 2, 4, 1
pop()      -> 2, 4, 1
front()    -> 2
front()    -> 2
pop()      -> 4, 1
push(5)    -> 4, 1, 5
front()    -> 4
size()     -> 3
*/

/*
2. Understand the important variables
queue<Node*> q;
q.push(root);


- queue<Node*> q — creates a queue that stores node addresses.
- q.push(root) — inserts the root node (5) into the queue.
- Node* temp = q.front() — stores the address of the first node in temp.
- q.pop() — removes the front node from the queue.
- temp->data — accesses the data of the node stored in temp.
Remember: A queue follows FIFO — First In, First Out.*/