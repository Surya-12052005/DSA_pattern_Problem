/*Q. Coin Change Problem using Greedy Approach
Given an amount N and the denominations
{1, 2, 5, 10, 20, 50, 100, 200, 500}, find the minimum number of currency notes required to make the amount N using the Greedy Approach.

At every step, select the largest possible denomination and continue until the amount becomes 0.*/

#include <iostream>
using namespace std;

// Function to find minimum number of currency notes
int minCurNotes(int n)
{
    int den[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};

    int cnt = 0;

    // Start from the largest denomination
    int size = sizeof(den) / sizeof(den[0]);

    for (int i = size - 1; i >= 0; i--)
    {
        if (n >= den[i])
        {
            cnt += n / den[i];
            n = n % den[i];
        }
    }

    return cnt;
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