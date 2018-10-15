#include<bits/stdc++.h>
using namespace std;

#define ll long long int


int main() {
  ll t, n;
  ll temp, x, m = 0;
  ll a[200];
  cin>>t;

  while(t--) {
    cin>>n;
    a[0] = 1; // Storing 1!
    m = 1;
    for(int i = 2; i <= n; i++) {
      temp = 0;
      for(int j = 0; j < m; j++) {
        x = a[j] * i + temp;
        a[j] = x % 10;
        temp = x / 10;
      }
      while(temp > 0) {
        a[m++] = temp % 10;
        temp = temp / 10;
      }
    }
    for(int i = m - 1; i >= 0; i--) {
      cout<<a[i];
    }
    cout<<endl;
  }
  return 0;
}
