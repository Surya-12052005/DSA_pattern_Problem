/*
    Problem   : Equilibrium Index of an Array
    Difficulty: Easy
    Topic     : Prefix Sum

    Find an index such that the sum of elements at lower indices is
    equal to the sum of elements at higher indices (excluding the index itself).

    Example:
    Input : arr = [-7,1,5,2,-4,3,0]
    Output: 3   (leftSum = -7+1+5 = -1, rightSum = -4+3+0 = -1)

    Approach:
    - Compute total sum first.
    - Traverse the array maintaining leftSum.
    - rightSum = total - leftSum - arr[i].
    - If leftSum == rightSum, i is the equilibrium index.

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int equilibriumIndex(vector<int>& arr) {
    int total = 0;
    for (int x : arr) total += x;

    long long leftSum = 0;
    for (int i = 0; i < (int)arr.size(); i++) {
        long long rightSum = total - leftSum - arr[i];
        if (leftSum == rightSum) return i;
        leftSum += arr[i];
    }
    return -1;
}

int main() {
    vector<int> arr = {-7,1,5,2,-4,3,0};
    cout << "Equilibrium Index: " << equilibriumIndex(arr) << endl;
    return 0;
}
