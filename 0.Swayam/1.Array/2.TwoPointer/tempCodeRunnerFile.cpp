#include <iostream>
using namespace std;

void OTF(int arr[], int n)
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
    int n;
    cout << "Enter n";
    cin >> n;

    int arr[n];

    cout << "enter arr elements";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    OTF(arr, n);

    cout << "array after sorting odd no to front";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}
