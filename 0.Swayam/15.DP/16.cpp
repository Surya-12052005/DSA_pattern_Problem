//givn an array  , find the max sum of array ,suh that no two elements ar adjacent 
// {5,3,3,4,2,9}
/*write the code using dynamic programing*/



#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {5, 3, 3, 4, 2, 9};

    int n = arr.size();

    vector<int> dp(n);

    dp[0] = arr[0];

    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
    }

    cout << "Maximum sum = " << dp[n - 1];

    return 0;
}

/*
Step 1: Create dp

Array size is 6.

arr =  5   3   3   4   2   9
dp  =  ?   ?   ?   ?   ?   ?
Step 2: dp[0]
dp[0] = arr[0];

So:

dp[0] = 5
dp = 5   ?   ?   ?   ?   ?

Meaning: with only 5, maximum sum is 5.

Step 3: dp[1]
dp[1] = max(arr[0], arr[1]);
max(5, 3) = 5
dp = 5   5   ?   ?   ?   ?

We choose 5 instead of 3.

Step 4: i = 2
dp[2] = max(dp[1], arr[2] + dp[0]);

Put values:

dp[2] = max(5, 3 + 5)
      = max(5, 8)
      = 8
dp = 5   5   8   ?   ?   ?

We take:

5 + 3 = 8
Step 5: i = 3
dp[3] = max(dp[2], arr[3] + dp[1]);
dp[3] = max(8, 4 + 5)
      = max(8, 9)
      = 9
dp = 5   5   8   9   ?   ?

We take:

5 + 4 = 9
Step 6: i = 4
dp[4] = max(dp[3], arr[4] + dp[2]);
dp[4] = max(9, 2 + 8)
      = max(9, 10)
      = 10
dp = 5   5   8   9   10   ?

We take:

3 + 5 + 2 = 10
Step 7: i = 5
dp[5] = max(dp[4], arr[5] + dp[3]);
dp[5] = max(10, 9 + 9)
      = max(10, 18)
      = 18
dp = 5   5   8   9   10   18
Final answer
cout << dp[n - 1];

Since:

n - 1 = 5

we get:

dp[5] = 18
Final DP table
Index:  0   1   2   3   4   5
arr:    5   3   3   4   2   9
dp:     5   5   8   9  10  18

Answer = 18*/