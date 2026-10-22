/*Problem: Print Truth Table for N Variables
Problem Statement

Given an integer N, print all possible combinations of 0 and 1 for N variables.
Each variable can have only two values:
0 (False)
1 (True)

Since each variable has 2 choices, the total number of combinations is:

2^N
Example 1
Input
N = 2
Output
0 0
0 1
1 0
1 1  */

#include <iostream>
using namespace std;

class Solution
{
public:
    void printTruthTable(int arr[], int n, int index)
    {
        // Base Case
        if (index == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            return;
        }

        // Put 0
        arr[index] = 0;
        printTruthTable(arr, n, index + 1);

        // Put 1
        arr[index] = 1;
        printTruthTable(arr, n, index + 1);
    }
};

int main()
{
    int n;

    cout << "Enter number of variables: ";
    cin >> n;

    int arr[n];

    Solution obj;
    obj.printTruthTable(arr, n, 0);

    return 0;
}