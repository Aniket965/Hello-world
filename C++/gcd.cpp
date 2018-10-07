#include <iostream>
using namespace std;

int gcd(int a ,int b)
{ if(a==b)
return a;
if(a%b==0)
    return b;
if(b%a==0)
    return a ;
if(a>b)
    return gcd(a%b,b);
else
    return gcd(a,b%a);

}
int main()
{   int a,b;
    cout <<"enter the numbers"<<endl;
    cin>>a>>b;
    int z =gcd(a,b);
    cout<<"the gcd of given numbers is"<<z<<endl;
}
