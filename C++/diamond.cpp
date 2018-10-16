#include <iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int n,k,l=-1,r;
    cout<<"enter the value of rows:\n";
    cin>>n;

   cout<<"diamond is:\n";
   for(int i=1;i<=n;i++)
   {

       for(int space=1;space<=abs((n+1)/2-i);space++){
        cout <<"  ";
       }
       if(i<=(n+1)/2)
            l=l+2;
         else              // i<=(n+1)/2 ? l=l+2:l=l-2
            l=l-2;
       for(int j=1;j<=l;j++) {

         cout<<"* ";
       }
       cout<<"\n";
   }

   
}
