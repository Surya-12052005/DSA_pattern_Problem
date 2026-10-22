/*Q. Weighted Activity Selection Problem

Given a list of N activities. Each activity has:

Start time
End time
Profit

Each activity takes the time interval from its start time to its end time. A person can perform multiple activities, but two selected activities must not overlap.

The person earns the given profit if an activity is selected.

Write a C++ program to find the maximum total profit that a person can achieve by selecting a set of non-overlapping activities.

Given Data
Activity	Start	End	Profit
A1	1	3	50
A2	2	5	70
A3	3	4	20
A4	4	7	60
A5	7	10	30
A6	8	9	40
A7	9	11	80
A8	9	13	35
A9	11	12	90
A10	12	14	45
Objective

Find:

The activities that should be selected.
The maximum total profit.*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Activity
{
    char name[5];
    int start;
    int end;
    int profit;
};

// Function to find maximum profit
int maxProfit(Activity a[], int n)
{
    // Sort activities according to ending time
    sort(a, a + n, [](Activity x, Activity y)
    {
        return x.end < y.end;
    });

    int dp[20];

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        // Profit if we select current activity
        int include = a[i - 1].profit;

        // Find the last non-overlapping activity
        int j = i - 2;

        while (j >= 0 && a[j].end > a[i - 1].start)
        {
            j--;
        }

        if (j >= 0)
        {
            include = include + dp[j + 1];
        }

        // Maximum of including or excluding current activity
        dp[i] = max(dp[i - 1], include);
    }

    return dp[n];
}

int main()
{
    Activity a[] =
    {
        {"A1", 1, 3, 50},
        {"A2", 2, 5, 70},
        {"A3", 3, 4, 20},
        {"A4", 4, 7, 60},
        {"A5", 7, 10, 30},
        {"A6", 8, 9, 40},
        {"A7", 9, 11, 80},
        {"A8", 9, 13, 35},
        {"A9", 11, 12, 90},
        {"A10", 12, 14, 45}
    };

    int n = 10;

    cout << "Maximum Profit = " << maxProfit(a, n);

    return 0;
}