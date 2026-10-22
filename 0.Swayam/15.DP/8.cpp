
/*
6.cpp — Blocked Road: Number of Ways + Minimum Time

Your last question is a combination of the previous concepts.

Question

A person starts at (0,0) and wants to reach (m-1,n-1). Some cells are blocked. The person can move only Right and Down.

Find:

1.Number of possible ways
2.Handle blocked cells
3.Minimum time to reach the destination

Diagram

Using the blocked grid from your screenshot:

              j=0    j=1    j=2    j=3
           ┌──────┬──────┬──────┬──────┐
i=0        │  S   │      │  X   │      │
           ├──────┼──────┼──────┼──────┤
i=1        │  X   │      │      │      │
           ├──────┼──────┼──────┼──────┤
i=2        │      │  X   │      │  X   │
           ├──────┼──────┼──────┼──────┤
i=3        │      │      │      │  X   │
           └──────┴──────┴──────┴──────┘

S = Start
X = Blocked
E = End = (3,3)


E = X

so the destination is blocked.

Therefore:

Number of ways = 0
Minimum time   = -1

But we should write the code generally, so it works even when the destination is not blocked.*/


#include <iostream>
using namespace std;

int grid[4][4] =
{
    {0, 0, 1, 0},
    {1, 0, 0, 0},
    {0, 1, 0, 1},
    {0, 0, 0, 1}
};

// Find number of ways
int numOfWays(int i, int j)
{
    // Outside grid
    if (i >= 4 || j >= 4)
        return 0;

    // Blocked cell
    if (grid[i][j] == 1)
        return 0;

    // Reached destination
    if (i == 3 && j == 3)
        return 1;

    int right = numOfWays(i, j + 1);
    int down = numOfWays(i + 1, j);

    return right + down;
}

// Find minimum time
int minTime(int i, int j)
{
    // Outside grid
    if (i >= 4 || j >= 4)
        return 1000000;

    // Blocked cell
    if (grid[i][j] == 1)
        return 1000000;

    // Reached destination
    if (i == 3 && j == 3)
        return 0;

    int right = minTime(i, j + 1);
    int down = minTime(i + 1, j);

    return 1 + min(right, down);
}

int main()
{
    int ways = numOfWays(0, 0);

    int time = minTime(0, 0);

    cout << "Number of ways = " << ways << endl;

    if (time == 1000000)
        cout << "Minimum time = No path";
    else
        cout << "Minimum time = " << time;

    return 0;
}

/*a person stand at start position and want to reach end position 
given there are some blockage in the road , 

1.find the numOfWays
2.blockage road.
3. min time.
[ ][ ][*][ ]
[*][ ][ ][ ]
[ ][*][ ][*]
[ ][ ][ ][ ]*/