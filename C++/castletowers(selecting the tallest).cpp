#include <bits/stdc++.h>
using namespace std;
int castleTowers(int n, vector <int> ar) {
    sort(ar.rbegin(), ar.rend());
    int maxi = ar[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (maxi == ar[i]) {
            cnt += 1;
        } else {
            break;
        }
    }
    return cnt;
}
int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
    	cin >> ar[ar_i];
    }
    int result = castleTowers(n, ar);
    cout << result << endl;
    return 0;
}