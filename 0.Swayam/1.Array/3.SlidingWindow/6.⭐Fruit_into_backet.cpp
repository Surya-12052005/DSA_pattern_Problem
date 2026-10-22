/*
LeetCode 904 — Fruit Into Baskets using Sliding Window in C++.
1. Problem statement
You are given an array fruits, where fruits[i] represents the type of fruit at position i.
You have 2 baskets, and each basket can hold only one type of fruit. 
Find the maximum number of fruits you can collect from a continuous section of the array containing at most 2 distinct types.
Example:
Input:  fruits = [1, 2, 1, 2, 3]
Output: 4

Explanation:
The longest valid subarray is [1, 2, 1, 2].
Length = 4*/

#include <bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> mp;

    int left = 0, ans = 0;

    for (int right = 0; right < fruits.size(); right++) {

        mp[fruits[right]]++;

        while (mp.size() > 2) {
            mp[fruits[left]]--;

            if (mp[fruits[left]] == 0) {
                mp.erase(fruits[left]);
            }

            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> fruits(n);

    cout << "Enter the fruit types: ";
    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }

    cout << "Maximum fruits collected: "
         << totalFruit(fruits) << endl;

    return 0;
}


/*
1. Input
n = 5
fruits = {1, 2, 1, 2, 3}


Your important variables:
int left = 0, ans = 0;
unordered_map<int, int> mp;


- left = starting index of the current window.
- right = ending index of the current window.
- mp = stores each fruit type and its frequency.
- ans = maximum valid window length found so far.




3. Complete dry run:

Iteration 1 — right = 0

mp[fruits[right]]++;
Since fruits[0] = 1, the map stores fruit type 1

Variable     	Value
left	        0
right	        0
fruits[right]	1
mp	            {1: 1}
mp.size()   	1

Check the condition:
while (mp.size() > 2)

(1 > 2) is false, so the while loop is skipped.


Now calculate:
ans = max(ans, right - left + 1);
     = max(0, 0 - 0 + 1);
     = max(0, 1);
     = 1;

Result: ans = 1
Add fruits[1] = 2.





Iteration 2 — right = 1

mp[fruits[right]]++;
Since fruits[1] = 2, the map stores fruit type 2

Variable     	Value
left	        0
right	        1
fruits[right]	2
mp	            {1 : 1, 2 : 1}
mp.size()   	2

Check the condition:
while (mp.size() > 2)

(2 > 2) is false, so the while loop is skipped.


Now calculate:
ans = max(ans, right - left + 1);
     = max(1, 1 - 0 + 1);
     = max(0, 2);
     = 2;

Result: ans = 2
Current window: [1, 2]







Iteration 3 — right = 2

mp[fruits[right]]++;
Since fruits[2] = 1, the map stores fruit type 1

Variable     	Value
left	        0
right	        2
fruits[right]	1
mp	            {1 : 2, 2 : 1}
mp.size()   	2

Check the condition:
while (mp.size() > 2)

(2 > 2) is false, so the while loop is skipped.


Now calculate:
ans = max(ans, right - left + 1);
     = max(2, 2 - 0 + 1);
     = max(0, 3);
     = 3;

Result: ans = 3
Current window: [1, 2, 1]







Iteration 4 — right = 3

mp[fruits[right]]++;
Since fruits[3] = 2, the map stores fruit type 2

Variable     	Value
left	        0
right	        3
fruits[right]	2
mp	            {1 : 2, 2 : 2}
mp.size()   	2

Check the condition:
while (mp.size() > 2)

(2 > 2) is false, so the while loop is skipped.


Now calculate:
ans = max(ans, right - left + 1);
     = max(3, 3 - 0 + 1);
     = max(0, 4);
     = 4;

Result: ans = 4
Current window: [1, 2, 1, 2]






Iteration 5 — right = 4

mp[fruits[right]]++;
Since fruits[4] = 3, the map stores fruit type 3

Variable     	Value
left	        0
right	        4
fruits[right]	3
mp	            {1 : 2, 2 : 2, 3 :1}
mp.size()   	3

Check the condition:
while (mp.size() > 2)

Since (3 > 2) is true, we must shrink the window.
While loop — removal 1

Execute:
mp[fruits[left]]--;

Currently, left = 0, so fruits[left] = fruits[0] = 1.
The frequency of fruit 1 decreases from 2 to 1.

Before: {1: 2, 2: 2, 3: 1}
After:  {1: 1, 2: 2, 3: 1}

Check:
if (mp[fruits[left]] == 0)

Is the frequency of 1 equal to zero?
(1 = 0) is false. Do not erase it.

Now:
left++;

left = 1.
The map still has 3 types, so the while condition is still true.





While loop — removal 2
Now left = 1.
mp[fruits[left]]--;


fruits[1] = 2, so decrease the frequency of fruit 2 from 2 to 1.
Before: {1: 1, 2: 2, 3: 1}
After:  {1: 1, 2: 1, 3: 1}

Check:
if (mp[fruits[left]] == 0)

Is the frequency of 2 zero?
(1 = 0) is false. Do not erase it.
Now:
left++;
left = 2.
The map still has 3 types, so the while condition is still true.




While loop — removal 3
Now left = 2.
mp[fruits[left]]--;

fruits[2] = 1, so decrease the frequency of fruit 1 from 1 to 0.
Before: {1: 1, 2: 1, 3: 1}
After:  {1: 0, 2: 1, 3: 1}

Now check:
if (mp[fruits[left]] == 0)


(0 = 0) is true.
Execute:
mp.erase(fruits[left]);

Remove fruit type 1 completely from the map.
Map = {2: 1, 3: 1}
Then:
left++;
left = 3.
Now mp.size() = 2, so:
while (mp.size() > 2)

(2 > 2) is false. The while loop ends.


ans = max(ans, right - left + 1);
     = max(4, 4 - 3 + 1);
     = max(4, 2);
     = 4;

Result: ans = 4
Current window: [1, 2, 1, 2]

*/