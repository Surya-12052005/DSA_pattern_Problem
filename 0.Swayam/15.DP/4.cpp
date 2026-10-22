/*
2.cpp — Print All Paths
Question

Given a 2 × 2 matrix, print all possible paths from (0,0) to (1,1).
A person can move only Right (R) and Down (D).

Diagram:


        j=0     j=1
      ┌───────┬───────┐
i=0   │ START │       │
      ├───────┼───────┤
i=1   │       │  END  │
      └───────┴───────┘

Possible paths:

START → RIGHT → END
        R       D

START → DOWN → END
        D      R

Therefore:

RD
DR
        */


#include <iostream>
#include <string>
using namespace std;

void printPaths(int i, int j, int m, int n, string path)     
{
    // Reached last cell
    if (i == m - 1 && j == n - 1)
    {
        cout << path << endl;           
        return;
    }

    // Move Right
    if (j < n - 1)                                   
    {
        printPaths(i, j + 1, m, n, path + "R");
    }

    // Move Down
    if (i < m - 1)
    {
        printPaths(i + 1, j, m, n, path + "D");
    }
}

int main()
{
    int m, n;

    cout << "Enter rows: ";
    cin >> m;

    cout << "Enter columns: ";
    cin >> n;

    printPaths(0, 0, m, n, "");                  

    return 0;
}        





/*given 2 *2 mattrix , print all the path from cell[0][0] to cell[1][1]

#include <iostream>
using namespace std;

void printPaths(int i, int j, string path)
{
    // Reached the last cell
    if (i == 1 && j == 1)
    {
        cout << path << endl;
        return;
    }

    // Move right
    if (j < 1)
        printPaths(i, j + 1, path + "R");

    // Move down
    if (i < 1)
        printPaths(i + 1, j, path + "D");
}

int main()
{
    printPaths(0, 0, "");

    return 0;
}

*/