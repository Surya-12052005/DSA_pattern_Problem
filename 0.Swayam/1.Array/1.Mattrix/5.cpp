/*You are stacking glasses in a triangular pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on — each row i has i + 1 glasses. Each glass has a capacity of 1 unit.
Champagne is poured into the top glass. Once a glass overflows, the excess is split equally and poured into the two glasses immediately below it (diagonally left and right). Given the total amount poured, print how much champagne ends up in every glass of the pyramid.*/

#include <bits/stdc++.h>
using namespace std;

const int MAXROWS = 20; // enough rows for the cascade to settle

// poured = total amount poured into the top glass
// cap    = capacity of each glass (1L in the classic problem)
void printFlat(double poured, double cap) {
    vector<vector<double>> a(MAXROWS + 1, vector<double>(MAXROWS + 1, 0.0));

    a[0][0] = poured;
    int n = 0;
    bool overflow = a[0][0] > cap;

    while (overflow && n < MAXROWS - 1) {
        overflow = false;
        for (int c = 0; c <= n; c++) {
            if (a[n][c] > cap) {
                overflow = true;
                double temp = a[n][c] - cap;   // excess amount
                a[n][c] = cap;                 // cap this glass
                a[n + 1][c]     += temp / 2.0; // pour left-below
                a[n + 1][c + 1] += temp / 2.0; // pour right-below
            }
        }
        n++;
    }

    cout << "Final tower (poured = " << poured << ", capacity = " << cap << "):\n";
    for (int r = 0; r <= n; r++) {
        for (int c = 0; c <= r; c++) {
            cout << fixed << setprecision(3) << a[r][c] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    printFlat(3, 1);    // 3 units poured, 1L capacity per glass
    cout << "\n";
    printFlat(4, 1);    // try a bigger pour
    return 0;
}