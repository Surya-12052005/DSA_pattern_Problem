/*
Question: Implement Queue Using an Array in C++
Write a C++ program to implement a Queue using an array. Perform the following basic operations:
1. push(x) – Insert an element into the queue.
2. pop() – Remove the front element from the queue.
3. front() – Return the front element of the queue.
4. size() – Return the number of elements in the queue.
5. isEmpty() – Check whether the queue is empty.
6. display() – Display all elements of the queue.
*/

/*

frontIndex = 0
rearIndex  = -1
count      = 0

          frontIndex
               ↓
Index:    0       1       2       3       4
       +-------+-------+-------+-------+-------+
arr =  |       |       |       |       |       |
       +-------+-------+-------+-------+-------+
       ↑
     (front)

Rear = -1 (no element inserted)

*/


#include <iostream>
using namespace std;

#define MAX 5

// Queue structure
class Queue {
    int arr[MAX];
    int frontIndex;   
    int rearIndex;
    int count;

public:
    // Constructor: initializes an empty queue
    Queue() {
        frontIndex = 0;    //Stores the index of the first element in the queue.
        rearIndex = -1;   //Stores the index of the last inserted element in the queue.
        count = 0;       //Stores the total number of elements currently present in the queue.
    }

    // Insert an element into the queue
    void push(int x) {
        if (count == MAX) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        rearIndex = (rearIndex + 1) % MAX;
        arr[rearIndex] = x;
        count++;

        cout << x << " pushed into queue" << endl;
    }

    // Remove the front element
    void pop() {
        if (count == 0) {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << arr[frontIndex] << " popped from queue" << endl;

        frontIndex = (frontIndex + 1) % MAX;
        count--;
    }

    // Return the front element
    void front() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Front element: " << arr[frontIndex] << endl;
    }

    // Return the number of elements
    void size() {
        cout << "Queue size: " << count << endl;
    }

    // Check whether the queue is empty
    void isEmpty() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue is not empty" << endl;
        }
    }

    // Display all queue elements
    void display() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements (front to rear): ";

        for (int i = 0; i < count; i++) {
            cout << arr[(frontIndex + i) % MAX] << " ";
        }

        cout << endl;
    }
};  // Queue structure ends here


// Main function
int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.display();

    q.front();
    q.size();
    q.isEmpty();

    q.pop();

    q.display();
    q.size();

    return 0;
}
