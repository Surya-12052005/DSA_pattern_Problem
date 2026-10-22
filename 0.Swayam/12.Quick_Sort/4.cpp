/*Q3. Find the Kth Largest and Kth Smallest Element
Question

Given an array and an integer k, find the:

Kth smallest element
Kth largest element

Example:

Array = [5, 1, 3, 2, 4, 8, 6, 7, 9]
k = 3

After sorting:

[1, 2, 3, 4, 5, 6, 7, 8, 9]

Therefore:

3rd smallest = 3
3rd largest  = 7
Concept

The simplest approach is:

1.Sort the array.
2.Kth smallest = arr[k-1]
3.Kth largest = arr[n-k]*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {5, 1, 3, 2, 4, 8, 6, 7, 9};

    int k = 3;

    sort(arr.begin(), arr.end());

    int n = arr.size();

    cout << "Kth Smallest Element = " << arr[k - 1] << endl;
    cout << "Kth Largest Element = " << arr[n - k] << endl;

    return 0;
}

/*Sorting : O(n log n)
Space   : O(1) auxiliary (ignoring sort implementation details)*/