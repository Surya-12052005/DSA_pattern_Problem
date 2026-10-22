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

//6.Recursive function to find HEIGHT OF A BINARY TREE
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

//8. Recursive function to FIND LEVEL OF A VALUE
int getLevel(Node* x, int val) {

    // Base case
    if (x == NULL)
        return 0;

    // If current node contains the value
    if (x->data == val)
        return 1;

    // Search in left subtree
    int leftLevel = getLevel(x->left, val);

    if (leftLevel != 0)
        return leftLevel + 1;

    // Search in right subtree
    int rightLevel = getLevel(x->right, val);

    if (rightLevel != 0)
        return rightLevel + 1;

    // Value not found
    return 0;
}

// 9.Recursive function to create mirror
void mirrorImage(Node*& x) {

    // Base case
    if (x == NULL)
        return;

    // Swap left and right children
    Node* temp = x->left;
    x->left = x->right;
    x->right = temp;

    // Mirror left subtree
    mirrorImage(x->left);

    // Mirror right subtree
    mirrorImage(x->right);
}

//10. Recursive function to check mirror
bool isMirror(Node* x, Node* y){

    // Both trees are empty
    if (x == NULL && y == NULL)
        return true;

    // One tree is empty, other is not
    if (x == NULL || y == NULL)
        return false;

    // Values must be same
    if (x->data != y->data)
        return false;

    // Cross comparison
    return isMirror(x->left, y->right)
        && isMirror(x->right, y->left);
    }


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    //1.Preorder traversal(rLR)
    cout << "Preorder Traversal: ";
    preorder(root);

    //2.Inorder traversal
    cout << "inorder Traversal: ";
    inorder(root);

    //3.postorder traversal
    cout << "postorder Traversal: ";
    postorder(root);

    // 4.Recursive function to count nodes
    cout << "Total number of nodes: " << countNodes(root) << endl;

    // 5.Recursive function to COUNT NODES HAVING ONLY RIGHT CHILD
    cout << "Nodes having only right child: " << countRightChild(root) << endl;

    //6.Recursive function to find HEIGHT OF A BINARY TREE
    cout << "Hight of Binary Tree: "<< getHeight(root)<<endl;
    
    //7. Recursive function to SEARCH A VALUE IN A BINARY TREE
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



    //8. Recursive function to FIND LEVEL OF A VALUE
    // Value to search
    int val;

    cout << "Enter value: ";
    cin >> val;

    // Find level
    int result = getLevel(root, val);

    // Display result
    if (result != 0)
        cout << "Level of " << val << " is: " << result << endl;
    else
        cout << "Value " << val << " is not present in the Binary Tree." << endl;



    // 9.Recursive function to create mirror
    // Original tree
    cout << "Original Preorder: ";
    preorder(root);

    // Create mirror
    mirrorImage(root);

    // Mirror tree
    cout << "\nMirror Preorder: ";
    preorder(root);


 
    return 0;
}
