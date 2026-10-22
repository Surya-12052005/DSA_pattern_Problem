/*Problem 6. Flip the nth Bit

Problem Statement:
Given an integer x and a bit position n, flip the nth bit.

If it is 0, make it 1.
If it is 1, make it 0.
Formula
x = x ^ (1 << n);*/

#include <iostream>
using namespace std;

int flipBit(int x, int n)
{
    int mask = 1 << n;

    return x ^ mask;
}

int main()
{
    int x = 5;
    int n = 1;

    cout << flipBit(x, n);

    return 0;
}