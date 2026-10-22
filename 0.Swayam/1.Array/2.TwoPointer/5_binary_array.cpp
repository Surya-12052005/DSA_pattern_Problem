/*
    Problem   : Move All Zeros to the Front (Binary Array)
    Difficulty: Easy
    Topic     : Two Pointers

    Given a binary array (containing only 0s and 1s),
    move all 0s to the front and all 1s to the back.

    Time Complexity : O(N)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

void moveZeroToFront(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        // Left side is already 0
        if (arr[left] == 0)
        {
            left++;
        }

        // Right side is already 1
        else if (arr[right] == 1)
        {
            right--;
        }

        // Left is 1 and Right is 0
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

    cout << "Enter binary array (0 and 1 only):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    moveZeroToFront(arr, n);

    cout << "\nArray after moving all zeros to the front:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}