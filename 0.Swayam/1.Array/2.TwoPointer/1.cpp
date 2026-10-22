/*
    Problem   : Move Odd Numbers to the Front
    Difficulty: Easy
    Topic     : Two Pointers

    Time Complexity : O(N)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

void moveOddToFront(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        if (arr[left] % 2 != 0)
        {
            left++;
        }
        else if (arr[right] % 2 == 0)
        {
            right--;
        }
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
    cout << "Enter size of array \n";
    int n;
    
    cin >> n;

    int arr[n];

    cout << "Enter array elements \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call the function directly
    moveOddToFront(arr, n);

    cout << "Array after moving odd numbers to the front:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";     
    }

    return 0;
}