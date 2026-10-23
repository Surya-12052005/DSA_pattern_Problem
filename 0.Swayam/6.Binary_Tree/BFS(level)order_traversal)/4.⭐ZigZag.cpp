/*
LeetCode 103 — Binary Tree Zigzag Level Order Traversal
Medium
BFS
Binary Tree

Question: Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
That means the first level is traversed left to right, the second level right to left, the third level left to right, and so on.*/

/*
2. Approach — BFS + Queue
We use BFS (Level Order Traversal) with a queue and a Boolean variable to control the direction.
1. If the root is NULL, return an empty answer.
2. Insert the root into the queue.
3. Process all nodes of one level at a time.
4. Store each level's values in a vector.
5. If the direction is right to left, reverse that level.
6. Insert the left and right children into the queue.
7. Change the direction for the next level.
*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> ans;                           //Stores the final zigzag traversal

    if (root == NULL)
        return ans;

    queue<Node*> q;                                  //Stores nodes waiting to be processed
    q.push(root);

    bool leftToRight = true;                        //Controls whether the current level needs reversing

    while (!q.empty()) {
        int n = q.size();                          //Number of nodes in the current level
        vector<int> level;                         //Stores values of the current level

        for (int i = 0; i < n; i++) {
            Node* temp = q.front();
            q.pop();

            level.push_back(temp->data);

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }

        if (leftToRight == false) {
            reverse(level.begin(), level.end());
        }

        ans.push_back(level);

        leftToRight = !leftToRight;
    }

    return ans;
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    vector<vector<int>> ans = zigzagLevelOrder(root);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



/*
=======================================================================
             LEETCODE 103: ZIGZAG LEVEL ORDER TRAVERSAL
=======================================================================

LEVEL 1                         LEVEL 2                         LEVEL 3
-----------------------------------------------------------------------

ans = []                        ans = [[3]]                     ans = [[3], [20, 9]]

q = [3]                         q = [9, 20]                     q = [15, 7]

leftToRight = true              leftToRight = false             leftToRight = true

SIZE = 1                        SIZE = 2                        SIZE = 2

LEVEL 1                         LEVEL 2                         LEVEL 3
-----------------------------------------------------------------------

q = [3]                         q = [9, 20]                     q = [15, 7]

temp = 3                        temp = 9                        temp = 15

q.pop()                         q.pop()                         q.pop()

remove 3                        remove 9                        remove 15

level = [3]                     level = [9]                     level = [15]

-----------------------------------------------------------------------

q = [9, 20]                     q = [20]                        q = [7]

                                temp = 20                       temp = 7

                                q.pop()                         q.pop()

                                remove 20                       remove 7

                                level = [9, 20]                 level = [15, 7]

-----------------------------------------------------------------------

leftToRight = true              leftToRight = false             leftToRight = true

Reverse: NO                     Reverse: YES                    Reverse: NO

level = [3]                     level = [20, 9]                 level = [15, 7]

-----------------------------------------------------------------------

ans = [[3]]                     ans = [[3], [20, 9]]            ans = [[3], [20, 9], [15, 7]]

leftToRight = false             leftToRight = true              leftToRight = false

=======================================================================
FINAL OUTPUT:

3
20 9
15 7

=======================================================================
*/
