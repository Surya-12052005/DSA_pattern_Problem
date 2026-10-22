/*
    Problem   : Move Numbers Less Than or Equal to 5 to the Front
    Difficulty: Easy
    Topic     : Two Pointers

    Given an integer array, move all numbers less than
    or equal to 5 to the front and the remaining numbers
    to the back.

    Time Complexity : O(N)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

void moveLessThanEqualToFive(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        // Left side is already <= 5
        if (arr[left] <= 5)
        {
            left++;
        }

        // Right side is already > 5
        else if (arr[right] > 5)
        {
            right--;
        }

        // Left is > 5 and Right is <= 5
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

    moveLessThanEqualToFive(arr, n);

    cout << "\nArray after moving numbers <= 5 to the front:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}