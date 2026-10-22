/*Q4. Reverse the Words in a String

Question:
Given a string containing multiple words separated by underscores _, reverse the order of the words.

Example:

Input:
IT_IS_HOT_OUTSIDE


Output:
OUTSIDE_HOT_IS_IT
Approach

First reverse the complete string, then reverse every individual word*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverseWords(string &str)
{
    // Reverse the complete string
    reverse(str.begin(), str.end());

    int start = 0;

 //   hello_world_cpp
 //   ↓
 //   olleh_dlrow_ppc

    for (int i = 0; i <= str.length(); i++)     
    {
        if (i == str.length() || str[i] == '_')
        {
            reverse(str.begin() + start, str.begin() + i);  
            start = i + 1;
        }
    }
}

int main()
{
    string str = "IT_IS_HOT_OUTSIDE";

    reverseWords(str);

    cout << "Output: " << str;

    return 0;
}