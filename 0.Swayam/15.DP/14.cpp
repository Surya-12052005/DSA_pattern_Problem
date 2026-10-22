//givn an array  , find the max sum of array ,suh that no two elements ar adjacent 
// {5,3,3,4,2,9}

#include <iostream>
#include <vector>
using namespace std;

int maxSum(vector<int>& arr, int i) {

    // Base case
    if (i >= arr.size())
        return 0;

    // Choice 1: Take current element
    // Then we cannot take the next element
    int take = arr[i] + maxSum(arr, i + 2);

    // Choice 2: Skip current element
    int skip = maxSum(arr, i + 1);

    // Return the better choice
    return max(take, skip);
}

int main() {

    vector<int> arr = {2, 7, 9, 3, 1};

    cout << "Maximum Sum = " << maxSum(arr, 0);

    return 0;
}