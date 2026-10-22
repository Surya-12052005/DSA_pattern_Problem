
/*
Problem: LeetCode 78 - Subsets

Problem Statement:
Given an array of unique integers, nums,
return all possible subsets (the power set).

Example:
Input:  nums = [1, 2, 3]
Output: [], [1], [2], [1, 2],
        [3], [1, 3], [2, 3], [1, 2, 3]

Approach: Bit Manipulation
Time Complexity: O(n * 2^n)
Space Complexity: O(n * 2^n) including output
*/


#include <iostream>
#include <vector> 
#include <cmath>         //pow(2, n)
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
                                                   //You must add: #include <cmath>
        for (int i = 0; i < (1<<n) ; i++){       // pow(2, n): This calculates 2^n  
            vector<int> temp;                     // pow(2, n)  ==  (1<<n)   == 8

            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    temp.push_back(nums[j]);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> ans = obj.subsets(nums);

    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

/*
1.variables:
*ans stores all the subsets.
*n = 3 because the array has three elements.
*temp stores one subset at a time.
*i represents which subset we are creating.
*j checks each element of the array.


2. How many subsets will we get?
Your code uses:
for (int i = 0; i < (1 << n); i++)
Here, n = 3.

1 << n means 2^n,  so 2^3=8.
Therefore, i runs from 0 to 7, creating 8 subsets.





3. The most important line in your code
if (i & (1 << j)) {
    temp.push_back(nums[j]);
}



*1 << j creates a bit mask.
*i & (1 << j) checks whether that bit is 1.
*If the bit is 1, add nums[j] to temp.
*If the bit is 0, skip that element.


For our array [1, 2, 3]:

j        nums[j]       1 << j(Binary mask: 2^j)            Bit checked   

0           1             001(1) ->2^0                     Rightmost bit
1           2             010(2) ->2^1                     Middle bit
2           3             100(4) _2^2                     Leftmost bit

These masks help check whether the corresponding bit in i is 1.
Remember: Bit 1 means include the element; bit 0 means exclude it.




*** Practical example
Suppose i = 5, whose binary representation is 101.
For nums = [1, 2, 3]:

j           1 << j            i & (1 << j)            Decision

0            001              101 & 001 = 001         Include 1
1            010              101 & 010 = 000         Skip 2
2            100              101 & 100 = 100         Include 3


*If the bit is 1, add nums[j] to temp.
*If the bit is 0, skip that element.

The resulting subset is [1, 3].



Easy trick to remember:
n → number of elements → total subsets.
j → index of an element → check its bit.






4. Complete dry run of your code
We will check every value of i.


best method:

Iteration 1:i=0
Binary representation:000
formula:(i&(1<<j))
                                            1
                                            |
        ↗   j=0 --- (000)&(2^0) --- (000)&(001) --- (000) --- skip nums[0] = 1   
      ↗
i=0 ↗→ → →  j=1 --- (000)&(2^1) --- (000)&(010) --- (000) --- skip nums[1] = 2
      ↘
        ↘   j=2 --- (000)&(2^2) --- (000)&(100) --- (000) --- skip nums[2] = 3
                                             |
                                             4

*If the bit is 1, add nums[j] to temp.
*If the bit is 0, skip that element
temp = []
ans = [[]]





method 2:

Iteration 1: i = 0
Binary representation: 000
All bits are 0, so no element is included.

j = 0 → skip 1
j = 1 → skip 2
j = 2 → skip 3
temp = []
ans = [[]]






Iteration 2:i=1
Binary representation:001
formula:(i&(1<<j))


        ↗   j=0 --- (001)&(2^0) --- (001)&(001) --- (001) --- 1 --- Include nums[0] = 1
      ↗
i=1 ↗→ → →  j=1 --- (001)&(2^1) --- (001)&(010) --- (000) --- 0  --- Skip nums[1] = 2
      ↘
        ↘   j=2 --- (001)&(2^2) --- (001)&(100) --- (001) --- 0  --- Skip nums[2] = 3 


*If the bit is 1, add nums[j] to temp.
*If the bit is 0, skip that element
temp = [1]
ans = [[], [1]]







Iteration 3:i=2
Binary representation:010
formula:(i&(1<<j))

                            1
                            |
        ↗   j=0 --- (010)&(2^0) --- (010)&(001) --- (000) --- 0 ---   skip nums[0]=1 
      ↗
i=2 ↗→ → →  j=1 --- (010)&(2^1) --- (010)&(010) --- (010) --- 2  ---  include nums[1]=2
      ↘
        ↘   j=2 --- (010)&(2^2) --- (010)&(100) --- (000) --- 0  ---  skip nums[2]=3
                            |
                            4
temp = [2]
ans = [[], [1], [2]]









Iteration 4:i=3
Binary representation:011
formula:(i&(1<<j))

                            1
                            |
        ↗   j=0 --- (011)&(2^0) --- (011)&(001) --- (001) --- 1 ---   include nums[0]=1 
      ↗
i=3 ↗→ → →  j=1 --- (011)&(2^1) --- (011)&(010) --- (010) --- 2  ---  include nums[1]=2
      ↘
        ↘   j=2 --- (011)&(2^2) --- (011)&(100) --- (000) --- 0  ---  skip nums[3]=3
                            |
                            4
temp = [1, 2]
ans = [[], [1], [2], [1, 2]]








Iteration 5:i=4
Binary representation:100
formula:(i&(1<<j))

                            1
                            |
        ↗   j=0 --- (100)&(2^0) --- (100)&(001) --- (000) --- 0 ---   skip nums[0]=1 
      ↗
i=4 ↗→ → →  j=1 --- (100)&(2^1) --- (100)&(010) --- (000) --- 0  ---  skip nums[1]=2
      ↘
        ↘   j=2 --- (100)&(2^2) --- (100)&(100) --- (100) --- 4  ---  include nums[2]=3
                            |
                            4

temp = [3]
ans = [[], [1], [2], [1, 2], [3]]








Iteration 5:i=4
Binary representation:100
formula:(i&(1<<j))

                            1
                            |
        ↗   j=0 --- (100)&(2^0) --- (100)&(001) --- (000) --- 0 ---   skip nums[0]=1 
      ↗
i=4 ↗→ → →  j=1 --- (100)&(2^1) --- (100)&(010) --- (000) --- 0  ---  skip nums[1]=2
      ↘
        ↘   j=2 --- (100)&(2^2) --- (100)&(100) --- (100) --- 4  ---  include nums[2]=3
                            |
                            4
                            
temp = [3]
ans = [[], [1], [2], [1, 2], [3]]













Iteration 6:i=5
Binary representation:101
formula:(i&(1<<j))

                            1
                            |
        ↗   j=0 --- (101)&(2^0) --- (101)&(001) --- (001) --- 1 ---    Include nums[0] = 1
      ↗
i=5 ↗→ → →  j=1 --- (101)&(2^1) --- (101)&(010) --- (000) --- 0  ---  Skip nums[1] = 2
      ↘
        ↘   j=2 --- (101)&(2^2) --- (101)&(100) --- (100) --- 4  ---  Include nums[2] = 3
                            |
                            4
                            
temp = [1, 3]
ans = [[], [1], [2], [1, 2], [3], [1, 3]]











Iteration 7:i=6
Binary representation:110
formula:(i&(1<<j))

                            1
                            |
        ↗   j=0 --- (110)&(2^0) --- (110)&(001) --- (000) --- 0 ---     Skip nums[0] = 1
      ↗
i=6 ↗→ → →  j=1 --- (110)&(2^1) --- (110)&(010) --- (010) --- 2  --- Include nums[1] = 2
      ↘
        ↘   j=2 --- (110)&(2^2) --- (110)&(100) --- (100) --- 4  ---   Include nums[2] = 3
                            |
                            4
                            
temp = [2, 3]
ans = [[], [1], [2], [1, 2], [3], [1, 3], [2, 3]]











Iteration 8:i=7
Binary representation:111
formula:(i&(1<<j))

                            1
                            |
        ↗   j=0 --- (111)&(2^0) --- (111)&(001) --- (001) --- 1 ---   Include nums[0] = 1
      ↗
i=7 ↗→ → →  j=1 --- (111)&(2^1) --- (111)&(010) --- (010) --- 2  ---  Include nums[1] = 2
      ↘
        ↘   j=2 --- (111)&(2^2) --- (111)&(100) --- (100) --- 4  ---   Include nums[2] = 3
                            |
                            4
               
                            
All bits are 1, so all elements are included.                            
temp = [1, 2, 3]
ans = [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]






5. Final output
Your code prints:
[ ]
[ 1 ]
[ 2 ]
[ 1 2 ]
[ 3 ]
[ 1 3 ]
[ 2 3 ]
[ 1 2 3 ]



6. Remember these three things

i decides which subset to create.
j checks each element of the array.
temp stores the elements whose corresponding bits are 1.


*/






















//extra->using recursion.
/*
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;  // Store all subsets
        int n = nums.size();

        // Generate all possible subsets
        for (int i = 0; i < (1 << n); i++) {

            vector<int> temp;  // Store one subset

            // Check every element
            for (int j = 0; j < n; j++) {

                // Check whether bit j is set
                if (i & (1 << j)) {
                    temp.push_back(nums[j]);
                }
            }

            // Store the completed subset
            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {
    int n;

    // Take input
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n < 0 || n > 20) {
        cout << "Please enter a size between 0 and 20.";
        return 0;
    }

    vector<int> nums(n);

    cout << "Enter " << n << " unique elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Create object
    Solution obj;

    // Generate all subsets
    vector<vector<int>> ans = obj.subsets(nums);

    // Print result
    cout << "\nAll possible subsets:\n";

    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";

        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}
*/