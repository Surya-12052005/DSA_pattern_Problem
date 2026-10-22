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

/*

arr = [1, 2, 3]
n = 3

Your initial call is:

printSubsequence(arr, 3, 0, ss, 0);

Here:

index = which array element we are currently processing
len = how many elements are currently stored in ss
ss = temporary array containing the current subsequence

1. First call
index = 0
len = 0

Current element:
arr[0] = 1

Your code first includes 1:
ss[len] = arr[index];

So:

ss[0] = 1

Then:

printSubsequence(arr, n, index + 1, ss, len + 1);

becomes:

printSubsequence(arr, 3, 1, ss, 1)




2. index = 1, len = 1

Current element:

arr[1] = 2

Currently:

ss = {1}

Again, first include 2:

ss[1] = 2;

Now:

ss = {1, 2}

Call:

printSubsequence(arr, 3, 2, ss, 2);




3. index = 2, len = 2

Current element:

arr[2] = 3

Currently:

ss = {1, 2}

Again, include 3:

ss[2] = 3;

Now:

ss = {1, 2, 3}

Call:

printSubsequence(arr, 3, 3, ss, 3);





4. index = 3 → BASE CASE

Now:

if(index == n)

Since:

index = 3
n = 3

condition is true.

So:

cout << "{ ";

Then loop:

for(int i = 0; i < len; i++)

Here:

len = 3

So it prints:

1 2 3

Output:

{ 1 2 3 }

Then:

return;

We go back to the previous function call.





5. Backtracking: Exclude 3

We return to:

index = 2
len = 2
ss = {1,2}

The next statement after the include call is:

printSubsequence(arr, n, index + 1, ss, len);

Notice:

len

is still 2.

That means 3 is excluded.

Call:

printSubsequence(arr, 3, 3, ss, 2);

Base case:

index = 3
len = 2

Print:

{ 1 2 }

So far:

{ 1 2 3 }
{ 1 2 }
6. Back to index = 1

Now we return to:

index = 1
len = 1
ss = {1,2}

We already finished the include 2 branch.

Now execute:

printSubsequence(arr, n, index + 1, ss, len);

Here len remains 1.

Therefore, 2 is excluded.

Call:

index = 2
len = 1

Conceptually our subsequence is:

{1}
*/