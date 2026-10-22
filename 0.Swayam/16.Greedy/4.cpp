/* given a list of activity , each activity take a day to complete it ,, each activity has a deadline , find the max no of activity a person can complete.*/
/*Q. Activity Scheduling with Deadlines Using Greedy Approach

Given a list of N activities. Each activity requires exactly one day to complete, and each activity has a given deadline.

A person can perform at most one activity per day. An activity is considered completed successfully if it is performed on or before its deadline.

Write a C++ program using the Greedy Approach to find the maximum number of activities that can be completed.

Given Data
Activity	Deadline
A1            	2
A2          	3
A3          	7
A4            	3
A5          	3
A6	            2
A7	            2

Assumption: All activities have equal importance because no profit or priority is given.*/

#include <iostream>
#include <algorithm>
using namespace std;

// Function to find maximum number of activities
int maxActivities(int deadline[], int n)
{
    // Sort deadlines in increasing order
    sort(deadline, deadline + n);

    int count = 0;

    // Check each activity
    for (int i = 0; i < n; i++)
    {
        // Activity can be completed on day count + 1
        if (count + 1 <= deadline[i])
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int deadline[] = {2, 3, 7, 3, 3, 2, 2};

    int n = 7;

    cout << "Maximum number of activities = "
         << maxActivities(deadline, n);

    return 0;
}