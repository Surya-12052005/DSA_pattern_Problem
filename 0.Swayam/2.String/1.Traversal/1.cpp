/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ans = strs[0];

    for (int i = 1; i < strs.size(); i++) {
        int j = 0;

        while (j < ans.size() && j < strs[i].size() && ans[j] == strs[i][j]) {
            j++;
        }

        ans = ans.substr(0, j);

        if (ans == "") {
            return "";
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<string> strs(n);

    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    cout << longestCommonPrefix(strs) << endl;

    return 0;
}


/*


1. Take the first string as ans
string ans = strs[0];

strs[0] is: flower

So:
ans = "flower"

Why?
We initially assume the first string is the answer.
Later, we compare it with the other strings and make it smaller if necessary.

2. Start comparing with other strings

for (int i = 1; i < strs.size(); i++)
We start from i = 1 because strs[0] is already stored in ans.

So we'll compare:
ans with strs[1]
ans with strs[2]
...

For our example:
i = 1 → "flow"
i = 2 → "flight"


3. Start character comparison

Inside the loop:
int j = 0;
j represents the character position we're checking.

For example:
flower
↑
j = 0


4 . Compare characters using while
while (j < ans.size() &&
       j < strs[i].size() &&
       ans[j] == strs[i][j])

This looks complicated, but it simply means:

Keep moving forward while both strings have characters and those characters are the same.

There are 3 conditions.

Condition 1
j < ans.size()                  ie, j<strs[0].size()  ->  j<6  (flower)

Make sure we haven't reached the end of ans.

Condition 2
j < strs[i].size()

Make sure we haven't reached the end of the current string.

Condition 3
ans[j] == strs[i][j]

Check whether the characters are equal.


5. Compare "flower" and "flow".

Initially:

ans     = flower
strs[i] = flow
j = 0
flower
↑

flow
↑
f == f

✅ Same

So:

j++;
j = 1
j = 1
flower
 ↑

flow
 ↑
l == l

✅ Same

j = 2
j = 2
flower
  ↑

flow
  ↑
o == o

✅ Same

j = 3
j = 3
flower
   ↑

flow
   ↑
w == w

✅ Same

j = 4
j = 4

Now "flow" has ended.

flow
0123

There is no index 4.

Therefore:

j < strs[i].size()

becomes:

4 < 4 → false

The while loop stops.



6. Keep only the common part

Now:

ans = ans.substr(0, j);    //ans = ans.substr(start, length);  

Currently:
ans = "flower"
j = 4

So:
ans = "flower".substr(0, 4);

means:
Take the first 4 characters.

flower
^^^^
flow

Now:

ans = "flow"


7. Compare with "flight"

The for loop continues:

i = 2

Now:

ans     = "flow"
strs[i] = "flight"

Again:

j = 0;

Compare:

flow
↑

flight
↑
j = 0
f == f

✅

j = 1

j = 1
l == l

✅

j = 2

j = 2
flow
  ↑

flight
  ↑

Now:

o != i

❌ Different!

So the while loop stops.




8. Again use substr

Now:

ans = "flow"
j = 2

Execute:

ans = ans.substr(0, j);

Therefore:

ans = "flow".substr(0, 2);

Take first 2 characters:

flow
^^
fl

Now:

ans = "fl"

*/
