#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	int b, h, A, a, c, d, e, f, s;
	cout<<"calculating an area of a triangle"<<endl;
	cout<<"What is the type of triangle"<<endl;
	cout<<"1. Equilateral\n";
	cout<<"2. Any Other\n";
	cout<<"Your Choice: ";
	cin>>a;
	if(a==1)
		{
			cout<<"enter the base value: ";
			cin>>b;
			cout<<endl;
			cout<<"enter the height value: ";
			cin>>h;
			cout<<endl;
			A = b*h/2;
			cout<<"Area is equivalent to:"<<A;
	}
	else
		{
			cout<<"Length of 1st side: ";
			cin>>c;
			cout<<"/nLength of 2nd side: ";
			cin>>d;
			cout<<"/nLength of 3rd side: ";
			cin>>e;
			cout<<endl;
			f=(c+d+e)/2;
			s=sqrt(f*(f-c)*(f-d)*(f-e));
			cout<<"Area is equivalent to:"<<f;

		}
}
