/*Problem Statement : leetcode 2149.

You are given an array nums of n integers. Rearrange the elements according to the following three conditions:

1.Alternating signs: Every positive number must be followed by a negative number, and every negative number must be followed by a positive number.

2.Starting position: The first element of the rearranged array must be positive.

3.Relative order: The positive numbers must maintain their original relative order, and the negative numbers must also maintain their original relative order.*/



#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {     
    int n = nums.size();

    vector<int> ans(n);
    int P = 0;
    int N = 1;

    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            ans[P] = nums[i];
            P += 2;
        }
        else {
            ans[N] = nums[i];
            N += 2;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = rearrangeArray(nums);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
