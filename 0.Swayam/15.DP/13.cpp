/*Rod Cutting Problem
Properly Framed Question

You are given an iron rod of length 6 meters. The rod can be cut into smaller pieces, and each piece has a selling price based on its length.

The price table is:

Rod Length	1m	2m	3m	4m	5m	6m
Price	1	4	5	8	11	12

So we can represent the prices as:

int val[] = {0, 1, 4, 5, 8, 11, 12};

The 0 at index 0 means a rod of length 0 has value 0.

Task

Given a rod of length n, cut the rod into one or more pieces such that the total selling price is maximum.

For:

n = 6

find the maximum possible value.

Example

We can cut the 6m rod in different ways:

6m → 6
Value = 12
6m → 3 + 3
Value = 5 + 5 = 10
6m → 2 + 2 + 2
Value = 4 + 4 + 4 = 12
6m → 1 + 1 + 1 + 1 + 1 + 1
Value = 1 + 1 + 1 + 1 + 1 + 1 = 6
6m → 2 + 4
Value = 4 + 8 = 12

The maximum is:

12

In fact, several cutting patterns give 12.

Recursive Solution — Include / Exclude

Based on the approach in your image, we can think:

At every position, we have two choices:

Include the current piece → take its value and continue from the remaining rod.
Exclude the current piece → move to the next possible piece length.

int maxVal(int n){
}
*/

#include <iostream>
using namespace std;

int val[] = {0, 1, 4, 5, 8, 11, 12};

int maxVal(int a[], int i, int n)
{
    // No rod left
    if (n == 0)
        return 0;

    // No more pieces to try
    if (i > n)
        return 0;

    // INCLUDE
    int x = a[i] + maxVal(a, i, n - i);

    // EXCLUDE
    int y = maxVal(a, i + 1, n);

    return max(x, y);
}

int main()
{
    int n = 6;

    cout << "Maximum value = " << maxVal(val, 1, n);  

    return 0;
}