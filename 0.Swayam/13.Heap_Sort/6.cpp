/*Q10. Heap is a Priority Queue + Heap Sort
Part A — What is a Heap?

A Heap is a Complete Binary Tree that follows the Heap Property.

There are two types:

Max Heap

Parent is greater than its children.

          50
        /    \
       30     40
      /  \   / \
     10  20 35  5
Parent >= Children
Min Heap

Parent is smaller than its children.

          10
        /    \
       20     15
      /  \   / \
     30  25 40  50
Parent <= Children
Why is Heap a Priority Queue?

A Priority Queue removes the element having the highest/lowest priority first.

A Heap gives us this efficiently.

Max Heap
Highest priority = Maximum element
Min Heap
Highest priority = Minimum element

Therefore:

Priority Queue
      ↓
Can be implemented using Heap
Heap Sort
Question

Write a C++ program to implement Heap Sort using a Max Heap.

Suppose:

arr = {5, 3, 8, 4, 1, 2}

Heap Sort converts it into:

1 2 3 4 5 8*/

#include <iostream>
using namespace std;

// Heapify a subtree
void heapify(int arr[], int n, int i) {

    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check right child
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {

        swap(arr[i], arr[largest]);

        // Recursively heapify affected subtree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {

        // Move largest element to the end
        swap(arr[0], arr[i]);

        // Heapify remaining heap
        heapify(arr, i, 0);
    }
}

int main() {

    int arr[] = {5, 3, 8, 4, 1, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    heapSort(arr, n);

    cout << "\nSorted Array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}