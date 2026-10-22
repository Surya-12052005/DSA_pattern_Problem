/*Insertion sort*/

/*3. Insertion Sort

Q3. Write a C++ program to sort an array of elements in ascending order using the Insertion Sort algorithm.

Working
Insertion Sort works similar to arranging playing cards in your hand.

Suppose:

5 3 8 1 2

Take 3.

Compare it with 5:

3 5 8 1 2

Take 8:

3 5 8 1 2

Take 1:

1 3 5 8 2

Take 2:

1 2 3 5 8*/

#include <iostream>
using namespace std;

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)        
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
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

    insertionSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}