/*Question: Same Tree (LeetCode 100)
Given the roots of two binary trees p and q, check whether they are identical in structure and node values.

Approach: Use recursion. If both nodes are NULL, return true. If only one is NULL or their values differ, return false. Otherwise, compare both left and right subtrees.*/
/*
       Tree P                 Tree Q

         1                      1
        / \                    / \
       2   3                  2   4

          3 != 4
          Result: false                 */

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isSameTree(Node* p, Node* q) {

    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    if (p->data != q->data)
        return false;

    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}

int main() {
    Node* p = new Node(1);
    p->left = new Node(2);
    p->right = new Node(3);

    Node* q = new Node(1);
    q->left = new Node(2);
    q->right = new Node(3);

    if (isSameTree(p, q))
        cout << "Same Tree";
    else
        cout << "Not Same Tree";

    return 0;
}
