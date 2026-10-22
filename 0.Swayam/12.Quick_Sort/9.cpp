/*Q8. Quick Sort — Partition Concept

Your handwritten notes also contain the Quick Sort partition concept, so this is important to keep in your sorting notes.

Question

Implement Quick Sort using the partition technique.

Concept

Quick Sort selects a pivot and places it at its correct position.

For example:

[5, 3, 8, 4, 2, 7, 1, 10]

Pivot = 5

Elements smaller than 5 → left
Elements greater than 5 → right

[3, 4, 2, 1]  5  [8, 7, 10]

Then we recursively sort the left and right portions.*/

#include <bits/stdc++.h>
using namespace std;

int partitionArray(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];

    int i = low;
    int j = high;

    while (i < j)
    {
        while (i <= high && arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);

    return j;
}

void quickSort(vector<int>& arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int pivotIndex = partitionArray(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);

    quickSort(arr, pivotIndex + 1, high);
}

int main()
{
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 10};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}