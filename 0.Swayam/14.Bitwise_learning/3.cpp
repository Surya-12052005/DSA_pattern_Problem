/*Q3. Find the Missing Number Using Sum
Proper Question

Given an unsorted array containing n distinct elements from 1 to n+1, with one number missing, find the missing number using the sum method.

Formula

The sum of numbers from 1 to n+1 is:

Sum = (n + 1) * (n + 2) / 2

Then:

Missing = Expected Sum - Array Sum
Example
Array = [1, 2, 4, 5]

Expected Sum = 1 + 2 + 3 + 4 + 5 = 15

Array Sum = 1 + 2 + 4 + 5 = 12

Missing = 15 - 12 = 3*/

#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 4, 5};

    int n = 4;

    int expectedSum = (n + 1) * (n + 2) / 2;

    int arraySum = 0;

    for (int i = 0; i < n; i++) {
        arraySum = arraySum + a[i];
    }

    int missing = expectedSum - arraySum;

    cout << "Missing number = " << missing;

    return 0;
}