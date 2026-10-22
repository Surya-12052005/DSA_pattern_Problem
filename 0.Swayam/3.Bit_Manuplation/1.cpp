/***Question: Decimal to Binary Conversion**

Write a C++ program to convert a given decimal integer into its binary representation using the following approach:

1. Create a function `convert2Binary(int n)` outside the `main()` function.
2. Use a `while` loop and the modulo operator (`% 2`) to find the binary digits.
3. Divide the number by 2 in each iteration.
4. Reverse the resulting string to obtain the correct binary representation.
5. Take input from the user in `main()` and display the binary result.

**Example:**

Input:
```text
13
```

Output:
```text
1101
```*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to convert decimal to binary
string convert2Binary(int n) {
    if (n == 0) {
        return "0";
    }

    string res = "";

    while (n != 0) {
        if (n % 2 == 1) {
            res += '1';
        } else {
            res += '0';
        }

        n = n / 2;
    }

    reverse(res.begin(), res.end());

    return res;
}

// Main function
int main() {
    int n;

    cout << "Enter a decimal number: ";
    cin >> n;

    cout << "Binary representation: "
         << convert2Binary(n) << endl;

    return 0;
}
