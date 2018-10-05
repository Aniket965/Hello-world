#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,N;
    cin >> n;
    int ascending[n];
    for(int i = 0; i < n; i++){
    cin >> ascending[i];
    }
    N = sizeof(ascending)/sizeof(ascending[0]);
    sort(ascending, ascending + N);
    for(int j = 0; j < N; j++){
    cout << ascending[j] << endl;
    }

    return 0;
}
