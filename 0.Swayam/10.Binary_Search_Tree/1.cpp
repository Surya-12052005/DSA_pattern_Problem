/*Q4. Binary Search Tree (BST)

The BST shown in your picture is:

          5
        /   \
       3     10
      / \    / \
     1   4  7   20
            \
             9
Question

Implement the basic operations of a Binary Search Tree:

Search
Insert
Delete*/

#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
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

// ---------------- SEARCH ----------------
Node* search(Node* root, int key)
{
    // Tree is empty
    if (root == NULL)
        return NULL;

    // Key found
    if (root->data == key)
        return root;

    // Search in left subtree
    if (key < root->data)
        return search(root->left, key);

    // Search in right subtree
    return search(root->right, key);
}

// ---------------- INSERT ----------------
Node* insert(Node* root, int key)
{
    // If tree is empty, create a new node
    if (root == NULL)
        return new Node(key);

    // Insert in left subtree
    if (key < root->data)
        root->left = insert(root->left, key);

    // Insert in right subtree
    else if (key > root->data)
        root->right = insert(root->right, key);

    return root;
}

// Find minimum value node
Node* findMin(Node* root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

// ---------------- DELETE ----------------
Node* deleteNode(Node* root, int key)
{
    // Key not found
    if (root == NULL)
        return NULL;

    // Search in left subtree
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);  
    }

    // Search in right subtree
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);  
    }

    // Node found
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        else
        {
            // Find inorder successor
            Node* temp = findMin(root->right);

            // Copy successor's value
            root->data = temp->data;

            // Delete successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// Inorder traversal
void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ---------------- MAIN ----------------
int main()
{
    // Creating the given BST
    Node* root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 20);
    root = insert(root, 9);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Search
    int key = 7;

    if (search(root, key) != NULL)
        cout << key << " found in BST." << endl;
    else
        cout << key << " not found in BST." << endl;

    // Insert
    root = insert(root, 8);

    cout << "After inserting 8: ";
    inorder(root);
    cout << endl;

    // Delete
    root = deleteNode(root, 7);

    cout << "After deleting 7: ";
    inorder(root);
    cout << endl;

    return 0;
}