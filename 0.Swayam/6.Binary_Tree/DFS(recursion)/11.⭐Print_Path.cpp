/*
Print All Root-to-Leaf Paths

Question:
Write a C++ program to print all root-to-leaf paths in a Binary Tree.  

             5
           /   \
          3     10
         / \    / \
        1   4  7   25
       /       \
      2         9

Output:
5 -> 3 -> 1 -> 2
5 -> 3 -> 4
5 -> 10 -> 7 -> 9
5 -> 10 -> 25
*/
/*
#include <iostream>
using namespace std;

// Node of Binary Tree
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

//  r     → Which node am I currently at?
//  Path  → What path have I collected so far?   , int Path[] means an integer array named Path. , it stor th lment in a particular path.
//  n     → How many nodes are currently in Path?

// Recursive function to print all root-to-leaf paths
void PrintAllPaths(Node* r, int Path[], int n)
{
    // Base case
    if (r == NULL)
        return;

    // Store current node in Path array
    Path[n] = r->data;
    n++;

    // If current node is a leaf node
    if (r->left == NULL && r->right == NULL)
    {
        for (int i = 0; i < n; i++)
        {
            cout << Path[i];

            if (i != n - 1)
                cout << " -> ";
        }

        cout << endl;
        return;
    }

    // Recursively visit left subtree
    PrintAllPaths(r->left, Path, n);

    // Recursively visit right subtree
    PrintAllPaths(r->right, Path, n);
}

int main()
{
    // Create the binary tree

    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(4);

    root->right->left = new Node(7);
    root->right->right = new Node(25);

    root->left->left->left = new Node(2);
    root->right->left->right = new Node(9);

    // Array to store current path
    int Path[100];

    cout << "Root-to-Leaf Paths:" << endl;

    // Call recursive function
    PrintAllPaths(root, Path, 0);

    return 0;
}

*/




#include <iostream>
#include <vector>
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

void printPaths(TreeNode* root, vector<int>& path) {
    if (root == NULL) {
        return;
    }

    // Add current node to path
    path.push_back(root->val);

    // If leaf node, print the path
    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    // Visit left subtree
    printPaths(root->left, path);

    // Visit right subtree
    printPaths(root->right, path);

    // Remove current node while backtracking
    path.pop_back();
}

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    vector<int> path;

    cout << "Root-to-Leaf Paths:" << endl;
    printPaths(root, path);

    return 0;
}
