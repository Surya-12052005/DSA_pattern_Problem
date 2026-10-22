/* given a list of activity , each activity take a day to complete it ,, each activity has a deadline , each activity is now associated with a list of profit , find the max profit a person can achieve.

activity   deadline    profit
A1            2           10
A2            3           18
A3            7            2 
A4            3           15
A5            3            4
A6           6             1
A7            2            12
*/


#include <iostream>
#include <algorithm>
using namespace std;

void jobSequencing(int deadline[], int profit[], int n)
{
    // Sort jobs according to profit
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (profit[i] < profit[j])
            {
                swap(profit[i], profit[j]);
                swap(deadline[i], deadline[j]);
            }
        }
    }

    int slot[8] = {0};
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = deadline[i]; j >= 1; j--)
        {
            if (slot[j] == 0)
            {
                slot[j] = profit[i];
                total += profit[i];
                break;
            }
        }
    }

    cout << "Maximum Profit = " << total;                                           
}

int main()
{
    int deadline[] = {2, 3, 7, 3, 3, 6, 2};
    int profit[]   = {10, 18, 2, 15, 4, 1, 12};

    int n = 7;

    jobSequencing(deadline, profit, n);

    return 0;
}
















#include <iostream>
#include <algorithm>
using namespace std;

void jobSequencing(int deadline[], int profit[], int n)
{
    // Sort profit in decreasing order
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (profit[i] < profit[j])
            {
                swap(profit[i], profit[j]);
                swap(deadline[i], deadline[j]);
            }
        }
    }

    int slot[8] = {0};
    int total = 0;

    // Select jobs
    for (int i = 0; i < n; i++)
    {
        for (int j = deadline[i]; j >= 1; j--)
        {
            if (slot[j] == 0)
            {
                slot[j] = 1;
                total = total + profit[i];
                break;
            }
        }
    }

    cout << "Maximum Profit = " << total;
}

int main()
{
    int deadline[] = {2, 3, 7, 3, 3, 6, 2};
    int profit[] = {10, 18, 2, 15, 4, 1, 12};

    jobSequencing(deadline, profit, 7);

    return 0;
}