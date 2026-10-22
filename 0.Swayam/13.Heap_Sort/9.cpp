/*Q. Deletion from a Max Heap
Question

Write a C++ function to delete the maximum element (root element) from a Max Heap and maintain the Max Heap property.

Concept

In a Max Heap, the maximum element is always at the root, i.e. at index 0.

To delete the root:

1.Store the root value.
2.Replace the root with the last element.
3.Reduce the heap size by 1.
4.Apply Heapify Down from the root.
5.Return the deleted value.*/

#include <iostream>
using namespace std;

// Function to maintain Max Heap property
void heapify(int a[], int n, int i)
{
    int largest = i;          // Assume current element is largest
    int left = 2 * i + 1;     // Left child
    int right = 2 * i + 2;    // Right child

    // Check if left child is greater
    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }

    // Check if right child is greater
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }

    // If largest is not the current element
    if (largest != i)
    {
        // Swap current element with largest child
        swap(a[i], a[largest]);

        // Continue heapifying downward
        heapify(a, n, largest);
    }
}

// Function to remove the root from Max Heap
int remove(int a[], int n)
{
    // Check if heap is empty
    if (n <= 0)
    {
        throw "Heap is empty";
    }

    // Store the root value
    int val = a[0];

    // Replace root with the last element
    a[0] = a[n - 1];

    // Reduce heap size by 1
    n--;

    // Restore Max Heap property
    heapify(a, n, 0);

    // Return deleted value
    return val;
}

int main()
{
    int a[100] = {14, 8, 10, 5, 7, 9, 3, 0, 1, 4};
    int n = 10;

    // Delete maximum element
    int deleted = remove(a, n);
    n--;

    cout << "Deleted element: " << deleted << endl;   

    cout << "Max Heap after deletion: ";

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

