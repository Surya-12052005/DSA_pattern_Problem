/*
Question: Number of Substrings Containing All Three Characters

Input: abcabc
Output: 10
Approach: Last Seen Index + Counting
*/

#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int last[3] = {-1, -1, -1};
    int ans = 0;

    for (int i = 0; i < s.size(); i++) {

        // Update the last seen index
        last[s[i] - 'a'] = i;

        // Count valid substrings ending at index i
        ans += min(last[0], min(last[1], last[2])) + 1;
    }

    return ans;
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Number of valid substrings: "
         << numberOfSubstrings(s) << endl;

    return 0;
}
    
