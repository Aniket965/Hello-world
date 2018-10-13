#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int i,j,k,l;
	for(i=1;i<=11;i=i+2)
	{
		for(int tab=9;tab>=i;tab=tab-2)
		{
			cout<<" ";
		}
		for(j=1;j<=i;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	
	for(i=9;i>=1;i=i-2)
	{
		for(int tab=9;tab>=i;tab=tab-2)
		{
			cout<<" ";
		}
		for(j=1;j<=i;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	getch();
}
