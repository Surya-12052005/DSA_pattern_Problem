/*Question:
Given a plot of size 2 × n meters and tiles of size 2 × 1 meters, find the number of different ways to completely cover the plot using these tiles.

DP + Recursion (Memoization)*/


#include <iostream>
#include <vector>
using namespace std;

int numOfWays(int n, vector<int>& dp)  
{
    // Base cases
    if(n == 0 || n == 1)
        return 1;

    // Already calculated
    if(dp[n] != -1)
        return dp[n];

    // 1 vertical tile OR 2 horizontal tiles
    dp[n] = numOfWays(n - 1, dp) + numOfWays(n - 2, dp);                        

    return dp[n];
}

int main()
{
    int n;

    cout << "Enter length of plot: ";
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << "Number of ways = " << numOfWays(n, dp) << endl;

    return 0;
}

/*we return 1 for n = 0 because there is exactly one way to completely cover a 2 × 0 plot: do nothing.

Think about n = 0

Our plot is:

2 × 0

There is no area to cover and therefore we don't need to place any tile.

So there is one valid arrangement:

[ nothing ]

We call this the empty arrangement.

Therefore:

numOfWays(0) = 1*/