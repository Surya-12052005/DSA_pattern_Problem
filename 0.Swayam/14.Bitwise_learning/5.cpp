/*Q5. Find Both Missing and Repeating Elements Using Bitwise Operation
Proper Question

Given an array of n elements containing numbers from 1 to n, one number is missing and one number is repeated. Find both the missing and repeating elements using bitwise XOR operations.

Example
Array = [1, 2, 2, 4, 5]

Numbers should be:

1 2 3 4 5

Missing = 3
Repeating = 2
Concept

First XOR:

1 ^ 2 ^ 3 ^ 4 ^ 5

with:

1 ^ 2 ^ 2 ^ 4 ^ 5

The result becomes:

Missing ^ Repeating

Then we separate the two numbers using a set bit*/

#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 2, 4, 5};

    int n = 5;

    int xorValue = 0;

    // XOR all array elements
    for (int i = 0; i < n; i++) {
        xorValue = xorValue ^ a[i];
    }

    // XOR numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        xorValue = xorValue ^ i;
    }

    // Find the rightmost set bit
    int bit = xorValue & (-xorValue);

    int x = 0;
    int y = 0;

    // Divide array elements into two groups
    for (int i = 0; i < n; i++) {
        if (a[i] & bit) {
            x = x ^ a[i];
        } else {
            y = y ^ a[i];
        }
    }

    // Divide numbers from 1 to n into two groups
    for (int i = 1; i <= n; i++) {
        if (i & bit) {
            x = x ^ i;
        } else {
            y = y ^ i;
        }
    }

    // Check which one is repeating
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Repeating element = " << x << endl;
        cout << "Missing element = " << y << endl;
    } else {
        cout << "Repeating element = " << y << endl;
        cout << "Missing element = " << x << endl;
    }

    return 0;
}