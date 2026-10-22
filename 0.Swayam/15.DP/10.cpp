/*Question:
Given a plot of size 2 × n meters and tiles of size 2 × 1 meters, find the number of different ways to completely cover the plot using these tiles.

Use recursion to solve the problem.*/


#include <iostream>
using namespace std;

int numOfWays(int n)
{
    // Base cases
    if(n == 0 || n == 1)
        return 1;

    // 1 vertical tile OR 2 horizontal tiles
    return numOfWays(n - 1) + numOfWays(n - 2);
}

int main()
{
    int n;

    cout << "Enter length of plot: ";
    cin >> n;

    cout << "Number of ways = " << numOfWays(n) << endl;

    return 0;
}
