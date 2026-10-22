/*
Problem statement:
Given a positive integer n, set its rightmost unset bit (the rightmost 0 in its binary representation) to 1. Return the resulting integer.
If all bits are already set to 1, leave the number unchanged.

Examples
Example 1
Input:  n = 10
Binary: 1010
Output: 11
Binary: 1011*/


#include <iostream>
using namespace std;

// Function to set the rightmost unset bit
int setRightmostUnsetBit(int n) {
    return n | (n + 1);  //You write 10 in decimal, but the computer represents it in binary:
}                        //You do not need to convert it manually.

int main() {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    int result = setRightmostUnsetBit(n);

    cout << "Result: " << result << endl;

    return 0;
}
