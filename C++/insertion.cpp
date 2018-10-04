#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int n,i,k,ele,a[20],pos;
	cout<<"Enter no. of elements\n";
	cin>>n;
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
	    cin>>a[i];
	cout<<"Enter the element to be inserted\n";
	cin>>ele;
	if(ele<a[0])
	    pos=0;
	else if(ele>a[n-1])
	    pos=n;
	else
	    for(i=0;i<n;i++)
		    if((ele>a[i])&&(ele<a[i]))
			pos=i+1;
	for(i=n;i>pos;)
	{
		a[i]=a[i-1];
		a[i]=ele;
		break;
	}n++;
	cout<<"New array is:\n";
	for(k=0;k<n;k++)
	    cout<<a[k]<<endl;
	getch();
}
