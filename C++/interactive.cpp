#include <bits/stdc++.h>
using namespace std;
int main() {
    int64_t t,n,a,b;
    cin >> t;
    while(t--) {
        cin >> a >> b >> n;
        int i = 0;
        while(a <= b) {
            int64_t mid = (a+b)/2;
            cout << mid << "\n";
            fflush(stdout);
            string s;
            cin >> s;
            if(s == "CORRECT") {
                break;
            } else if(s == "TOO_SMALL") {
                a = mid+1;
            } else if(s == "TOO_BIG") {
                b = mid-1;
            } else {
                break;
            }
        }
    }
}
