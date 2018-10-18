
#include<iostream>
using namespace std;

long long int calculate_gcd(long long int a,long long int b)
{
  if(b==0)
    return a;
  else
    return calculate_gcd(b,a%b);
}


int main()
{
    long long int n1,n2;
    cout<<"Enter the two numbers:";
    cin>>n1>>n2;

    cout<<calculate_gcd(n1,n2)<<endl;
    return 0;
}

    
