#include<bits/stdc++.h>

using namespace std;

int main ()
{
  int N , T , Ans=0 ;
  //cout<<"Enter the number of lines";
  cin >> T;
  for (int i = 0; i < T; i++)
    {
    //cout<<"Enter a number";
      cin >> N;
      Ans= sqrt(N);
      cout<<Ans<<endl;
    }
  return 0;
}
