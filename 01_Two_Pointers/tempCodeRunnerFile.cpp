#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
    // Edge case: empty array
    if (n == 0) return 0;

    int slow = 0; // slow points to last unique element found so far

    // simple loop from index 1 to n-1
    for (int fast = 1; fast < n; fast++) {

        // if current element is different from the last unique one
        if (arr[fast] != arr[slow]) {
            slow = slow + 1;       // move slow one step forward
            arr[slow] = arr[fast]; // copy new unique value into that spot
        }
        // else: it's a duplicate, do nothing
    }

    // total unique elements = slow + 1
    return slow + 1;
}

int main() {
    int n;

    // Step 1: ask user for size of array
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100]; // fixed-size array (assuming n <= 100)

    // Step 2: ask user to enter elements (must be sorted!)
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: process
    int newLength = removeDuplicates(arr, n);

    // Step 4: show result
    cout << "New length: " << newLength << endl;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}