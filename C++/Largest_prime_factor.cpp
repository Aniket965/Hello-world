#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
 long int n,i;
cin>>t;
while(t--)
   { 
cin>>n;
    i=2;
   for(;i<=(int)sqrt(n);)
    {         
      if(n%i==0)
      {              
         n/=i;
         i=2;                                         
       }

       else
         ++i;           
    }

    cout<<n<<endl;
}
    return 0;
}
