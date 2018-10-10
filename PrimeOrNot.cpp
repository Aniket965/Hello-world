#include<iostream>

using  std:: cin;
using  std:: cout;

int main(void)
{
  int n,counter=0;
  cout<<"Enter the Number : ";
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    if(n%i==0)
    {
      counter++;
	}
  }
  cout<<(counter==2?"Number is prime":"Number is not Prime");
  return 0;
}
