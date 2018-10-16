#include<bits/stdc++.h>
using namespace std;
int myXor(int a, int b)
{
  return (a|b) & (~a|~b);
}
int main()
{
  //finding the xor of two numbers
  int a,b;
  cin>>a>>b;
  int result = myXor(a,b);
  cout<<result<<endl;
}
