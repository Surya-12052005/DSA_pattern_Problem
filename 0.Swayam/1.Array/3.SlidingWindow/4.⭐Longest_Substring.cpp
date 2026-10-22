/*
LeetCode 3: Longest Substring Without Repeating Characters
1. Question
Given a string s, find the length of the longest substring that contains no duplicate characters.
A substring must contain consecutive characters.


Example 1
Input:  s = "abcabcbb"
Output: 3
Explanation: "abc" is the longest substring without repeating characters.


Example 2
Input:  s = "bbbbb"
Output: 1
Explanation: "b" is the longest substring without repeating characters.*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> last(256, -1);        //This line creates an integer vector of 256 elements, and initializes every element to -1
                                     //256 provides slots for all possible byte values, including standard ASCII characters.
    int left = 0;
    int ans = 0;

    for (int right = 0; right < s.size(); right++) {
        char ch = s[right];            // 'a'

        if (last[ch] >= left) {       // Initially, last['a'] = -1 and left = 0.  so  -1>=0   ->  false;
            left = last[ch] + 1;       
        }

        last[ch] = right;            //last[a] = 0  ,  Now, a was last seen at index 0.

        ans = max(ans, right - left + 1);   // max(0, 0-0+1)
    }

    return ans;        
}   

int main() {
    string s;
    cin >> s;

    cout << lengthOfLongestSubstring(s) << endl;

    return 0;
}


/*
for (int right = 0; right < s.size(); right++) {
            char ch = s[right];

            if (last[ch] >= left) {
                left = last[ch] + 1;
            }

            last[ch] = right;

            ans = max(ans, right - left + 1);
        }
            */


/*
vector<int> last(256, -1);

This line creates an integer vector of 256 elements, and initializes every element to -1.   
1. Understand each part
- vector<int> → creates a vector of integers.
- last → the vector's name.
- 256 → the number of elements.
- -1 → the initial value of every element.


Imagine it like this:
Index:  0   1   2   3   4  ...  255
Value: -1  -1  -1  -1  -1  ...   -1



2. Why use 256 and -1?
In LeetCode 3, we need to remember the last index where each character appeared.
- 256 provides slots for all possible byte values, including standard ASCII characters.
- -1 means the character has not appeared yet.



*/



/*

1. Understand the string and its indexes
Index	0	1	2	3	4	5	6	7
Character	a	b	c	a	b	c	b	b
Initially:
- left = 0
- ans = 0
- Every last[ch] = -1, meaning no character has appeared yet.
2. Complete iteration-by-iteration dry run
Iteration 1: right = 0
Character = 'a'
1. last['a'] = -1, left = 0
2. Duplicate check: \(-1 \geq 0 \Rightarrow false\)
3. Update: last['a'] = 0
4. Calculate: \(ans = \max(0,0-0+1)=1\)
Window: "a" | ans = 1

Iteration 2: right = 1
Character = 'b'
1. last['b'] = -1, left = 0
2. Duplicate check: \(-1 \geq 0 \Rightarrow false\)
3. Update: last['b'] = 1
4. Calculate: \(ans = \max(1,1-0+1)=2\)
Window: "ab" | ans = 2

Iteration 3: right = 2
Character = 'c'
1. last['c'] = -1, left = 0
2. Duplicate check: \(-1 \geq 0 \Rightarrow false\)
3. Update: last['c'] = 2
4. Calculate: \(ans = \max(2,2-0+1)=3\)
Window: "abc" | ans = 3

Iteration 4: right = 3
Character = 'a'
1. last['a'] = 0, left = 0
2. Duplicate check: \(0 \geq 0 \Rightarrow true\)
3. Move left: left = 0 + 1 = 1
4. Update: last['a'] = 3
5. Calculate: \(ans = \max(3,3-1+1)=3\)
Window: "bca" | ans = 3

Iteration 5: right = 4
Character = 'b'
1. last['b'] = 1, left = 1
2. Duplicate check: \(1 \geq 1 \Rightarrow true\)
3. Move left: left = 1 + 1 = 2
4. Update: last['b'] = 4
5. Calculate: \(ans = \max(3,4-2+1)=3\)
Window: "cab" | ans = 3

Iteration 6: right = 5
Character = 'c'
1. last['c'] = 2, left = 2
2. Duplicate check: \(2 \geq 2 \Rightarrow true\)
3. Move left: left = 2 + 1 = 3
4. Update: last['c'] = 5
5. Calculate: \(ans = \max(3,5-3+1)=3\)
Window: "abc" | ans = 3

Iteration 7: right = 6
Character = 'b'
1. last['b'] = 4, left = 3
2. Duplicate check: \(4 \geq 3 \Rightarrow true\)
3. Move left: left = 4 + 1 = 5
4. Update: last['b'] = 6
5. Calculate: \(ans = \max(3,6-5+1)=3\)
Window: "cb" | ans = 3

Iteration 8: right = 7
Character = 'b'
1. last['b'] = 6, left = 5
2. Duplicate check: \(6 \geq 5 \Rightarrow true\)
3. Move left: left = 6 + 1 = 7
4. Update: last['b'] = 7
5. Calculate: \(ans = \max(3,7-7+1)=3\)
Window: "b" | ans = 3

*/