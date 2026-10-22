/*Merge sort*/
#include <iostream>
using namespace std;

class MergeArray
{
public:

    void merge(int a[], int n, int b[], int m, int c[])
    {
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < n && j < m)  
        {
            if (a[i] < b[j])
            {
                c[k] = a[i];
                i++;
            }
            else
            {
                c[k] = b[j];
                j++;
            }

            k++;
        }

        while (i < n)
        {
            c[k] = a[i];
            i++;
            k++;
        }

        while (j < m)
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }
};

int main()
{
    int a[] = {1, 5, 8, 10};
    int b[] = {2, 3, 9, 12, 15};

    int n = 4;
    int m = 5;

    int c[n + m];

    MergeArray obj;

    obj.merge(a, n, b, m, c);

    cout << "Merged Array: ";

    for (int i = 0; i < n + m; i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}