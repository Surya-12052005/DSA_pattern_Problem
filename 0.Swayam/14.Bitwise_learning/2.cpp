/*Q2. Find the Missing Number Using XOR
Proper Question

Given an unsorted array containing n distinct elements from the range 1 to n+1, one number is missing. Find the missing number using the XOR method.

Example
Array = [1, 2, 4, 5]

Numbers should be = 1, 2, 3, 4, 5

Missing number = 3
Concept

We XOR:

1 ^ 2 ^ 3 ^ 4 ^ 5

with all array elements:

1 ^ 2 ^ 4 ^ 5

The repeated numbers cancel, leaving:

3*/

#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 4, 5};

    int n = 4;
    int ans = 0;

    // XOR all numbers from 1 to n+1
    for (int i = 1; i <= n + 1; i++) {
        ans = ans ^ i;                      //ans = 1 ^ 2 ^ 3 ^ 4 ^ 5
    }

    // XOR all array elements
    for (int i = 0; i < n; i++) {
        ans = ans ^ a[i];                //ans = 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 1 ^ 2 ^ 4 ^ 5
    }

    cout << "Missing number = " << ans;  

    return 0;
}

/*Yes — this code solves the “Find the Missing Number” problem using XOR.

Problem

You are given an array containing numbers from 1 to n+1, but one number is missing.

Array = {1, 2, 4, 5}

Numbers should be:

1, 2, 3, 4, 5

So the missing number is:

3
Your Code Explained
1. Create the array
int a[] = {1, 2, 4, 5};

The array contains:

1  2  4  5

Number 3 is missing.

2. Store the array size
int n = 4;

There are 4 elements in the array.

Since one number is missing, the complete range contains:

1 to n+1

So:

1 to 5
3. Initialize ans
int ans = 0;

We start with 0 because:

0 ^ x = x
4. XOR all numbers from 1 to n+1
for (int i = 1; i <= n + 1; i++) {
    ans = ans ^ i;
}

Here:

n + 1 = 5

So the loop performs:

ans = 0 ^ 1 ^ 2 ^ 3 ^ 4 ^ 5

After this loop:

ans = 1 ^ 2 ^ 3 ^ 4 ^ 5
5. XOR all array elements
for (int i = 0; i < n; i++) {
    ans = ans ^ a[i];
}

The array contains:

1, 2, 4, 5

So now:

ans = 1 ^ 2 ^ 3 ^ 4 ^ 5
      ^ 1 ^ 2 ^ 4 ^ 5

Now the duplicate numbers cancel each other:

1 ^ 1 = 0
2 ^ 2 = 0
4 ^ 4 = 0
5 ^ 5 = 0

Therefore:

ans = 3*/