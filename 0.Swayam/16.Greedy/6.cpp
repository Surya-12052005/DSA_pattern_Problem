/*Q. Activity Selection Problem Using Greedy Approach

Given a list of N activities. Each activity has a start time and an end time. A person can perform only one activity at a time.

An activity can be selected only if its start time is greater than or equal to the end time of the previously selected activity.

Write a C++ program using the Greedy Approach to find the maximum number of activities that a person can perform.

Given Data
Activity	Start Time	End Time
A1           	1        	3
A2          	2	        5
A3          	3        	4
A4          	4	        7
A5          	7	        10
A6           	8	        9
A7          	9	        11
A8          	9	        13
A9	            11         	12
A10	            12	        14
Greedy Rule

Always select the activity that has the earliest finishing time.

This leaves more time for the remaining activities.*/     


#include <iostream>
#include <algorithm>
using namespace std;

struct Activity
{
    int start;
    int end;
};

// Function to find maximum number of activities
int maxActivities(Activity a[], int n)
{
    // Sort activities according to ending time(incresing order)
    sort(a, a + n, [](Activity x, Activity y)
    {
        return x.end < y.end;
    });

    int count = 1;
    int lastEnd = a[0].end;

    // Select compatible activities
    for (int i = 1; i < n; i++)
    {
        if (a[i].start >= lastEnd)
        {
            count++;
            lastEnd = a[i].end;
        }
    }

    return count;
}

int main()
{
    Activity a[] =
    {
        {1, 3},
        {2, 5},
        {3, 4},
        {4, 7},
        {7, 10},
        {8, 9},
        {9, 11},
        {9, 13},
        {11, 12},
        {12, 14}
    };

    int n = 10;

    cout << "Maximum number of activities = "
         << maxActivities(a, n);

    return 0;
}