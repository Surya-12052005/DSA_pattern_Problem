/*Problem 1. Set the nth Bit

Problem Statement:
Given an integer x and a bit position n, set the nth bit of x to 1.

Formula
x = x | (1 << n);*/

#include <iostream>
using namespace std;

int setBit(int x, int n)
{
    int mask = 1 << n;

    return x | mask;
}

int main()
{
    int x = 5;
    int n = 1;

    cout << setBit(x, n);

    return 0;
}
