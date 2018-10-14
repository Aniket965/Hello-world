#include<iostream.h>
#include<stdio.h>
#include<conio.h>
void main()
{
	clrscr();
	int a[20],n,i,ele,b;
	cout<<"Enter the number of elements\n";
	cin>>n;
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
	cin>>a[i];
	cout<<"Enter the element to be deleted\n";
	cin>>ele;
	for(i=0;i<n;i++)
	{
		{
			if(ele==a[i])
			b=i;
			break;
		}
	}
	for(i=b;i<n;i++)
	{
		a[i]=a[i+1];
	}
	n--;
	for(i=0;i<n;i++)
	cout<<a[i]<<endl;
	getch();
}
