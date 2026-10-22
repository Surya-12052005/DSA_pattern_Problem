/*You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/
#include <iostream>
using namespace std;

int climbStairs(int n)
{
    // Base cases
    if(n==0 || n==1 || n==2)          // or if(n <= 2){ return n; } 
    return n;

    // 1 step or 2 steps
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main()
{
    int n;

    cout << "Enter number of stairs: ";
    cin >> n;

    int ans = climbStairs(n);

    cout << "Number of ways = " << ans << endl;

    return 0;
}