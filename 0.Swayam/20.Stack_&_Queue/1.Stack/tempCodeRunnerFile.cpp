/*
Question: Implement Stack Using an Array in C++
Write a C++ program to implement a Stack using an array. Perform the following basic operations:
1. push(x) – Insert an element into the stack.
2. pop() – Remove the top element from the stack.
3. top() – Return the top element of the stack.
4. size() – Return the number of elements in the stack.
5. isEmpty() – Check whether the stack is empty.
6. display() – Display all elements of the stack.
*/
/*
The role of topIndex in a stack implemented using an array is to keep track of the index of the topmost element of the stack.

                                                 top = -1

Index:   0     1     2     3     4
      +-----+-----+-----+-----+-----+
arr = |     |     |     |     |     |
      +-----+-----+-----+-----+-----+

      
      */
#include <iostream>
using namespace std;

#define MAX 5

class Stack {
    int arr[MAX];
    int topIndex;

public:                        // Constructor: runs automatically when an object is created
    Stack() {
        topIndex = -1;
    }


    // Insert an element into the stack
    void push(int x) {
        if (topIndex == MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        topIndex++;
        arr[topIndex] = x;

        cout << x << " pushed into stack" << endl;
    }

    // Remove the top element
    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }

        cout << arr[topIndex] << " popped from stack" << endl;
        topIndex--;
    }

    // Return the top element
    void top() {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top element: " << arr[topIndex] << endl;
    }

    // Return the number of elements
    void size() {
        cout << "Stack size: " << topIndex + 1 << endl;
    }

    // Check whether the stack is empty
    void isEmpty() {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack is not empty" << endl;
        }
    }

    // Display all stack elements
    void display() {
        if (topIndex == -1) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";

        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

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
