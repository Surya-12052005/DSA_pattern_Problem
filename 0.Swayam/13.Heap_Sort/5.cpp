/*Q9. Serialization and Deserialization of Binary Tree
Question

Explain Serialization and Deserialization of a Binary Tree and implement them in C++.

Serialization

Serialization means converting a binary tree into a string/array so that it can be stored or transmitted.

Example:

          1
        /   \
       2     3
      / \
     4   5

Can be serialized as:

1,2,4,#,#,5,#,#,3,#,#

Here:

# = NULL
Deserialization

Deserialization is the reverse process.

String
   ↓
Binary Tree*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Serialization
void serialize(Node* root, stringstream& ss) {

    if (root == NULL) {
        ss << "# ";
        return;
    }

    ss << root->data << " ";

    serialize(root->left, ss);
    serialize(root->right, ss);
}

// Deserialization
Node* deserialize(stringstream& ss) {

    string value;
    ss >> value;

    if (value == "#") {
        return NULL;
    }

    Node* root = new Node(stoi(value));

    root->left = deserialize(ss);
    root->right = deserialize(ss);

    return root;
}

// Preorder to check the result
void preOrder(Node* root) {

    if (root == NULL) {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

int main() {

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Serialize
    stringstream ss;

    serialize(root, ss);

    cout << "Serialized Tree: ";
    cout << ss.str() << endl;

    // Deserialize
    Node* newRoot = deserialize(ss);

    cout << "Preorder after Deserialization: ";
    preOrder(newRoot);

    return 0;
}