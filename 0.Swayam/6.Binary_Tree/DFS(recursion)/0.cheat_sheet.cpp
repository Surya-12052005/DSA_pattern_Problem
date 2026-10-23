#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

//1.Preorder Traversal
void Preorder(Node* root){
    if(root==NULL) return;
    
    cout<<root->data;
    Preorder(root->left);
    Preorder(root->right);
}

//2.inorder Traversal
void inorder(Node* root){
    if(root==NULL) return;
    
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

//3.Postorder Traversal
void Postorder(Node* root){
    if(root==NULL) return;
    
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data;
}

//4.countNodes
int countNodes(Node* root){
    if(root==NULL) return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}

//5.COUNT NODES HAVING ONLY RIGHT CHILD
int countRight(Node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right!=NULL)
    return 1+countRight(root->left)+countRight(root->right);
    
    return countRight(root->left)+countRight(root->right);
}

//6.HEIGHT OF A BINARY TREE
int maxHeight(Node* root){
    if(root==NULL) return 0;
    
    return 1 + max(maxHeight(root->left),maxHeight(root->right));
}

//7. SEARCH A VALUE IN A BINARY TREE
bool Search(Node* root, int val) {
    if (root == NULL)
        return false;

    if (root->data == val)
        return true;

    if (Search(root->left, val))
        return true;

    return Search(root->right, val);
}


//8.FIND LEVEL OF A VALUE
int level(Node* root, int val) {
    if (root == NULL)
        return 0;

    if (root->data == val)
        return 1;

    int left = level(root->left, val);
    if (left != 0)
        return left + 1;

    int right = level(root->right, val);
    if (right != 0)
        return right + 1;

    return 0;
}

//9.CREATE THE MIRROR IMAGE OF A BINARY TREE
void mirrorimage(Node* root) {
    if (root == NULL)
        return;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorimage(root->left);
    mirrorimage(root->right);
}

//10.CHECK WHETHER TWO BINARY TREES ARE MIRROR IMAGES
bool isMirror(Node* p, Node* q) {
    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    if (p->data != q->data)
        return false;

    return isMirror(p->left, q->right) &&
           isMirror(p->right, q->left);
}

//11.Print All Root-to-Leaf Paths
void printPaths(Node* root, vector<int>& path) {
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

//12.Print All Ancestors of a Given Node
bool printAncestors(Node* root, int target) {

    if (root == NULL)
        return false;

    if (root->data == target)
        return true;

    if (printAncestors(root->left, target) ||
        printAncestors(root->right, target)) {

        cout << root->data << " ";
        return true;
    }

    return false;
}

//13.Convert Binary Tree into Doubly Linked List
void convertToDLL(Node* root, Node*& head, Node*& prev)
{
    // Base case
    if (root == nullptr)
        return;

    // Step 1: Convert left subtree
    convertToDLL(root->left, head, prev);

    // Step 2: Process current node

    // If this is the first node,
    // it becomes the head of DLL
    if (prev == nullptr)
    {
        head = root;
    }
    else
    {
        // Connect previous node with current node

        // Previous node's next = current node
        prev->right = root;

        // Current node's previous = previous node
        root->left = prev;
    }

    // Current node becomes previous node
    prev = root;

    // Step 3: Convert right subtree
    convertToDLL(root->right, head, prev);
}

// Function to print DLL from left to right
void printDLL(Node* head)
{
    Node* current = head;

    while (current != nullptr)
    {
        cout << current->data;

        if (current->right != nullptr)
            cout << " <-> ";

        current = current->right;
    }

    cout << endl;
}


//14.Same Tree (LeetCode 100)

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

//15.Balanced Binary Tree
int height(Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right); 

    if (leftHeight == -1 || rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)   // Current node is unbalanced
        return -1;

    return 1 + max(leftHeight, rightHeight);  // Return height of current subtree
}

bool isBalanced(Node* root) {
    return height(root) != -1;  //This line means: If the height function does not return -1, the tree is balanced.
}


//16. Subtree of Another Tree (LeetCode 572)

bool isSame(Node* p, Node* q) {

    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    if (p->data != q->data)
        return false;

    return isSame(p->left, q->left) &&
           isSame(p->right, q->right);
}

bool isSubtree(Node* p, Node* q) {

    if (q == NULL)
        return true;

    if (p == NULL)
        return false;

    if (isSame(p, q))
        return true;

    return isSubtree(p->left, q) ||
           isSubtree(p->right, q);
}

//17.Invert Binary Tree

Node* invertTree(Node* root) {
    if (root == NULL)
        return NULL;

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

void levelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;     
    q.push(root);

    while (q.size() > 0) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}



int main() {
	// your code goes here

	
	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->right=new Node(6);
	

    // Tree 1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    // Tree 2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    if(isSubtree(root1, root2))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
