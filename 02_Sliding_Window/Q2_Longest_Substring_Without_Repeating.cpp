/*
    Problem   : Longest Substring Without Repeating Characters
    Difficulty: Medium
    Topic     : Sliding Window

    Given a string s, find the length of the longest substring
    without repeating characters.

    Example:
    Input : s = "abcabcbb"
    Output: 3   ("abc")

    Approach:
    - Use a variable-size window [left, right] and a hash set/map
      storing the last index of each character.
    - If s[right] already exists in the window, move left just past
      its previous occurrence.
    - Track the max window length.

    Time Complexity : O(n)
    Space Complexity: O(min(n, charset size))
*/

#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> st;   // An unordered_set is a container that stores only unique values.
                                     // unordered_set → Data structure
    int left = 0;                   //<char> → It stores characters       
    int maxLen = 0;                 //st → Variable name

    // Move right pointer
    for (int right = 0; right < s.length(); right++)
    {
        // If current character is already present,
        // remove characters from the left
        while (st.find(s[right]) != st.end())
        {
            st.erase(s[left]);
            left++;
        }

        // Add current character
        st.insert(s[right]);

        // Calculate current window length
        int currentLen = right - left + 1;

        // Update maximum length
        if (currentLen > maxLen)
        {
            maxLen = currentLen;
        }
    }

    return maxLen;
}

int main()
{
    string s;

    cout << "Enter string: ";
    cin >> s;

    cout << "Longest substring length = "
         << lengthOfLongestSubstring(s);

    return 0;
}

/* 
unordered_map<char, int>
              ↑      ↑
             key   value
             
             
             */