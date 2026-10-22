/*Q7. How to Sort 10 Million Integers?
Question

Suppose we have 10 million integers and we need to sort them efficiently.

What sorting algorithm should we use?

Concept

For a large number of integers, Merge Sort is a good general-purpose choice because it has guaranteed:

O(n log n)

time complexity.

Merge Sort follows:

Divide → Sort → Merge

Example:

[38, 27, 43, 3, 9, 82, 10]

              Divide
                 ↓
        [38,27,43] [3,9,82,10]
             ↓          ↓
           Sort        Sort
             ↓          ↓
        [27,38,43] [3,9,10,82]
                 ↓
               Merge
                 ↓
       [3,9,10,27,38,43,82]*/

       #include <bits/stdc++.h>
using namespace std;

void mergeArray(vector<int>& arr, int low, int mid, int high)
{
    vector<int> temp;

    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = low; k <= high; k++)
    {
        arr[k] = temp[k - low];
    }
}

void mergeSort(vector<int>& arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    mergeArray(arr, low, mid, high);
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";

    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}