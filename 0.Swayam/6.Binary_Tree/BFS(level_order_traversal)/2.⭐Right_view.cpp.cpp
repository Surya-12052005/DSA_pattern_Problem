/*
LeetCode 199: Binary Tree Right Side View (Medium)

Question: Given the root of a binary tree, return the values of the nodes visible when viewed from the right side, from top to bottom.

Example:
Input:  root = [1,2,3,null,5,null,4]
Output: [1,3,4]


Approach: Use BFS (Level Order Traversal) with a queue and store the last node of each level.*/



/*LeetCode 199 — Approach in Easy Words
Approach used: BFS (Breadth-First Search) — Level Order Traversal

We use a Queue to visit the binary tree level by level and select the last node of each level.
Steps of the approach
1. Create an empty vector ans to store the result.
2. Insert the root node into the queue.
3. Find the number of nodes at the current level using size = q.size().
4. Process all nodes at that level.
5. Add the last node of the level to ans using if (i == size - 1).
6. Insert the left and right children into the queue.
7. Repeat until the queue becomes empty.
8. Return ans */

/*
        1
       / \
      2   3
       \   \
        5   4
        
        
        
Right side view: 1 → 3 → 4*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;                              // ans = []

    if (root == NULL) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);                                 // q = [1]
///itterate over the levels.
    while (!q.empty()) {
        int size = q.size();                      // size = 1  (one node on level 0)
//itterate over the queue.
        for (int i = 0; i < size; i++) {         //i = 0
            TreeNode* node = q.front();          // node = q.front() gives node 1, 
            q.pop();                             // q.pop() leaves q = []

            // Store the last node of each level
            if (i == size - 1) {               //i == size - 1? 0 == 0, yes, so result = [1]
                ans.push_back(node->val);
            }

            if (node->left != NULL) {
                q.push(node->left);         //node 1 has a left child, so push 2: q = [2]       
            }

            if (node->right != NULL) {
                q.push(node->right);       //node 1 has a right child, so push 3: q = [2, 3]
            }
        }
    }

    return ans;
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> ans = rightSideView(root);

    cout << "Right Side View: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}



/*

// ===== Dry run: LeetCode 199, Right Side View (BFS, queue = FIFO) =====
//
// Tree:
//          1 ------ level 1
//         / \
//        2   3 ---- level 2
//       / \   \
//      4   5   6 -- level 3
//     /   /
//    7   8 -------- level 4
//

    vector<int> ans;

    while (!q.empty()) {
        int size = q.size();                     

        for (int i = 0; i < size; i++) {        
            TreeNode* node = q.front();          
            q.pop();                            

            // Store the last node of each level
            if (i == size - 1) {              
                ans.push_back(node->val);
            }

            if (node->left != NULL) {
                q.push(node->left);             
            }

            if (node->right != NULL) {
                q.push(node->right);     
            }
        }


// ans = []
// q = [1]
// | q at level start   | [1]            | [2,3]          |                | [4,5,6]        |                |                | [7,8]          |                |
// | size               | 1              | 2              |                | 3              |                |                | 2              |                |
// | level              | 1              | 2              | 2              | 3              | 3              | 3              | 4              | 4              |
// | Step               | L1,i=0         | L2,i=0         | L2,i=1         | L3,i=0         | L3,i=1         | L3,i=2         | L4,i=0         | L4,i=1         |
// |--------------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|----------------|
// | i                  | 0              | 0              | 1              | 0              | 1              | 2              | 0              | 1              |
// | Node               | 1              | 2              | 3              | 4              | 5              | 6              | 7              | 8              |
// | q after pop        | []             | [3]            | [4,5]          | [5,6]          | [6,7]          | [7,8]          | [8]            | []             |
// | i == size-1 ?      | 0==0 YES       | 0==1 NO        | 1==1 YES       | 0==2 NO        | 1==2 NO        | 2==2 YES       | 0==1 NO        | 1==1 YES       |
// | ans                | [1]            | no push_back   | [1,3]          | no push_back   | no push_back   | [1,3,6]        | no push_back   | [1,3,6,8]      |
// | left != NULL ?     | 2!=NULL        | 4!=NULL        | NULL           | 7!=NULL        | 8!=NULL        | NULL           | NULL           | NULL           |
// | q after left push  | [2]            | [3,4]          | no push_back   | [5,6,7]        | [6,7,8]        | no push_back   | no push_back   | no push_back   |
// | right != NULL ?    | 3!=NULL        | 5!=NULL        | 6!=NULL        | NULL           | NULL           | NULL           | NULL           | NULL           |
// | q after right push | [2,3]          | [3,4,5]        | [4,5,6]        | no push_back   | no push_back   | no push_back   | no push_back   | no push_back   |
//
// After L4,i=1 -> q = [] -> while loop ends
// Final answer: ans = [1, 3, 6, 8]

*/