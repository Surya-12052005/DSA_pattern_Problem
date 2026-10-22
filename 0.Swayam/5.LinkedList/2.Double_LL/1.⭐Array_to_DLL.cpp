//convert array to doubly linked list.
#include <iostream>
#include <vector>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// Convert array to Doubly Linked List
Node* convertArr2DLL(vector<int>& arr) {
    if (arr.size() == 0) {
        return NULL;
    }

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]); 

        temp->prev = prev;
        prev->next = temp;

        prev = temp;
    }

    return head;
}

// Print DLL
void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Enter array size: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid array size!";
        return 0;
    }

    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = convertArr2DLL(arr);

    cout << "Doubly Linked List: ";
    print(head);

    return 0;
}
