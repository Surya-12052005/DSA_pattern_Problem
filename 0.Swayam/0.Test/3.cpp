//givn an array  , find the max sum of array ,such that no two elements are adjacent. using DP.
// {5,3,3,4,2,9}

#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int>& arr) {

    int n = arr.size();

    if (n == 0)
        return 0;

    if (n == 1)
        return arr[0];

    vector<int> dp(n);

    // Maximum sum using only first element
    dp[0] = arr[0];

    // Maximum sum using first two elements
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {

        // Option 1: Do not take arr[i]
        // Option 2: Take arr[i] and add dp[i-2]
        dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
    }

    return dp[n - 1];
}

int main() {

    vector<int> arr = {5, 3, 3, 4, 2, 9};

    cout << "Maximum Sum = " << maxSum(arr);

    return 0;
}