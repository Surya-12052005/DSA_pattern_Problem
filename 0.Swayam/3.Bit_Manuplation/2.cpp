/*
Write a C++ program to convert a binary number, given as a string, into its decimal equivalent.

Create a function `convert2Decimal(string n)` outside the `main()` function.

**Approach:**
1. Traverse the binary string from right to left.
2. Initialize `p2 = 1` and `num = 0`.
3. If the current digit is `'1'`, add `p2` to `num`.
4. Multiply `p2` by 2 in each iteration.
5. Return the decimal number.

**Example**

Input: `1101`

Output: `13`
*/


#include <iostream>
#include <string>
using namespace std;

// Function to convert binary to decimal
int convert2Decimal(string n) {
    int len = n.length();
    int p2 = 1;    //p2 reffered to as power of two.
    int num = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (n[i] == '1') {
            num = num + p2;
        }

        p2 = p2 * 2;
    }

    return num;
}

// Main function
int main() {
    string n;

    cout << "Enter a binary number: ";
    cin >> n;

    cout << "Decimal number: " << convert2Decimal(n) << endl;

    return 0;
}

/*
4. Dry run: 1101
Digit	Power of 2 (p2)	num
1 (rightmost)	1	1
0	2	1
1	4	5
1 (leftmost)	8	13
So,
\[
1101_2 = 1(8)+1(4)+0(2)+1(1)=13
\]

Memory trick: Binary to decimal = traverse right to left, start with p2 = 1, add p2 only when the digit is 1, then double p2 every time.*/