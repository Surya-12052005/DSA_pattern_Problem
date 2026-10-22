/*
    Problem   : Merge Sort
    Difficulty: Easy
    Topic     : Divide and Conquer

    Sort an array using the merge sort algorithm.

    Example:
    Input : arr = [5,2,4,7,1,3,2,6]
    Output: [1,2,2,3,4,5,6,7]

    Approach:
    - Divide the array into two halves recursively until size 1.
    - Conquer: merge two sorted halves into one sorted array.

    Time Complexity : O(n log n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = left; k <= right; k++) arr[k] = temp[k - left];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {5,2,4,7,1,3,2,6};
    mergeSort(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
