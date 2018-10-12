#include<bits/stdc++.h>
using namespace std;

main () 
{
	long long a=0,b=1,c,n;
	cout<<"Enter total number of Fibonacci= ";cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		if(i==1)
			{
				c=1;
			}
		else 
			{
				c=a+b;
				a=b;
				b=c;
			}
		if(i!=n) cout<<c<<" ";
		else cout<<c<<endl;
	}
	

}
