/*Remove Duplicates from Sorted Array
Problem Statement

Given a sorted array of integers, remove the duplicate elements in-place so that each element appears only once.

Return the number of unique elements in the array.

The first k positions of the array, where k is the number of unique elements, should contain the unique elements in sorted order.

You should solve the problem using the Two Pointer technique.

Input

The program should take:

An integer n, representing the size of the array.
n integers representing the sorted array.
Output

Print:

The number of unique elements k.
The array containing the unique elements.
Example
Input
5
1 1 2 2 3
Output
3
1 2 3
Another Example
Input
10
0 0 1 1 1 2 2 3 3 4
Output
5
0 1 2 3 4
Constraints
1 <= n <= 30000
-100 <= arr[i] <= 100*/



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        if (n == 0) {
            return 0;
        }

        int i = 0;

        for (int j = 1; j < n; j++) {

            // If we find a new unique element
            if (nums[i] != nums[j]) {

                i++;

                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};

int main() {

    vector<int> nums = {1, 1, 2, 2, 3};

    Solution obj;

    int k = obj.removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl;

    cout << "Array after removing duplicates: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}