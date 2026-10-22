
/*
Question: Swap Two Numbers Without a Third Variable
Problem statement: Given two integers a and b, swap their values without using a third or temporary variable.
Example 1
Input:
a = 5
b = 10

Output:
a = 10
b = 5*/

#include <iostream>
using namespace std;

void swapNumbers(int &a, int &b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {
    int a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    swapNumbers(a, b);

    cout << "After swapping:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}

/*
Dry run
Suppose a = 5 and b = 10.
Step	Operation	a	b
Initial	—	5	10
1	a = a ^ b	15	10
2	b = a ^ b	15	5
3	a = a ^ b	10	5
Final values: a = 10, b = 5.
*/
