#include<bits/stdc++.h>
using namespace std;
int main()
{
  vector<int>v(100);
  int n;
  cin>>n;
  for(int i=0;i<n;++i)
    cin>>v[i];
  sort(v.begin(),v.end());
  return 0;
}
