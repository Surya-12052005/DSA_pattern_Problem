/*
    Problem   : Daily Temperatures
    Difficulty: Medium
    Topic     : Monotonic Stack

    Given an array of daily temperatures, return an array such that
    answer[i] is the number of days to wait after day i to get a
    warmer temperature. If no such day exists, put 0.

    Example:
    Input : temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]

    Approach:
    - Maintain a stack of indices with decreasing temperatures.
    - For current day, pop all indices with smaller temperature and
      set their answer = current index - popped index.
    - Push current index onto the stack.

    Time Complexity : O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> st; // indices

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
            int idx = st.top(); st.pop();
            answer[idx] = i - idx;
        }
        st.push(i);
    }
    return answer;
}

int main() {
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> res = dailyTemperatures(temperatures);
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
