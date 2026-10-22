/*Q1. Insertion in a Max Heap
Question

Write a C++ program to insert a new element into a Max Heap and maintain the Max Heap property after insertion.

Concept

A Max Heap is a complete binary tree in which:

Parent >= Child

When a new element is inserted:

1.Insert the element at the end of the heap.
2.Compare it with its parent.
3.If the new element is greater than its parent, swap them.
4.Continue moving the element upward.
5.Stop when the Max Heap property is satisfied.

This process is called Heapify Up or Bubble Up.

Parent Formula

For an element at index i:

Parent = (i - 1) / 2*/

#include <iostream>
using namespace std;

void insert(int a[], int n, int val)
{
    // Insert value at the end
    a[n] = val; 

    // Heapify Up
    while (n > 0)
    {
        int p = (n - 1) / 2;

        // If child is greater than parent
        if (a[n] > a[p])
        {
            swap(a[n], a[p]);
            n = p;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int a[100] = {50, 40, 30, 20, 10};
    int n = 5;

    int val = 60;

    insert(a, n, val);
    n++;

    cout << "Max Heap after insertion: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

/*#include <iostream>
using namespace std;

// Function to insert a new value into Max Heap
void insert(int a[], int n, int val)
{
    // Step 1: Put the new value at the end of the heap
    a[n] = val;

    // Step 2: Check the new element with its parent
    // Continue until the element reaches the correct position
    while (n > 0)
    {
        // Find the index of the parent
        int p = (n - 1) / 2;

        // If child is greater than parent,
        // Max Heap property is violated
        if (a[n] > a[p])
        {
            // Swap child and parent
            swap(a[n], a[p]);

            // After swapping, move to the parent's position
            // and continue checking
            n = p;
        }
        else
        {
            // Parent is already greater than child,
            // so Max Heap property is satisfied
            break;
        }
    }
}

int main()
{
    // Existing Max Heap
    int a[100] = {50, 40, 30, 20, 10};

    // Current number of elements
    int n = 5;

    // Value that we want to insert
    int val = 60;

    // Insert 60 into the Max Heap
    insert(a, n, val);

    // Increase the size because one new element was inserted
    n++;

    // Print the final Max Heap
    cout << "Max Heap: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}*/