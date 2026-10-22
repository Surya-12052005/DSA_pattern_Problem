//givn an array  , find the max sum of array ,suh that no two elements ar adjacent 
// {5,3,3,4,2,9}
/*write the code using cache array*/

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& arr, int i, vector<int>& cache)
{
    // Base case
    if (i >= arr.size())
        return 0;

    // Already calculated
    if (cache[i] != -1)
        return cache[i];

    // Take current element
    int take = arr[i] + solve(arr, i + 2, cache);

    // Don't take current element
    int notTake = solve(arr, i + 1, cache);

    // Store answer
    cache[i] = max(take, notTake);

    return cache[i];
}

int main()
{
    vector<int> arr = {5, 3, 3, 4, 2, 9};

    vector<int> cache(arr.size(), -1);

    cout << "Maximum sum = " << solve(arr, 0, cache);

    return 0;
}


