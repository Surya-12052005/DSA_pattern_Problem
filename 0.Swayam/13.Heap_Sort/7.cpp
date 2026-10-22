/*
MIN HAP : In a Min Heap, the parent is always smaller than or equal to its children.
MAX HAP : In a Max Heap, the parent is always greater than or equal to its children.
GIVN A MAX HAEP TRee , THe ROOT IS SMALL THN THE SUBROOT, haepfy THE tree  */

/*Yes. You are describing a Max Heap where the root must be greater than its children.

If the root is smaller than a child, we need to heapify the tree.

Example

Suppose the tree is:

        10
       /  \
     30    20
    /  \
   5    15

Here, 10 < 30, so the Max Heap property is violated.

Max Heap Property

For every node:

Parent >= Left Child
Parent >= Right Child

So we compare the parent with its children and move the largest value upward.

After heapifying:

        30
       /  \
     15    20
    /  \
   5    10

Now:

30 > 15, 20
15 > 5, 10

So it is a valid Max Heap.*/

#include <iostream>
using namespace std;

// Heapify function
void heapify(int arr[], int n, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Check right child
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // If largest is not parent
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Build Max Heap
void buildMaxHeap(int arr[], int n)
{
    // Start from last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

// Print array
void printHeap(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[] = {10, 30, 20, 5, 15};

    int n = 5;

    cout << "Before Heapify: ";
    printHeap(arr, n);

    // Convert into Max Heap
    buildMaxHeap(arr, n);

    cout << "After Heapify (Max Heap): ";
    printHeap(arr, n);

    return 0;
}

/* 
// Heapify function
void heapify(int arr[], int n, int i)
{
    // Assume that the current node is the largest
    int largest = i;

    // Find the index of left child
    int left = 2 * i + 1;

    // Find the index of right child
    int right = 2 * i + 2;


    // Check if left child exists
    // and left child is greater than current largest
    if (left < n && arr[left] > arr[largest])
    {
        // Make left child the largest
        largest = left;
    }


    // Check if right child exists
    // and right child is greater than current largest
    if (right < n && arr[right] > arr[largest])
    {
        // Make right child the largest
        largest = right;
    }


    // If largest is not the parent,
    // it means one of the children is bigger
    if (largest != i)
    {
        // Swap parent with the largest child
        swap(arr[i], arr[largest]);


        // After swapping, the subtree may still
        // not be a Max Heap, so heapify it again
        heapify(arr, n, largest);
    }
} */


/*// Function to convert the complete array into a Max Heap
void buildMaxHeap(int arr[], int n)
{
    // Leaf nodes are already in correct position.
    // So, we start from the last non-leaf node.
    int start = n / 2 - 1;


    // Move from the last non-leaf node towards the root
    for (int i = start; i >= 0; i--)
    {
        // Fix the tree at index i
        // and make it a Max Heap
        heapify(arr, n, i);
    }
}*/