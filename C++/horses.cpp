// Problem https://www.codechef.com/problems/HORSES


#include <bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin >> t;
   while(t--){
       int n;
       cin >> n;
       
       vector<int>v;
       
       for(int i=0;i<n;i++){
           int x;cin >> x;
           v.push_back(x);
       }
       
       sort(v.begin(),v.end());
       
       int ans = INT_MAX;
       for(int i=1;i<n;i++){
           ans = min(ans,v[i]-v[i-1]);
       }
       
       cout << (ans) << endl;
   }
   return 0;
}
