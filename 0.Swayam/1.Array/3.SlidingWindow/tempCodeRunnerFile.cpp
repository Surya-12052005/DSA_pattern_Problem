/*
LeetCode 904 — Fruit Into Baskets using Sliding Window in C++.
1. Problem statement
You are given an array fruits, where fruits[i] represents the type of fruit at position i.
You have 2 baskets, and each basket can hold only one type of fruit. Find the maximum number of fruits you can collect from a continuous section of the array containing at most 2 distinct types.
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