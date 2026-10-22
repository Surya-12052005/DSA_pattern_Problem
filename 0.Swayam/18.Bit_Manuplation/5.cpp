/*Problem 7. Get the nth Bit

Problem Statement:
Given an integer x and a bit position n, determine whether the nth bit is 0 or 1.

Formula
x & (1 << n)*/

#include <iostream>
using namespace std;

int getBit(int x, int n)
{
    int mask = 1 << n;

    if((x & mask) == 0)
        return 0;
    else
        return 1;
}

int main()
{
    int x = 5;
    int n = 2;

    cout << getBit(x, n);

    return 0;
}