/*Q1. Find the Element That Appears Once
Proper Question

Given an array in which every element appears an even number of times except one element, find the element that appears an odd number of times.

Concept: XOR

Important XOR properties:

a ^ a = 0
a ^ 0 = a

So, when we XOR all elements, the repeated elements cancel each other and only the unique element remains.

Example
Array = [2, 3, 4, 3, 2]

2 ^ 3 ^ 4 ^ 3 ^ 2 = 4*/

#include <iostream>
using namespace std;

int main() {
    int a[] = {2, 3, 4, 3, 2};

    int n = 5;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans = ans ^ a[i];
    }

    cout << "Element appearing once = " << ans;

    return 0;
}


/*Main Concept: XOR (^)

The important part of your solution is:

ans = ans ^ a[i];

XOR has three important properties:

1. Same numbers cancel each other
5 ^ 5 = 0
2. XOR with 0 gives the same number
0 ^ 5 = 5
3. Order does not matter
2 ^ 3 ^ 2 = 3

So, when every number occurs twice, the duplicate numbers cancel out and only the number occurring once remains.

Step-by-step execution

Your array is:

{2, 3, 4, 3, 2}

Initially:

ans = 0;

Now the loop runs.

Iteration 1
ans = 0 ^ 2;

Result:

ans = 2
Iteration 2
ans = 2 ^ 3;

Result:

ans = 1

Because:

2 = 010
3 = 011
---------
    001 = 1
Iteration 3
ans = 1 ^ 4;

Result:

ans = 5
Iteration 4
ans = 5 ^ 3;

Result:

ans = 6
Iteration 5
ans = 6 ^ 2;

Result:

ans = 4

Therefore:

Answer = 4*/