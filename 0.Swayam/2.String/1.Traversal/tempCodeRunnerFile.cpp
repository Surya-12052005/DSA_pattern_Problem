/*
Problem: Print All Substrings of a String

Question

Given a string s, print all possible non-empty substrings of the string in their original order.
A substring is a sequence of consecutive characters from a string.

Input:
abc

Output:
a
ab
abc
b
bc
c

Constraints

1≤s.length()≤100

The string contains English letters.*/


#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    int n = s.size();

    cout << "All substrings are:" << endl;

    for (int i = 0; i < n; i++) {
        string ans = "";

        for (int j = i; j < n; j++) {
            ans += s[j];
            cout << ans << endl;
        }
    }

    return 0;
}