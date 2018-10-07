#include <iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int n,k,l,r;
    cout<<"enter the value of rows:\n";
    cin>>n;
    r=(n+1)/2+1;
    l=-2;

   for(int i=1;i<=n;i++)
   {
       if(i<=(n+1)/2) {     //l for spaces and r for number of stars,initialy space=0 and star=(n+1)/2
            l=l+2;
            r=r-1; }
         else {
            l=l-2;
            r=r+1; }
       for(int j=1;j<=r;j++){
        cout<<"* ";
       }
       for(int j=1;j<=l;j++){
        cout<<"  ";
       }
       for(int j=1;j<=r;j++){
        cout<<"* ";
       }
       cout<<"\n";
   }
}
