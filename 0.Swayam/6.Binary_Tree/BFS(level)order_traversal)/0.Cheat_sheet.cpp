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

// 1. Level Order Traversal
void levelorder(Node* root) {
    if (root == NULL) return;

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

// 2. Binary Tree Right Side View
vector<int> rightside(Node* root) {
    vector<int> ans;

    if (root == NULL) return ans;

    queue<Node*> q;
    q.push(root);

    while (q.size() > 0) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            Node* temp = q.front();
            q.pop();

            if (i == n - 1)
                ans.push_back(temp->data);

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }

    return ans;
}

// 3. Binary Tree left Side View
vector<int> leftside(Node* root) {
    vector<int> ans;

    if (root == NULL) return ans;

    queue<Node*> q;
    q.push(root);

    while (q.size() > 0) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            Node* temp = q.front();
            q.pop();

            if (i == 0)
                ans.push_back(temp->data);

            if (temp->left != NULL)
                q.push(temp->left);

            if (temp->right != NULL)
                q.push(temp->right);
        }
    }

    return ans;
}

//4.Binary Tree Zigzag Level Order Traversal
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
	// your code goes here
	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(4);
	root->left->left=new Node(5);
	root->left->right=new Node(8);
	
	vector<int> ans=leftside(root);
	
	for(int j=0;j<ans.size();j++){
	    cout<<ans[j]<<" ";
	}
	
	return 0;

}
