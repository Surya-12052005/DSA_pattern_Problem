/*Q8. Given a Binary Tree in Array Form, Convert it into Preorder
Question

Given a binary tree represented using an array, print its Preorder Traversal.

For a 0-based array:

          1
        /   \
       2     3
      / \   / \
     4   5 6   7

Array:

[1, 2, 3, 4, 5, 6, 7]
Preorder

Preorder follows:

Root → Left → Right

Therefore:

1 2 4 5 3 6 7*/

#include <iostream>
using namespace std;

void preOrder(int arr[], int n, int r) {

    // Index is outside the array
    if (r >= n) {
        return;
    }

    // Root
    cout << arr[r] << " ";

    // Left subtree
    preOrder(arr, n, 2 * r + 1);

    // Right subtree
    preOrder(arr, n, 2 * r + 2);
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Preorder Traversal: ";

    preOrder(arr, n, 0);

    return 0;
}