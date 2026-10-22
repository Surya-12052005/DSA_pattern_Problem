/*Hash Table Using Chaining

For example:

Hash Table

0 → 20
1 → 31 → 41
2 → 12
3 → ...
4 → 14

If two keys generate the same hash index, we store them in the same bucket using a linked list.*/


/*Question

Implement a Hash Table using Separate Chaining.*/

#include <iostream>
#include <list>
using namespace std;

class HashTable
{
private:
    int N;
    list<int>* table;

public:
    HashTable(int size)
    {
        N = size;
        table = new list<int>[N];
    }

    int hashFunction(int key)
    {
        return key % N;
    }

    void insert(int key)
    {
        int index = hashFunction(key);

        table[index].push_back(key);
    }

    bool search(int key)
    {
        int index = hashFunction(key);

        for (int value : table[index])
        {
            if (value == key)
                return true;
        }

        return false;
    }

    void remove(int key)
    {
        int index = hashFunction(key);

        table[index].remove(key);
    }

    void display()
    {
        for (int i = 0; i < N; i++)
        {
            cout << i << " -> ";

            for (int value : table[i])
            {
                cout << value << " -> ";
            }

            cout << "NULL\n";
        }
    }
};

int main()
{
    HashTable h(5);

    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(25);
    h.insert(7);

    cout << "Hash Table:\n";
    h.display();

    int key = 20;

    if (h.search(key))
        cout << "\n" << key << " found";
    else
        cout << "\n" << key << " not found";

    h.remove(20);

    cout << "\n\nAfter deletion:\n";
    h.display();

    return 0;
}

