/*Problem 8. Count Number of Set Bits

Problem Statement:
Given an integer x, find the number of set bits (1s) in its binary representation.

Example
x = 13

Binary representation:

1101

Number of 1s = 3*/

#include <iostream>
using namespace std;

int countSetBits(int x)
{
    int count = 0;

    while(x > 0)
    {
        if(x & 1)
            count++;

        x = x >> 1;
    }

    return count;
}

int main()
{
    int x = 13;

    cout << "Number of set bits = "
         << countSetBits(x);

    return 0;
}

