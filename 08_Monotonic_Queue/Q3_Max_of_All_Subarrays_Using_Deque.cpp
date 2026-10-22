/*
    Problem   : First Negative Number in Every Window of Size K
    Difficulty: Medium
    Topic     : Monotonic Queue (deque used as a sliding index buffer)

    Given an array and window size k, find the first negative number
    in every window of size k. If a window has no negative number,
    output 0 for that window.

    Example:
    Input : arr = [12,-1,-7,8,-15,30,16,28], k = 3
    Output: [-1,-1,-7,-15,-15,0,0]

    Approach:
    - Use a deque to store indices of negative numbers within current window.
    - Slide the window; remove indices out of range from front.
    - If arr[i] is negative, push its index.
    - The front of the deque (if any) gives the first negative number.

    Time Complexity : O(n)
    Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeInWindow(vector<int>& arr, int k) {
    deque<int> dq; // indices of negative numbers
    vector<int> result;

    for (int i = 0; i < (int)arr.size(); i++) {
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        if (arr[i] < 0) dq.push_back(i);
        if (i >= k - 1) result.push_back(dq.empty() ? 0 : arr[dq.front()]);
    }
    return result;
}

int main() {
    vector<int> arr = {12,-1,-7,8,-15,30,16,28};
    int k = 3;
    vector<int> res = firstNegativeInWindow(arr, k);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
