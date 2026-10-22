//Problem Name: Chef Finds Minimum Bit Flips to Convert Number
#include <bits/stdc++.h>
using namespace std;

int calculateMinimumBitFlips(int initialNumber, int targetNumber) {
    int x = initialNumber ^ targetNumber;
    int count = 0;

    while (x > 0) {
        if (x % 2 == 1) {  
            count++;
        }
        x = x / 2;
    }

    return count;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int initialNumber, targetNumber;
        cin >> initialNumber >> targetNumber;

        cout << calculateMinimumBitFlips(initialNumber, targetNumber) << endl;
    }

    return 0;
}


/*
3. Dry-run table

initialNumber=01010(10)
targetNumber=10100(20)

int x = 10 ^ 20;
cout << x;  // Output: 30

how it work , " 10 ^ 20 = 30- chatgpt

Iteration	x	x % 2	Condition	count_after_check	x = x / 2
1	        30	  0     	False	  0	                    15
2	        15	  1	        True	  1	                    7
3        	7	  1	        True	  2	                    3
4	        3	  1     	True	  3	                    1
5	        1	  1     	True	  4	                    0
*/