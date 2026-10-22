
/*LeetCode 169 — Majority Element
Problem Statement

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than n / 2 times in the array. You may assume that the majority element always exists.

Example 1

Input:

nums = [3,2,3]

Output:

3

Explanation:

The element 3 appears 2 times out of 3 elements, which is more than 3 / 2.*/

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums){
    int candidate=0;
    int count=0;
    int n=nums.size();

    for(int i=0;i<n;i++){
        if(count==0){
            candidate=nums[i];
        }
        if(nums[i]==candidate)
        count++;
        else
        count--;
    }
    cout<< candidate;

}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    majorityElement(nums);

}

/*Use Boyer–Moore Voting Algorithm when a problem asks you to find the majority element in an array.

When should you apply it?

Look for these clues in a problem statement:

1.Find an element that appears more than n/2 times.
2.Find the majority element in an array.
3.Solve the problem in O(n) time and O(1) extra space.

Example
nums = [2, 2, 1, 1, 1, 2, 2];

Here, n = 7, so a majority element must appear more than 7/2, meaning at least 4 times.

2 appears 4 times.
1 appears 3 times.*/

