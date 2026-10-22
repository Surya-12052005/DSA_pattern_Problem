/*
Problem: Character Value Lookup:leetcode 13

Problem Statement:
You are given a character representing a Roman numeral. Your task is to print its corresponding integer value using an unordered_map.

Use the following values:

I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

Input Format:
A single character representing a Roman numeral.

Output Format:
Print its corresponding integer value.

Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 3:
*/


#include <iostream>
#include <unordered_map>
using namespace std;


    int romanToInt(string s) {

        unordered_map<char, int> value = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
                  
            if(i + 1 < s.size() && value[s[i]] < value[s[i + 1]])   // Check if next element exists and is greater     
                ans = ans - value[s[i]];  // subtract
            else
                ans = ans + value[s[i]];  // add
        }

        return ans;
    }

/*

unordered_map<char, int> value = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

Let's break it down:

unordered_map → stores key-value pairs.

char → the key is a character, such as 'I' or 'V'.
int → the value is an integer, such as 1 or 5.
value → the name of the map.
{ 'I', 1 } → means the character 'I' has the value 1.


Q. How do you access a value?

cout << value['I'] << endl;
cout << value['V'] << endl;
cout << value['X'] << endl;

*/