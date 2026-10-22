/* Problem: Print All Subsequences of an Array

Difficulty: Medium
Topic: Recursion / Backtracking

Problem Statement:

Given an array of N integers, print all possible subsequences of the array while maintaining the original order of elements.
A subsequence is formed by deleting zero or more elements from the array without changing the order of the remaining elements.
Print every possible subsequence, including the empty subsequence.

Example:
Input arr = [1, 2, 3]        

Output
{}
{1}
{2}
{3}
{1,2}
{1,3}
{2,3}
{1,2,3}

The order of printing may vary. */

#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to print all subsequences
    void printSubsequence(int arr[], int n, int index, int ss[], int len)
    {
        // Base case        //len tells us how many elements are currently stored in ss[].
        if (index == n)    //We crossed the array. so print whatever is inside ss.
        {
            cout << "{ ";

            for (int i = 0; i < len; i++)     
            {
                cout << ss[i] << " ";
            }

            cout << "}" << endl;
            return;
        }

        // Include current element
        ss[len] = arr[index];
        printSubsequence(arr, n, index + 1, ss, len + 1);

        // Exclude current element
        printSubsequence(arr, n, index + 1, ss, len);
    }
};

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ss[n];   // Stores current subsequence

    Solution obj;
    obj.printSubsequence(arr, n, 0, ss, 0);

    return 0;
}