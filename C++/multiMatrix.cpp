#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	int a[4][4]={{1,2,3,4},
				{9,45,75,94},
				{25,107,55,71},
				{66,20,10,3}};
	int b[4][2]={{1,15},
				{5,8},
				{8,25},
				{55,11}};
	int c[4][2]={{}};

	for(int i=0;i<4;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<4;k++)
				c[i][j]+=a[i][k]*b[k][j];

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<2;j++)
			cout<<c[i][j]<<" ";//printf("%6d",c[i][j]);
		cout<<endl;
	}

	_getch();
	return 0;
}