/*jha max /min lement nikalne ki requirement ho wha hap ka use kro*/
/*Q. Merge K Sorted Arrays
Question

Given K sorted arrays A1, A2, A3, ..., Ak, merge all the arrays into a single sorted array.

Example

Given:

A1 = {1, 4, 7}
A2 = {2, 5, 8}
A3 = {3, 6, 9}

After merging:

1 2 3 4 5 6 7 8 9
Concept: Min Heap

We can solve this efficiently using a Min Heap.

The idea is:

Put the first element of every array into the Min Heap.
The smallest element will always be at the top.
Remove the smallest element and add it to the answer.
Then insert the next element from the same array into the heap.
Repeat until the heap becomes empty.
Why Min Heap?

Because we need the smallest element among all K arrays at every step.*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// This stores an element along with
// the array number and its index
class Node
{
public:
    int value;
    int arrayNo;
    int index;

    Node(int v, int a, int i)
    {
        value = v;
        arrayNo = a;
        index = i;
    }
};

// Compare function for Min Heap
class Compare
{
public:
    bool operator()(Node a, Node b)
    {
        return a.value > b.value;
    }
};

int main()
{
    // K sorted arrays
    vector<vector<int>> a =
    {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    int k = a.size();

    // Min Heap
    priority_queue<Node, vector<Node>, Compare> pq;

    // Put the first element of every array into Min Heap
    for (int i = 0; i < k; i++)
    {
        pq.push(Node(a[i][0], i, 0));
    }

    vector<int> ans;

    // Continue until heap becomes empty
    while (!pq.empty())
    {
        // Get the smallest element
        Node temp = pq.top();
        pq.pop();

        // Add it to answer
        ans.push_back(temp.value);

        // Get next element from the same array
        int nextIndex = temp.index + 1;

        if (nextIndex < a[temp.arrayNo].size())
        {
            pq.push(Node(
                a[temp.arrayNo][nextIndex],
                temp.arrayNo,
                nextIndex
            ));
        }
    }

    // Print final sorted array
    cout << "Merged Sorted Array: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}