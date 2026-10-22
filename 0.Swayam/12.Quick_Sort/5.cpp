/*Q4. Find K Largest and K Smallest Elements
Question

Given an array and an integer k, find the k largest elements and k smallest elements.

Example:

Array = [5, 1, 3, 2, 4, 8, 6, 7, 9]
k = 3

Sorted array:

[1, 2, 3, 4, 5, 6, 7, 8, 9]

Therefore:

3 smallest = 1 2 3
3 largest  = 7 8 9
Concept

After sorting:

First k elements → k smallest
Last k elements  → k largest*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {5, 1, 3, 2, 4, 8, 6, 7, 9};

    int k = 3;

    sort(arr.begin(), arr.end());

    cout << "K Smallest Elements: ";

    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "K Largest Elements: ";

    for (int i = arr.size() - k; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
/*Time  : O(n log n)
Space : O(1) auxiliary*/