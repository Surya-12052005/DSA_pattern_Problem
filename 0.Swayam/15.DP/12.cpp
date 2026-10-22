/*Minimum Cost to Reach the Destination

There are 4 stations numbered 0, 1, 2, 3.

A person starts at station 0 and wants to reach station 3.

The fare required to travel directly from one station to another is given by the following matrix:

          Destination
             0    1    2    3
          ┌────┬────┬────┬────┐
      0   │  0 │ 10 │ 45 │ 60 │
          ├────┼────┼────┼────┤
      1   │  - │  0 │ 25 │ 35 │
          ├────┼────┼────┼────┤
      2   │  - │  - │  0 │ 30 │
          ├────┼────┼────┼────┤
      3   │  - │  - │  - │  0 │
          └────┴────┴────┴────┘
             ↑
          Source

For example:

0 → 1 = 10
0 → 2 = 45
0 → 3 = 60

1 → 2 = 25
1 → 3 = 35

2 → 3 = 30

The person can travel through intermediate stations.

For example:

0 ───────────────→ 3
       cost = 60

or

0 ──10──→ 1 ──35──→ 3
          total = 45

or

0 ──10──→ 1 ──25──→ 2 ──30──→ 3
          total = 65
Task

Find the minimum cost to travel from station 0 to station 3 using recursion.
*/

#include <iostream>
using namespace std;

int fare[4][4] =
{
    {0, 10, 45, 60},
    {0,  0, 25, 35},
    {0,  0,  0, 30},
    {0,  0,  0,  0}
};

int minCost(int s, int d)
{
    // Base case
    if (s == d)
        return 0;

    int ans = 9999;

    // Try every possible next station
    for (int i = s + 1; i <= d; i++)
    {
        int cost = fare[s][i] + minCost(i, d);

        if (cost < ans)
            ans = cost;
    }

    return ans;
}

int main()
{
    int s = 0;
    int d = 3;

    cout << "Minimum cost = " << minCost(s, d);

    return 0;
}


//int minCost(int n)