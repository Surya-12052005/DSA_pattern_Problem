/*Problem: Reverse a String

Problem Statement:

You are given an array of characters s. Reverse the array in-place, meaning you must modify the original array without creating another array.

You must use O(1) extra space.

Input Format:

The first line contains an integer n, representing the number of characters.
The second line contains n characters separated by spaces.

Output Format:

Print the characters in reverse order.

Example 1:

Input:

5
h e l l o

Output:

o l l e h*/



#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    int i = 0;
    int j = s.size() - 1;

    while (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

int main() {
    int n;
    cin >> n;

    vector<char> s(n);

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    reverseString(s);

    for (int i = 0; i < n; i++) {
        cout << s[i];
    }

    cout << endl;

    return 0;
}
