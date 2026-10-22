/*Leetcode Problem:1423: Maximum Points You Can Obtain from Cards**

You are given an integer array `cardPoints` of size `n`. Each element represents the points on a card.
You must select exactly `k` cards. In each move, you can take one card either from the beginning or from the end of the array.
Return the maximum possible sum of the points obtained.

**Example 1**

Input:
7
1 2 3 4 5 6 1
3


Output:
12

Explanation: Select cards `1`, `6`, and `5` from the two ends. The maximum score is `1 + 6 + 5 = 12`.



**Example 2**

Input:
5
2 2 2 2 2
2

Output:
4

**Constraints**
- `1 <= n <= 100000`
- `1 <= k <= n`
- `1 <= cardPoints[i] <= 10000` */      



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int sum = 0;

    // Step 1: Take all k cards from the left
    for (int i = 0; i < k; i++) {
        sum += cardPoints[i];
    }

    int ans = sum;

    // Step 2: Replace left cards with right cards
    for (int i = 1; i <= k; i++) {
        sum = sum - cardPoints[k - i] + cardPoints[n - i];     //important learn
                    //cardPoints[2]       cardpoints[6]  
        ans = max(ans, sum);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> cardPoints(n);

    for (int i = 0; i < n; i++) {
        cin >> cardPoints[i];
    }

    int k;
    cin >> k;

    cout << maxScore(cardPoints, k) << endl;

    return 0;
}

/*
Concept: Sliding Window (Two-ended selection)
Idea: Start with k cards from the left, then replace them one by one with cards from the right.
sum = sum - cardPoints[k-i] + cardPoints[n-i];
ans = max(ans, sum);


Remember: Remove Left → Add Right → Update Maximum.
Loop: i = 1 to k
Complexity: Time O(k), Space O(1). */