// CPP Program to print Hosoya's
// triangle of height n.
#include <bits/stdc++.h>
using namespace std;

int Hosoya(int n, int m) { 
    // Base case
    if ((n == 0 && m == 0) ||
        (n == 1 && m == 0) ||
        (n == 1 && m == 1) ||
        (n == 2 && m == 1))
        return 1;

    // Recursive step
    if (n > m)
        return Hosoya(n - 1, m)
               + Hosoya(n - 2, m);

    else if (m == n)
        return Hosoya(n - 1, m - 1)
               + Hosoya(n - 2, m - 2);

    else
        return 0;
}

// Print the Hosoya triangle of height n.
void printHosoya(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cout << Hosoya(i, j) << " ";

        cout << endl;
    }
}

// Driven Program
int main() {
    int n = 5;
    printHosoya(n);
    return 0;
}
