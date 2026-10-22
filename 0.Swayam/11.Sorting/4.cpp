/*Shell sort*/

/*
Proper Question
Q4. Write a C++ program to sort an array of elements in ascending order using the Shell Sort algorithm.

Working

Shell Sort is an improved version of Insertion Sort.

Instead of comparing only adjacent elements, it first compares elements that are far apart using a gap.

For example:

10 7 8 9 1 5

Initial gap:

gap = n / 2

For n = 6:

gap = 3

Elements with gap 3 are compared.

Then gap becomes smaller:

3 → 1

When gap = 1, it behaves like Insertion Sort.*/

#include <iostream>
using namespace std;

void shellSort(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];

            int j = i;

            while (j >= gap && a[j - gap] > temp)
            {
                a[j] = a[j - gap];
                j = j - gap;
            }

            a[j] = temp;
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

    shellSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}