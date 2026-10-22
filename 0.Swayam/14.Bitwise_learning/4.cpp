/*Q4. Find the Repeating Element
Proper Question

Given an array containing n elements where all elements are unique except one element that appears twice, find the repeating element.

Example
Array = [1, 2, 3, 4, 3]

Repeating element = 3
Concept

Since numbers are from 1 to n-1, we can XOR:

All numbers from 1 to n-1

with:

All array elements

The unique numbers cancel, leaving the repeating number.*/

#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 3};

    int n = 5;
    int ans = 0;

    // XOR numbers from 1 to n-1
    for (int i = 1; i < n; i++) {
        ans = ans ^ i;
    }

    // XOR array elements
    for (int i = 0; i < n; i++) {
        ans = ans ^ a[i];
    }

    cout << "Repeating element = " << ans;

    return 0;
}