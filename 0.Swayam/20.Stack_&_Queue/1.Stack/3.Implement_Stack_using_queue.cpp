/*
Write a C++ program to implement a Stack using a Queue. Perform the following basic operations:
1. push(x) – Insert an element into the stack.
2. pop() – Remove the top element from the stack.
3. top() – Return the top element of the stack.
4. size() – Return the number of elements in the stack.
5. isEmpty() – Check whether the stack is empty.
6. display() – Display all elements of the stack from top to bottom.
We will use
*/

/*
Question: Implement Stack Using Queue
Approach (Short):
1. Use one queue to implement the stack.
2. In push(x), insert x into the queue.
3. Move all previously existing elements behind x by repeatedly removing the front element and inserting it at the rear.
4. Now, the newest element stays at the front, following LIFO (Last In, First Out).
5. pop() removes the front element, and top() returns the front element.
*/


#include <iostream>
#include <queue>
using namespace std;

// Stack structure using Queue
class Stack {
    queue<int> q;

public:
    // Insert an element into the stack
    void push(int x) {
        int n = q.size();

        q.push(x);

        // Move previous elements behind the new element
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << x << " pushed into stack" << endl;
    }

    // Remove the top element
    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << q.front() << " popped from stack" << endl;
        q.pop();
    }

    // Return the top element
    void top() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top element: " << q.front() << endl;
    }

    // Return the number of elements
    void size() {
        cout << "Stack size: " << q.size() << endl;
    }

    // Check whether the stack is empty
    void isEmpty() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack is not empty" << endl;
        }
    }

    // Display elements from top to bottom
    void display() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        queue<int> temp = q;

        cout << "Stack elements (top to bottom): ";

        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};  // Stack structure ends here


// Main function
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.top();
    s.size();
    s.isEmpty();

    s.pop();

    s.display();
    s.size();

    return 0;
}
