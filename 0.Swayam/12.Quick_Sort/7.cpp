/*Q6. Find Median in an Array
Question

Find the median of a given array.

Example:

Array = [1, 5, 8, 200, 5000]

After sorting:

[1, 5, 8, 200, 5000]

There are 5 elements, so the middle element is:

Median = 8
Concept

First sort the array.

Case 1: Odd number of elements

If:

n = 5

Median is:

arr[n/2]
Case 2: Even number of elements

If:

n = 6

Median is average of the two middle elements:

(arr[n/2 - 1] + arr[n/2]) / 2*/

#include <bits/stdc++.h>
using namespace std;

double findMedian(vector<int>& arr)
{
    sort(arr.begin(), arr.end());

    int n = arr.size();

    if (n % 2 == 1)
    {
        return arr[n / 2];
    }
    else
    {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
}

int main()
{
    vector<int> arr = {1, 5, 8, 200, 5000};

    cout << "Median = " << findMedian(arr) << endl;

    return 0;
}

/*Time  : O(n log n)
Space : O(1) auxiliary*/