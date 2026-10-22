/*Selection sort*/

/*2. Selection Sort
Proper Question

Q2. Write a C++ program to sort an array of elements in ascending order using the Selection Sort algorithm.

Working

Selection Sort divides the array into:

Sorted part
Unsorted part

For every position:

1.Find the smallest element from the unsorted part.
2.Swap it with the first element of the unsorted part.
3.Continue until the array is sorted.

Example:

5 3 8 1 2

Smallest = 1

1 3 8 5 2

Next smallest = 2

1 2 8 5 3

Next smallest = 3

1 2 3 5 8*/

#include <iostream>
using namespace std;

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;                   //Assume current element is minimum (ie: minIndex=0)
                                            //We temporarily assume 5 is the smallest.
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        swap(a[i], a[minIndex]);
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

    selectionSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}