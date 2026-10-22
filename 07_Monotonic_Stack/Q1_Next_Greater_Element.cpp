/*
    Problem   : Next Greater Element
    Difficulty: Easy
    Topic     : Monotonic Stack

    For each element in the array, find the next greater element to
    its right. If none exists, put -1.

    Example:
    Input : arr = [4,5,2,25]
    Output: [5,25,25,-1]

    Approach:
    - Traverse from right to left, maintain a decreasing stack.
    - Pop elements smaller than or equal to current from stack top.
    - Top of stack (if any) is the next greater element.
    - Push current element onto stack.

    Time Complexity : O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // stores values

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) st.pop();
        if (!st.empty()) result[i] = st.top();
        st.push(arr[i]);
    }
    return result;
}

int main() {
    vector<int> arr = {4,5,2,25};
    vector<int> res = nextGreaterElement(arr);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
