
#include<bits/stdc++.h>

using namespace std;

int
main ()
{
  int N, T, R = 0;
  //cout<<"Enter the number of lines";
  cin >> T;
  for (int i = 0; i < T; i++)
    {
      cin >> N;
      while (N > 0)
	{
	  R = R * 10;
	  R = R + (N % 10);
	  N = N / 10;
	}
      cout << R<<endl;
      R=0;
    }
  return 0;
}
