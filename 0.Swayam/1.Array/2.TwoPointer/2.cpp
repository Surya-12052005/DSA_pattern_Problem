/*
    Problem   : Move Negative Numbers to the Front
    Difficulty: Easy
    Topic     : Two Pointers

    Given an integer array, move all negative numbers
    to the front and all positive numbers to the back.

    Time Complexity : O(N)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

void moveNegativeToFront(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        // Left side is already negative
        if (arr[left] < 0)
        {
            left++;
        }

        // Right side is already positive (or zero)
        else if (arr[right] >= 0)
        {
            right--;
        }

        // Left is positive and Right is negative
        else
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    moveNegativeToFront(arr, n);

    cout << "\nArray after moving negative numbers to the front:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}