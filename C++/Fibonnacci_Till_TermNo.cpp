// Fibonacci Series up to entered number of terms

#include<iostream>

using std:: cout;
using std:: cin;

int main(void)
{
  int n,a=0,b=1,c=0;
  cout<<"Enter the number of term you want in fabonnaci series : ";
  cin>>n;
  for(int i =0; i<n ; i++)
  {
  	cout<<a<<" , ";
    c = a+b;
	a=b;
	b=c; 
  }
  return 0;
}
