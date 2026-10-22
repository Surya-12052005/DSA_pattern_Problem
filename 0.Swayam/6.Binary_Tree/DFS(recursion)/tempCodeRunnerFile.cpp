#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

//1.Preorder traversal(rLR)
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";  // Root
    preorder(root->left);       // Left
    preorder(root->right);      // Right
}

//2.Inorder traversal
void inorder(Node* x) {
    if (x == NULL)
        return;

    inorder(x->left);           // LEFT
    cout << x->data << " ";     // ROOT
    inorder(x->right);          // RIGHT
}

//3.postorder traversal
void postorder(Node* x) {
    if (x == NULL)
        return;

    postorder(x->left);         // LEFT
    postorder(x->right);        // RIGHT
    cout << x->data << " ";     // ROOT
}


// 4.Recursive function to count nodes
int countNodes(Node* x) {

    // Base case
    if (x == NULL)
        return 0;

    // Count left subtree
    int leftCount = countNodes(x->left);

    // Count right subtree
    int rightCount = countNodes(x->right);

    // Current node + left + right
    return 1 + leftCount + rightCount;
}

// 5.Recursive function to COUNT NODES HAVING ONLY RIGHT CHILD
int countRightChild(Node* x) {

    // Base case
    if (x == NULL)
        return 0;

    // Count left and right subtree
    int leftCount = countRightChild(x->left);
    int rightCount = countRightChild(x->right);

    // Check if current node has ONLY right child      
    if (x->left == NULL && x->right != NULL)
        return 1 + leftCount + rightCount;

    return leftCount + rightCount;
}

//Recursive function to find HEIGHT OF A BINARY TREE
int getHeight(Node* x) {
    if (x == NULL)
        return 0;

    int leftHeight = getHeight(x->left);
    int rightHeight = getHeight(x->right);

    return 1 + max(leftHeight, rightHeight);
}

//7. Recursive function to SEARCH A VALUE IN A BINARY TREE
bool search(Node* x, int val) {

    // Base case: tree is empty
    if (x == NULL)
        return false;

    // If current node contains the value
    if (x->data == val)
        return true;

    // Search in left subtree
    if (search(x->left, val))     
        return true;

    // Search in right subtree
    return search(x->right, val);   
}  

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << "inorder Traversal: ";
    inorder(root);

    cout << "postorder Traversal: ";
    postorder(root);

    cout << "Total number of nodes: " << countNodes(root) << endl;

    cout << "Nodes having only right child: " << countRightChild(root) << endl;


    //Value to search
    int val;

    cout << "Enter value to search: ";
    cin >> val;

     // Call search function
    bool result = search(root, val);

    // Display result
    if (result)
        cout << "Value " << val << " is present in the Binary Tree." << endl;
    else
        cout << "Value " << val << " is NOT present in the Binary Tree." << endl;


    cout << "Hight of Binary Tree: "<< getHeight(root) <<endl;
    

    return 0;
}
