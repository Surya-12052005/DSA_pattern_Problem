/*5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.*/







#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string longestPalindrome(string s) {
    string LongPal = "";

    for (int i = 0; i < s.size(); i++) {
        string ans = "";

        for (int j = i; j < s.size(); j++) {
            ans += s[j];

            string rev = ans;
            reverse(rev.begin(), rev.end());

            if (ans == rev && ans.size() > LongPal.size()) {
                LongPal = ans;
            }
        }
    }

    return LongPal;
}

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    cout << "Longest palindromic substring: "
         << longestPalindrome(s) << endl;

    return 0;
}