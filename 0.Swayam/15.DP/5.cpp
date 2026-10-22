/*
3.cpp — Print All Paths in m × m Matrix

Your 3.cpp is basically correct. The main thing is to make the question and indexing clear.

Question

Given an m × m matrix, print all possible paths from cell (0,0) to cell (m-1,m-1).
The person can move only Right (R) or Down (D).  

Diagram for 3 × 3

                 j
              0     1     2
           ┌─────┬─────┬─────┐
        0  │  S  │     │     │
           ├─────┼─────┼─────┤
        1  │     │     │     │
           ├─────┼─────┼─────┤
        2  │     │     │  E  │
           └─────┴─────┴─────┘
          i

S = (0,0)
E = (m-1,m-1)  

*/

#include <iostream>
#include <string>
using namespace std;

void printPaths(int i, int j, int m, string path)
{
    // Reached last cell
    if (i == m - 1 && j == m - 1)
    {
        cout << path << endl;   // initially path= "" : (empty) 
        return;                 
    }

    // Move Right      
    if (j < m - 1)
    {
        printPaths(i, j + 1, m, path + "R");   // initially path= "" 
    }                                         //path + "R"= "" + "R"= "R"

    // Move Down
    if (i < m - 1)
    {
        printPaths(i + 1, j, m, path + "D");
    }
}

int main()
{
    int m;

    cout << "Enter matrix size: ";  
    cin >> m;

    printPaths(0, 0, m, "");   // experiment:use -> in place of ""  ( ie: "" --> "->")

    return 0;
}




/*given  m*m mattrix , print all the path from cell[0][0] to cell[m][m]


#include <iostream>
using namespace std;

void printPaths(int i, int j, int m, string path)
{
    // Reached last cell
    if (i == m - 1 && j == m - 1)
    {
        cout << path << endl;
        return;
    }

    // Move right
    if (j < m - 1)
        printPaths(i, j + 1, m, path + "R");

    // Move down
    if (i < m - 1)
        printPaths(i + 1, j, m, path + "D");
}

int main()
{
    int m;

    cout << "Enter matrix size: ";
    cin >> m;

    printPaths(0, 0, m, "");

    return 0;
}
*/

