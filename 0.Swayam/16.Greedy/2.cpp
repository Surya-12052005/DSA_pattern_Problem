/*Q. Coin Change Problem using Greedy and Recursion

Given an amount N and the following currency denominations:

{1, 2, 5, 10, 20, 50, 100, 200, 500}

Find the minimum number of currency notes required to return the change N.

Use the Greedy Approach with Recursion. At each step, select the largest possible denomination.*/

#include <iostream>
using namespace std;

// Available denominations
int den[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};

// Function to find minimum number of currency notes
int minCurNotes(int n)
{
    // Base case
    if (n == 0)
        return 0;

    // Find the largest denomination <= n
    for (int i = 8; i >= 0; i--)
    {
        if (n >= den[i])
        {
            int cnt = n / den[i];
            int rem = n % den[i];

            // Greedy choice + recursion
            return cnt + minCurNotes(rem);
        }
    }

    return 0;
}

int main()
{
    int N;

    cout << "Enter amount: ";
    cin >> N;

    cout << "Minimum number of notes required = "
         << minCurNotes(N);

    return 0;
}