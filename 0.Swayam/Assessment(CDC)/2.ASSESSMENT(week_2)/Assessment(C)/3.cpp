
//Problem Name: Smallest Numbers of Notes
#include <bits/stdc++.h>
using namespace std;

int minnotes(int N) {
    int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0;

    A = N / 100;
    N = N % 100;

    B = N / 50;
    N = N % 50;

    C = N / 10;
    N = N % 10;

    D = N / 5;
    N = N % 5;

    E = N / 2;
    N = N % 2;

    F = N;

    return A + B + C + D + E + F;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        cout << minnotes(N) << endl;
    }

    return 0;
}
