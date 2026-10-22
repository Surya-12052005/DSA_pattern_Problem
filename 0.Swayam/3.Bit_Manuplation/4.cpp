/*
Problem statement: Given a positive integer n, count the number of set bits (1s) in its binary representation and return the total count.
Example 1
- Input: n = 11
- Binary: 1011
- Output: 3
Example 2
- Input: n = 128
- Binary: 10000000
- Output: 1
*/


#include <iostream>
using namespace std;

int hammingWeight(int n) {
    int cnt = 0;

    while (n > 0) {
        cnt += n % 2;
        n /= 2;
    }

    return cnt;
}

int main() {
    int n;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }

    cout << "Number of 1 bits: " << hammingWeight(n) << endl;

    return 0;
}

/*
Step 1: Convert 11 to binary
\(11_{10} = 1011_2\)
Binary 1011 contains three 1 bits, so the expected answer is 3.

Step 2: Dry run, iteration by iteration
The key operations are:
- n % 2 → gets the last binary bit.
- cnt += n % 2 → adds that bit to the count.
- n /= 2 → removes the last binary bit through integer division.
Iteration	n before	n % 2	cnt after adding	n /= 2
1	       11 (1011)    	1	         1	           5
2          	5 (101)	        1	         2	           2
3       	2 (10)	        0	         2	           1
4        	1 (1)	        1	         3	           0
*/

