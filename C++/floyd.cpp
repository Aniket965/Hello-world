#include <iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int n,k,l=-1,r;
    cout<<"enter the value of rows:\n";
    cin>>n;

   cout<<"floyd triangle is:\n";
   for(int i=1;i<=n;i++)
   {
       for(int k =1;k<=i;k++)
       {
           cout<<k<<" ";
       }
       cout<<"\n";

   }
}
