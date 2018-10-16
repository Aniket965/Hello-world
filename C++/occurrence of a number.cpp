#include <iostream>
using namespace std;

int  linearsearch(int a[],int x )
{  int count =0;
   for (int i=0 ;i<21;i++)
   {
       if (a[i]==x)
    {count ++;}

   }
   return count ;
}
int main()
{   int x;
    int a[50]={1,2,3,3,4,5,5,5,5,5,6,6,6,7,7,9,9,9,9,9,9};
    cout<<"enter the element you want to check "<<endl;
    cin>>x;
   int y =linearsearch(a,x);
   cout<<y<<endl;
}
