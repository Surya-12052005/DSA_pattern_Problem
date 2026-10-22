/*1. Bubble Sort
Proper Question

Q1. Write a C++ program to sort an array of elements in ascending order using the Bubble Sort algorithm.

Working

Bubble Sort repeatedly compares two adjacent elements.

If the left element is greater than the right element, swap them.
After one complete pass, the largest element moves to the end.
Repeat until the array is sorted.

Example:

5 3 8 1 2

After passes:

3 5 1 2 8
3 1 2 5 8
1 2 3 5 8*/

#include <iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)    //This loop controls the number of passes.
    {
        for (int j = 0; j < n - 1 - i; j++)  //This compares adjacent elements:
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int a[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bubbleSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

