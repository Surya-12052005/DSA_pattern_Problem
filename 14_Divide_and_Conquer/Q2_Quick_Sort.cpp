/*
    Problem   : Quick Sort
    Difficulty: Easy
    Topic     : Divide and Conquer

    Sort an array using the quick sort algorithm (Lomuto partition).

    Example:
    Input : arr = [10,7,8,9,1,5]
    Output: [1,5,7,8,9,10]

    Approach:
    - Choose a pivot (commonly the last element).
    - Partition the array so elements smaller than pivot go left,
      larger go right; place pivot in its correct sorted position.
    - Recursively sort the left and right partitions.

    Time Complexity : O(n log n) average, O(n^2) worst case
    Space Complexity: O(log n) recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {10,7,8,9,1,5};
    quickSort(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
