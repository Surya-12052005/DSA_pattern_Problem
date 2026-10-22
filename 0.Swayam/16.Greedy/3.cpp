/*Q. Coin Change Problem Using Recursion

Given an amount N and the following currency denominations:

{1, 2, 5, 10, 20, 50, 100, 200, 500}

Write a C++ program to find the minimum number of currency notes required to make the amount N using recursion.

At each step, consider each denomination and recursively find the minimum number of notes required for the remaining amount. Return the minimum among all possible choices.

Example:

For:

N = 93

Possible minimum combination:

50 + 20 + 20 + 2 + 1 = 93

Therefore:

Minimum number of notes = 5*/


#include <iostream>
#include <climits>
using namespace std;

// Recursive function
int minNotes(int amount, int notes[], int n)
{
    // Base case
    if (amount == 0)
        return 0;

    int ans = INT_MAX;

    // Try every denomination
    for (int i = 0; i < n; i++)
    {
        if (notes[i] <= amount)
        {
            int result = minNotes(amount - notes[i], notes, n);

            if (result != INT_MAX)
            {
                ans = min(ans, result + 1);
            }
        }
    }

    return ans;
}

int main()
{
    int N;

    int notes[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};

    cout << "Enter amount: ";
    cin >> N;

    int n = 9;

    int answer = minNotes(N, notes, n);

    cout << "Minimum number of notes = " << answer;

    return 0;
}

/*Q. Coin Change Problem using Recursion Approach
Given an amount N and the denominations
{1, 2, 5, 10, 20, 50, 100, 200, 500}, find the minimum number of currency notes required to make the amount N using the recurion Approach.

At every step, select the largest possible denomination and continue until the amount becomes 0.*/

